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
% currImage.Position = [1000 0 720 480];
% keyImage.Position = [100 1000 720 480];
% numPoints   = 1000;
% numSkipFrames = 20;
% numLevels = 8;
% scaleFactor = 1.2;
% verbose = true;
% trackFeatureRange = [20,100];
% loopClosureThreshold = 60;
% 
% vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames, ...
%     NumLevels=numLevels,ScaleFactor=scaleFactor,Verbose=verbose, ...
%     TrackFeatureRange=trackFeatureRange,LoopClosureThreshold=loopClosureThreshold);

%warunki sprawdzajace czy aby kontynuowac petle i czy tracking jest
%zgubiony 
isStop = false;
isLost = false;
camPose = eye(4);
xyzPoints = [];
%% petla główna 
while ~isStop
    
    I = snapshot(cam);
    I=rgb2gray(I);
    I = undistortImage(I, intrinsics);

    %dispaly current undistorted image from camera
    figure(currImage);
    imagesc(I);
    drawnow;
    colormap('gray');
    hold off;
    
    [xyzPoints, camPose] = testyCodegena_mex(I);
    % Convert camPoses to trajectory for display
    camPoses = rigidtform3d(camPose(1:3,1:3),camPose(4,1:3));
    % viewer = helperVisualSLAMViewer(xyzPoints,camPoses);
    % viewer.updatePlot(xyzPoints, camPoses);
    
end
clear cam;
%%
function keyPressCallback(~, event)
    if strcmp(event.Key, 'q')
       assignin('base', 'isStop', true);
        fprintf('Naciśnięto klawisz "q". Kończenie pętli...');% Zamknięcie okna figure
    end
end