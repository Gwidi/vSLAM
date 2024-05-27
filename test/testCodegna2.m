% %% kalibracja kamery 
% % kuba
%principalPoint=[644.5,355.6];
%focalLength=[983.4,989.3];

% gwidon 
principalPoint=[651.7301,433.2670];
focalLength=[951.6815,955.0682];

imageSize=[720,1280];
intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize);
%%parametry 
% Connect to the webcam.
cam = webcam();  % Assumes the default webcam.

% Create a publisher to publish map points and camera poses to MATLAB
cameraPub = ros2publisher(node,'/visualizePoints','std_msgs/Float64MultiArray');

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
keyFrameCount = 0;
mkdir('img');



%% petla główna 
while ~isStop
    
    I = snapshot(cam);
    %I=rgb2gray(I);
    I = undistortImage(I, intrinsics);

    %dispaly current undistorted image from camera
    figure(currImage);
    imagesc(I);
    drawnow;
    colormap('gray');
    hold off;
    
    [worldPoints, transformation] = testyCodegena_mex64(I);

    R = transformation(1:3, 1:3); % Macierz rotacji
    Translation = transformation(1:3, 4);   % Wektor translacji

    camPoses = rigidtform3d(transformation);

    msg = rosmessage('std_msgs/Float64MultiArray', 'DataFormat', 'struct');
    % Pack camera poses for publishing
    poseSize = numel(camPoses);
    transAndRots = zeros(poseSize*4,3);
    for i = 0:poseSize-1
        transAndRots(i*4+1,:) = camPoses(i+1).Translation;
        transAndRots(i*4+2:i*4+4,:) = camPoses(i+1).R;
    end
            
    % Concatenate poses and points into one struct
    allData = vertcat(transAndRots, worldPoints);
    allDataSize = size(allData,1);
    flattenPoints = reshape(allData,[allDataSize*3 1]);
    msg.data = flattenPoints;
    
    % Set the layout dimensions
    dim = ros2message('std_msgs/MultiArrayDimension'); % Zmienione na ros2message
    dim.Label = 'poses_points';
    dim.Size = uint32(size(flattenPoints, 1));
    dim.Stride = uint32(size(flattenPoints, 1));

    % Assign the dimension to the layout
    msg.layout.dim = dim;
    msg.layout.data_offset =uint32(0);

    send(cameraPub, msg);
end
clear cam;
%%
function keyPressCallback(~, event)
    if strcmp(event.Key, 'q')
       assignin('base', 'isStop', true);
        fprintf('Naciśnięto klawisz "q". Kończenie pętli...');% Zamknięcie okna figure
    end
end