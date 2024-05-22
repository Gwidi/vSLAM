% %% kalibracja kamery 
% % kuba
principalPoint=[644.5,355.6];
focalLength=[983.4,989.3];

% gwidon 
% principalPoint=[651.7301,433.2670];
% focalLength=[951.6815,955.0682];

imageSize=[720,1280];
intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize);
%%parametry 
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
currImage = figure( 'Name',"Current Image from camera",'NumberTitle','off','KeyPressFcn', @keyPressCallback);% For camera image
keyImage = figure('Name',"Last keyFrame from camera",'NumberTitle','off','KeyPressFcn', @keyPressCallback);
%plotImage = figure('Name',"Current Map points",'NumberTitle','off','KeyPressFcn', @keyPressCallback);
currImage.Position = [1000 0 720 480];
keyImage.Position = [100 1000 720 480];
numPoints   = 1000;
numSkipFrames = 20;
numLevels = 8;
scaleFactor = 1.2;
verbose = true;
trackFeatureRange = [20,100];
loopClosureThreshold = 60;

vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames, ...
    NumLevels=numLevels,ScaleFactor=scaleFactor,Verbose=verbose, ...
    TrackFeatureRange=trackFeatureRange,LoopClosureThreshold=loopClosureThreshold);

%warunki sprawdzajace czy aby kontynuowac petle i czy tracking jest
%zgubiony 
isStop = false;
isLost = false;

%% petla główna 
while ~isStop
    
    I=snapshot(cam);
    I = undistortImage(I, intrinsics);

    %dispaly current undistorted image from camera
    figure(currImage);
    imagesc(I);
    drawnow;
    hold off;

    I=rgb2gray(I); %monovslam sam zamienia na skale szarosci
    addFrame(vslam,I);
    %% Plot intermediate results and wait until all images are processed
    while ~isDone(vslam)
        if hasNewKeyFrame(vslam)
            isLost = false;
 
            plot(vslam); % mozna uzyc paramteru ,"Parent" ale nie wiem jak 
           
            figure(keyImage)
            imagesc(I);
            colormap('gray');
            drawnow;
            hold off;
            xyzPoints = mapPoints(vslam);
            [camPoses,viewIds] = poses(vslam);
            % fprintf('Added new Keyframe\n')
            % featurePlot   = helperVisualizeMotionAndStructure(I, currPoints(indexPairs(:,2)));
        end
    end
    
    % Get current status of system
    lastStatus = status;
    status = checkStatus(vslam);

    switch status
        case 0
            isLost = true;
            if ~(lastStatus == status)
                fprintf('Lost tracking.\n')
            end
        case 2
            isLost = false;
        if ~(lastStatus == status)
            if lastStatus == 0
                fprintf('Praca wznowniona \n')
            end
            fprintf('Frequent Key Frames \n')
        end
    end
    %% instrukcja warunkowa czy system zgubil tracking 
    if isLost 
        tempLostTime = toc(isLostTime); 

        % funkcje wysylajace info o czasie w statusie tracking lost
        if tempLostTime > 10 && ~isLostTime10
            isLostTime10 = true;
            fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
        elseif tempLostTime > 20 && ~isLostTime20
            isLostTime20 = true;
            fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
        elseif tempLostTime > 30 && ~isLostTime30
            isLostTime30 = true;
            fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
        end 
    else
        % resetowanie danych dot. zgubionego trackingu
        isLostTime10 = false;
        isLostTime20 = false;
        isLostTime30 = false;
        isLostTime = tic;
    end
    
end
clear cam;
%%
function keyPressCallback(~, event)
    if strcmp(event.Key, 'q')
       assignin('base', 'isStop', true);
        disp('Naciśnięto klawisz "q". Kończenie pętli...');% Zamknięcie okna figure
    end
end