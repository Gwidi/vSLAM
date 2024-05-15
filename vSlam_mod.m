%% kalibracja kamery 
% % kuba
principalPoint=[644.5,355.6];
focalLength=[983.4,989.3];

% gwidon 
% principalPoint=[651.7301,433.2670];
% focalLength=[951.6815,955.0682];

imageSize=[720,1280];
intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize);
%% definicja zmiennych 
% Connect to the webcam.
cam = webcam();  % Assumes the default webcam.

%Dlugosc czasu zanim funkcja sie wylaczy po uzyskaniu tracking lost.
duration=30;

% Rozpocznij pomiar czasu
startTime = tic; %od poczatku uruchomienia progrmau 
isLostTime = tic; %dlugosc czasu na statusie tracking lost

%poprzedni i obecny status obiektu vslam 
lastStatus = 0;
status = 0;

%sprawdzanie czy wyslano komunikat o uplywie czasu - status tracking lost
isLostTime10 = false;
isLostTime20 = false;
isLostTime30 = false;

% Konfig obiektu vslam 
figure(1); % For camera image
numPoints   = 2000;
numSkipFrames = 20;
scaleFactor = 1.2;
numLevels   = 14;
vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames);

%warunki sprawdzajace czy aby kontynuowac petle i czy tracking jest
%zgubiony 
isStop = false;
isLost = false;

%skipowanie pierwszych 30 klatek obrazu, aby unikac problemow z pierwsza
%klatka
for k = 1:30
    I = snapshot(cam); 
end

% workflow for vSlam
%% I. Map Initialization
isMapInitialized = false; % Czy mapa zostala zainicjalizowana
vSetKeyFrames = imageviewset; % Zbior zdjec i punktów
currFrameIdx = 0; % Identyfikator obecnego zdjecia
currFrameCheckIdx = 0; %Identyfikator blednej petli 
    % Workflow for map initialization
    %1. Detect Features
    %2. Extract Features
    %3. Match Features
    %4. Estimate Pose
    %5. Find 3-D locations of the matched feature points
    %6. Refine initial map	
    %7. Manage data for initial map and key frames
while ~isMapInitialized
    I = snapshot(cam);
    I = undistortImage(I, intrinsics);
    I = rgb2gray(I);
    %zabezpieczenie przed zbyt długa inicjalizacja 
    currFrameCheckIdx = currFrameCheckIdx + 1;
    if currFrameCheckIdx > 150
        vSetKeyFrames = deleteView(vSetKeyFrames, 1);
        currFrameIdx = 0;
        currFrameCheckIdx = 0;
    end
    %% 1. i 2. Detect Features and Extract Features
    if currFrameIdx == 0 % Pierwsze zdjecie, inicjalizacja, zapamietanie, wykrycie i ekstrakcja cech
        currFrameIdx = currFrameIdx + 1;
        imFirst = I;
        [firstFeatures, firstPoints] = helperDetectAndExtractFeatures(I, scaleFactor, numLevels, numPoints); 
        himage = imshow(I);
        continue
    end
    %% 3. Match Features
    % Kolejne zdjecia, szukanie cech, dopasowanie, estymacja pozycji, triangulacja
    [currFeatures, currPoints] = helperDetectAndExtractFeatures(I, scaleFactor, numLevels, numPoints); 
    indexPairs = matchFeatures(firstFeatures, currFeatures, Unique=true, MaxRatio=0.9, MatchThreshold=90);

     % If not enough matches are found, check the next frame 
     minMatches = 100;
     if size(indexPairs, 1) < minMatches
         continue
     end
     %% 4. Estimate relative camera pose from matched feature points
     firstMatchedPoints  = firstPoints(indexPairs(:,1),:); %cechy pierwszego zdjecia
     currMatchedPoints = currPoints(indexPairs(:,2),:); %cechy obecnego zdjecia

    % Wybranie modelu na podstawie heurystyki  
    % Compute homography and evaluate reconstruction
    [tformH, scoreH, inliersIdxH] = helperComputeHomography(firstMatchedPoints, currMatchedPoints);

    % Compute fundamental matrix and evaluate reconstruction
    [tformF, scoreF, inliersIdxF] = helperComputeFundamentalMatrix(firstMatchedPoints, currMatchedPoints); 

    %Select the model based on a heuristic
    ratio = scoreH/(scoreH + scoreF); 
    ratioThreshold = 0.45;
    if ratio > ratioThreshold
        disp('Homography');
        inlierTformIdx = inliersIdxH;
        tform          = tformH;
    else
         disp('Fundamental Matrix');
        inlierTformIdx = inliersIdxF;
        tform          = tformF;
    end

    % Computes the camera location up to scale. Use half of the 
    % points to reduce computation
    inlierFirstPoints  = firstMatchedPoints(inlierTformIdx);
    inlierCurrPoints = currMatchedPoints(inlierTformIdx);
    [relPose, validFraction] = estrelpose(tform, intrinsics, inlierFirstPoints(1:2:end), inlierCurrPoints(1:2:end));

    % If not enough inliers are found, move to the next frame
    if validFraction < 0.9 || numel(relPose)>1
        continue
    end
    %% 5. Find 3-D locations of the matched feature points
     % Triangulate two views to obtain 3-D map points
     minParallax = 1; % In degrees
     [isValid, xyzWorldPoints, inlierTriangulationIdx] = helperTriangulateTwoFrames(rigidtform3d, relPose, inlierFirstPoints, inlierCurrPoints, intrinsics, minParallax);
 
     if ~isValid
         continue
     end

     % Get the original index of features in the two key frames
    indexPairsMapInit = indexPairs;
    indexPairs = indexPairs(inlierTformIdx(inlierTriangulationIdx),:);
    currFrameIdx = currFrameIdx + 1;
    imSecond = I;
    secondFeatures = currFeatures;
    secondPoints = currPoints;
    addFrame(vslam,imFirst);
    addFrame(vslam, imSecond);
    isMapInitialized = true;

    disp('Map initialized')
end % End of map initialization loop

if isMapInitialized
    close(himage.Parent.Parent);% Close the previous figure
    % Show matched features
    hfeature = showMatchedFeatures(imFirst, imSecond, firstPoints(indexPairs(:,1)), secondPoints(indexPairs(:, 2)), "Montage");
    saveas(gcf, 'map_init.png');
    disp('Image of map initialized saved as "map_init.png"' )
else
    error('Unable to initialize the map.')
end
%% II. Tracking
    %Match extracted features
    %Estimate Pose
    %Project map points
    %Refine map points
    %Identify local map points
    %Search for more feature correspondences
    %Refine camera pose
    %Store new key frames

% Create an empty worldpointset object to store 3-D map points
mapPointSet   = worldpointset;

% Add the first key frame. Place the camera associated with the first 
% key frame at the origin, oriented along the Z-axis
vSetKeyFrames = addView(vSetKeyFrames, 1, rigidtform3d, Points=firstPoints,...
    Features=firstFeatures.Features);

% Add the second key frame
vSetKeyFrames = addView(vSetKeyFrames, 2, relPose, Points=secondPoints,...
    Features=secondFeatures.Features);

% Add connection between the first and the second key frame
vSetKeyFrames = addConnection(vSetKeyFrames, 1, 2, relPose, Matches=indexPairs);

% Add 3-D map points
[mapPointSet, newPointIdx] = addWorldPoints(mapPointSet, xyzWorldPoints);

% Add observations of the map points
preLocations  = firstPoints.Location;
currLocations = secondPoints.Location;
preScales     = firstPoints.Scale;
currScales    = secondPoints.Scale;

% Add image points corresponding to the map points in the first key frame
mapPointSet   = addCorrespondences(mapPointSet, 1, newPointIdx, indexPairs(:,1));

% Add image points corresponding to the map points in the second key frame
mapPointSet   = addCorrespondences(mapPointSet, 2, newPointIdx, indexPairs(:,2));

% Load the bag of features data created offline
bofData         = load("bagOfFeaturesDataSLAM.mat"); %naprawde nie wiem co to jest

% Initialize the place recognition database
loopDatabase    = invertedImageIndex(bofData.bof,SaveFeatureLocations=false);

% Add features of the first two key frames to the database
addImageFeatures(loopDatabase, firstFeatures, 1);
addImageFeatures(loopDatabase, secondFeatures, 2);

% Run full bundle adjustment on the first two key frames
tracks       = findTracks(vSetKeyFrames);
cameraPoses  = poses(vSetKeyFrames);

[refinedPoints, refinedAbsPoses] = bundleAdjustment(xyzWorldPoints, tracks, ...
    cameraPoses, intrinsics, FixedViewIDs=1, ...
    PointsUndistorted=true, AbsoluteTolerance=1e-7,...
    RelativeTolerance=1e-15, MaxIteration=20, ...
    Solver="preconditioned-conjugate-gradient");

% Scale the map and the camera pose using the median depth of map points
medianDepth   = median(vecnorm(refinedPoints.'));
refinedPoints = refinedPoints / medianDepth;

refinedAbsPoses.AbsolutePose(2).Translation = ...
    refinedAbsPoses.AbsolutePose(2).Translation / medianDepth;
relPose.Translation = relPose.Translation/medianDepth;

% Update key frames with the refined poses
vSetKeyFrames = updateView(vSetKeyFrames, refinedAbsPoses);
vSetKeyFrames = updateConnection(vSetKeyFrames, 1, 2, relPose);

% Update map points with the refined positions
mapPointSet = updateWorldPoints(mapPointSet, newPointIdx, refinedPoints);

% Update view direction and depth 
mapPointSet = updateLimitsAndDirection(mapPointSet, newPointIdx, vSetKeyFrames.Views);

% Update representative view
mapPointSet = updateRepresentativeView(mapPointSet, newPointIdx, vSetKeyFrames.Views);

% Visualize matched features in the current frame
close(hfeature.Parent.Parent);
featurePlot   = helperVisualizeMatchedFeatures(I, currPoints(indexPairs(:,2)));
% 
% Visualize initial map points and camera trajectory
mapPlot       = helperVisualizeMotionAndStructure(vSetKeyFrames, mapPointSet);

% Show legend
showLegend(mapPlot);

% ViewId of the current key frame
currKeyFrameId   = 2;

% ViewId of the last key frame
lastKeyFrameId   = 2;

% Index of the last key frame in the input image sequence
lastKeyFrameIdx  = currFrameIdx - 1; 

% Indices of all the key frames in the input image sequence
addedFramesIdx   = [1; lastKeyFrameIdx];

isLoopClosed     = false;


%% Main loop
isLastFrameKeyFrame = true;
disp('Main Loop Started');
while ~isLoopClosed
    I = snapshot(cam);
    I = undistortImage(I, intrinsics);
    I = rgb2gray(I);

    [currFeatures, currPoints] = helperDetectAndExtractFeatures(I, scaleFactor, numLevels, numPoints);

    % Track the last key frame
    % mapPointsIdx:   Indices of the map points observed in the current frame
    % featureIdx:     Indices of the corresponding feature points in the 
    %                 current frame
    [currPose, mapPointsIdx, featureIdx] = helperTrackLastKeyFrame(mapPointSet, ...
        vSetKeyFrames.Views, currFeatures, currPoints, lastKeyFrameId, intrinsics, scaleFactor);

    % Track the local map and check if the current frame is a key frame.
    % A frame is a key frame if both of the following conditions are satisfied:
    %
    % 1. At least 20 frames have passed since the last key frame or the
    %    current frame tracks fewer than 100 map points.
    % 2. The map points tracked by the current frame are fewer than 90% of
    %    points tracked by the reference key frame.
    %
    % Tracking performance is sensitive to the value of numPointsKeyFrame.  
    % If tracking is lost, try a larger value.
    %
    % localKeyFrameIds:   ViewId of the connected key frames of the current frame
    numSkipFrames     = 20;
    numPointsKeyFrame = 90;
    [localKeyFrameIds, currPose, mapPointsIdx, featureIdx, isKeyFrame] = ...
        helperTrackLocalMap(mapPointSet, vSetKeyFrames, mapPointsIdx, ...
        featureIdx, currPose, currFeatures, currPoints, intrinsics, scaleFactor, numLevels, ...
        isLastFrameKeyFrame, lastKeyFrameIdx, currFrameIdx, numSkipFrames, numPointsKeyFrame);


% function [localKeyFrameIds, currPose, mapPointIdx, featureIdx, isKeyFrame] = ...
%         helperTrackLocalMap(mapPoints, vSetKeyFrames, mapPointIdx, ...
%         featureIdx, currPose, currFeatures, currPoints, intrinsics, scaleFactor, numLevels, ...
%         newKeyFrameAdded, lastKeyFrameIndex, currFrameIndex, numSkipFrames, numPointsKeyFrame)

    % Visualize matched features
    updatePlot(featurePlot, I, currPoints(featureIdx));

    if ~isKeyFrame
        currFrameIdx        = currFrameIdx + 1;
        isLastFrameKeyFrame = false;
        continue
    else
        isLastFrameKeyFrame = true;
    end

    % Update current key frame ID
    currKeyFrameId  = currKeyFrameId + 1;
%% III. Local Mapping
    %Connect key frames
    %Search for matches in connected key frames	
    %Compute location for new matches	
    %Store new map points	
    %Store 3-D to 2-D correspondences	
    %Update odometry connection	
    %Store representative view of 3-D points	
    %Store distance limits and viewing direction of 3-D points
    %Refine pose	
    %Remove outliers	
       % Add the new key frame 
       [mapPointSet, vSetKeyFrames] = helperAddNewKeyFrame(mapPointSet, vSetKeyFrames, ...
        currPose, currFeatures, currPoints, mapPointsIdx, featureIdx, localKeyFrameIds);

    % Remove outlier map points that are observed in fewer than 3 key frames
    outlierIdx    = setdiff(newPointIdx, mapPointsIdx);
    if ~isempty(outlierIdx)
        mapPointSet   = removeWorldPoints(mapPointSet, outlierIdx);
    end

    % Create new map points by triangulation
    minNumMatches = 10;
    minParallax   = 3;
    [mapPointSet, vSetKeyFrames, newPointIdx] = helperCreateNewMapPoints(mapPointSet, vSetKeyFrames, ...
        currKeyFrameId, intrinsics, scaleFactor, minNumMatches, minParallax);

    % Local bundle adjustment
    [refinedViews, dist] = connectedViews(vSetKeyFrames, currKeyFrameId, MaxDistance=2);
    refinedKeyFrameIds = refinedViews.ViewId;
    fixedViewIds = refinedKeyFrameIds(dist==2);
    fixedViewIds = fixedViewIds(1:min(10, numel(fixedViewIds)));

    % Refine local key frames and map points
    [mapPointSet, vSetKeyFrames, mapPointIdx] = bundleAdjustment(...
        mapPointSet, vSetKeyFrames, [refinedKeyFrameIds; currKeyFrameId], intrinsics, ...
        FixedViewIDs=fixedViewIds, PointsUndistorted=true, AbsoluteTolerance=1e-7,...
        RelativeTolerance=1e-16, Solver="preconditioned-conjugate-gradient", ...
        MaxIteration=10);

    % Update view direction and depth
    mapPointSet = updateLimitsAndDirection(mapPointSet, mapPointIdx, vSetKeyFrames.Views);

    % Update representative view
    mapPointSet = updateRepresentativeView(mapPointSet, mapPointIdx, vSetKeyFrames.Views);

    % Visualize 3D world points and camera trajectory
    updatePlot(mapPlot, vSetKeyFrames, mapPointSet);

%% IV. Loop Closing
    %Construct bag of visual words
    %Create recognition database
    %Identify loop closure candidates	
    %Compute relative camera pose for loop closure candidates	
    %Close loop	

        % Check loop closure after some key frames have been created    
        if currKeyFrameId > 20

            % Minimum number of feature matches of loop edges
            loopEdgeNumMatches = 50;
    
            % Detect possible loop closure key frame candidates
            [isDetected, validLoopCandidates] = helperCheckLoopClosure(vSetKeyFrames, currKeyFrameId, ...
                loopDatabase, I, loopEdgeNumMatches);
    
            if isDetected 
                % Add loop closure connections
                [isLoopClosed, mapPointSet, vSetKeyFrames] = helperAddLoopConnections(...
                    mapPointSet, vSetKeyFrames, validLoopCandidates, currKeyFrameId, ...
                    currFeatures, loopEdgeNumMatches);
            end
        end
    
        % If no loop closure is detected, add current features into the database
        if ~isLoopClosed
            addImageFeatures(loopDatabase,  currFeatures, currKeyFrameId);
        end
    
        % Update IDs and indices
        lastKeyFrameId  = currKeyFrameId;
        lastKeyFrameIdx = currFrameIdx;
        addedFramesIdx  = [addedFramesIdx; currFrameIdx]; %#ok<AGROW>
        currFrameIdx    = currFrameIdx + 1;
end %% End of main loop
%% V. Drift Correction
if isLoopClosed
    % Optimize the poses
    minNumMatches      = 20;
    vSetKeyFramesOptim = optimizePoses(vSetKeyFrames, minNumMatches, Tolerance=1e-16);

    % Update map points after optimizing the poses
    mapPointSet = helperUpdateGlobalMap(mapPointSet, vSetKeyFrames, vSetKeyFramesOptim);

    updatePlot(mapPlot, vSetKeyFrames, mapPointSet);

    % Plot the optimized camera trajectory
    optimizedPoses  = poses(vSetKeyFramesOptim);
    plotOptimizedTrajectory(mapPlot, optimizedPoses)

    % Update legend
    showLegend(mapPlot);
end
% 6. Visualization





%% petla główna 
% while ~isStop
    
%     I=snapshot(cam);
%     I = undistortImage(I, intrinsics);

%     %dispaly current undistorted image from camera
%     figure(1);
%     imshow(I);
%     hold off;

%     I=rgb2gray(I);
%     addFrame(vslam,I);

%     %% Plot intermediate results and wait until all images are processed
%     while ~isDone(vslam)
%         if hasNewKeyFrame(vslam)
%             isLost = false;
%             plot(vslam);
%             xyzPoints = mapPoints(vslam);
%             [camPoses,viewIds] = poses(vslam);
%             fprintf('Added new Keyframe\n')
%             featurePlot   = helperVisualizeMatchedFeatures(I, currPoints(indexPairs(:,2)));
%         end
%     end
    
%     %% Get current status of system
%     lastStatus = status;
%     status = checkStatus(vslam);

%     if status == 0 % tracking lost
%         isLost = true;
%         if ~(lastStatus == status)
%             fprintf('Lost tracking.\n')
%         end
%     end
%     if status == 2 % odrzucony frame
%         isLost = false;
%         if ~(lastStatus == status)
%             if lastStatus == 0
%                 fprintf('Praca wznowniona \n')
%             end
%             fprintf('Frequent Key Frames \n')
%         end
%     end
%     %% instrukcja warunkowa czy system zgubil tracking 
%     if isLost 
%         tempLostTime = toc(isLostTime); 

%         % funkcje wysylajace info o czasie w statusie tracking lost
%         if tempLostTime > 10 && ~isLostTime10
%             isLostTime10 = true;
%             fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
%         elseif tempLostTime > 20 && ~isLostTime20
%             isLostTime20 = true;
%             fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
%         elseif tempLostTime > 30 && ~isLostTime30
%             isLostTime30 = true;
%             fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
%         end 
%         % funkcja wychodzaca z petli
%         if tempLostTime>duration
%             isStop = true;
%             fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
%             fprintf("zatrzymana praca po: %.1f sek\n",toc(startTime))
%         end
%     else
%         % resetowanie danych dot. zgubionego trackingu
%         isLostTime10 = false;
%         isLostTime20 = false;
%         isLostTime30 = false;
%         isLostTime = tic;
%     end
    
% end
clear cam;
% %%

