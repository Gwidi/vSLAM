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


% Konfig obiektu vslam 
currImage = figure( 'Name',"Current Image from camera",'NumberTitle','off','KeyPressFcn', @keyPressCallback);% For camera image
keyImage = figure('Name',"Last keyFrame from camera",'NumberTitle','off','KeyPressFcn', @keyPressCallback);
%plotImage = figure('Name',"Current Map points",'NumberTitle','off','KeyPressFcn', @keyPressCallback);
currImage.Position = [1000 0 720 480];
keyImage.Position = [100 1000 720 480];
numPoints   = 2000;
numSkipFrames = 20;
numLevels = 8;
scaleFactor = 1.4;
verbose = true;
trackFeatureRange = [20,300];
loopClosureThreshold = 60;

vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames, ...
    NumLevels=numLevels,ScaleFactor=scaleFactor,Verbose=verbose, ...
    TrackFeatureRange=trackFeatureRange,LoopClosureThreshold=loopClosureThreshold);

%warunki sprawdzajace czy aby kontynuowac petle i czy tracking jest
%zgubiony 
isStop = false;
isLost = false;
imds = imageDatastore("./img/");
%% petla główna 
for i = 1:numel(imds.Files)
    
    I = imds.readimage(i);
    I=rgb2gray(I);
    sigma = 1.6;
    I = imgaussfilt(I,sigma);
    % I = imgradient(I,"CentralDifference");
    %dispaly current undistorted image from camera
    figure(currImage);
    imagesc(I);
    drawnow;
    hold off;

     %monovslam sam zamienia na skale szarosci
    addFrame(vslam,I);

    %% Plot intermediate results and wait until all images are processed
    while ~isDone(vslam)
        if hasNewKeyFrame(vslam)
            plot(vslam); % mozna uzyc paramteru ,"Parent" ale nie wiem jak 
            figure(keyImage)
            imagesc(I);
            colormap('gray');
            drawnow;
            hold off;
            xyzPoints = mapPoints(vslam);
            [camPoses,viewIds] = poses(vslam);
        end
    end
    
    % Get current status of system
    status = checkStatus(vslam);

    
    %% instrukcja warunkowa czy system zgubil tracking 
    switch status
        case 0 
            fprintf('%d ,Tracking lost\n', i);
        case 1
            fprintf('%d ,TrackingSuccessful\n', i);
        case 2
            fprintf('%d ,FrequentKeyFrames\n', i);
    end
    if isStop
        break
    end
    
end
clear cam;
%%
function keyPressCallback(~, event)
    if strcmp(event.Key, 'q')
       assignin('base', 'isStop', true);
        fprintf('Naciśnięto klawisz "q". Kończenie pętli...');% Zamknięcie okna figure
    end
end