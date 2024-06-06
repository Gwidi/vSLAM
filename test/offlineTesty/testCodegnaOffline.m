clear;
close all;
clear testyCodegena_mex9;
clear testyCodegena_mex1x24;
clear testyCodegena;
clear helperVisualSLAMViewer;
% %% kalibracja kamery 
%EuRoC dataset 
% Intrinsics
% ----------
% Focal length (pixels):   [  734.4191 +/- 0.5139      735.9122 +/- 0.5117  ]
% Principal point (pixels):[  628.2064 +/- 0.6888      507.9858 +/- 0.5796  ]
% Radial distortion:       [   -0.2524 +/- 0.0006        0.0536 +/- 0.0003  ]
principalPoint=[628.2,507.98];
focalLength=[734.42,735.91];
radialDistortion = [-0.2524,0.0536];
imageSize=[1024,1280];

% % kuba
% principalPoint=[644.5,355.6];
% focalLength=[983.4,989.3];
% imageSize=[720,1280];
% radialDistortion = [0, 0];

intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize,'RadialDistortion',radialDistortion);

%ros pub 
node = ros2node("visualizePoints");
% Create a publisher to publish map points and camera poses to MATLAB
cameraPub = ros2publisher(node,'/points','std_msgs/Float64MultiArray');

% gwidon 
% principalPoint=[651.7301,433.2670];
% focalLength=[951.6815,955.0682];
%%parametry 

status = 0;

% Czy wlaczyc wizualizacje lokalna 
isEneablePlot = false;

% Konfig obiektu vslam
if isEneablePlot
    keyImage = figure('Name',"Last Frame from camera",'NumberTitle','off','KeyPressFcn', @keyPressCallback);
end
numPoints   = 3000;
numSkipFrames = 15; 
numLevels = 30; % floor((log(1024)-log(63))/(log(1.2)))+1
scaleFactor = 1.1;
verbose = false;
trackFeatureRange = [5,300];
loopClosureThreshold = 60;
% 
% vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames, ...
%     NumLevels=numLevels,ScaleFactor=scaleFactor,Verbose=verbose, ...
%     TrackFeatureRange=trackFeatureRange,LoopClosureThreshold=loopClosureThreshold);

%warunki sprawdzajace czy aby kontynuowac petle i czy tracking jest
%zgubiony 
isStop = false;
camLastPose = zeros(4);
camPoses = eye(4);
xyzPoints = [0,0,0];
imds = imageDatastore("./images30/");
vSet = imageviewset;
vSetIndex = 0;
trajectory = rigidtform3d;
numLastTrackedPoints = 0;
isMapInit = false;
isMapInitLast = false;
%% petla główna 
for i = 1:numel(imds.Files)
    
    % I = snapshot(cam);f
    I = readimage(imds,i);
    % I = rgb2gray(I);
    % I = undistortImage(I, intrinsics);
    I = DistWrapper_mex3(I);
    if isEneablePlot
        figure(keyImage);
        imagesc(I);
        drawnow;
        colormap('gray');
        hold off;
    end
    [xyzPoints, camPoses, status] = testyCodegena(I,imageSize, ...
    principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, ...
    scaleFactor, verbose,trackFeatureRange,loopClosureThreshold,isStop );
    
    if ~(isequal(camPoses,camLastPose))
        vSetIndex = vSetIndex + 1;
        camLastPose = camPoses;
        if ~(hasView(vSet,vSetIndex))
            temp = rigidtform3d(camPoses);
            vSet = addView(vSet,vSetIndex,temp);
        end
        if vSetIndex == 2 && isEneablePlot
                visualHelper = helperVisualSLAMViewer(xyzPoints,vSet.poses{:,2});
                visualHelper.Axes.XLimMode = 'auto';
                visualHelper.Axes.YLimMode = 'auto';
                visualHelper.Axes.ZLimMode = 'auto';
                visualHelper.Axes.Children.findobj('Color','r').set('Color','magenta')
                visualHelper.Axes.Children.findobj('Color','b').set('Color','cyan')
        end
        if vSetIndex > 1
            if ~(hasConnection(vSet,vSetIndex-1,vSetIndex))
                vSet = addConnection(vSet,vSetIndex-1,vSetIndex);
            end
            if isEneablePlot
            updatePlot(visualHelper,xyzPoints,vSet.poses{:,2});
            end
        end
    end
    if ~(isMapInit == isMapInitLast)
        fprintf('======== Map Initializted ========\n Tracking started at %d Frame\n', i);
        isMapInitLast = true;
    end
    switch status
        case 0 
            fprintf('%d ,Tracking lost\n', i);
        case 1
            fprintf('%d ,TrackingSuccessful\n', i);
        case 2
            fprintf('%d ,FrequentKeyFrames\n', i);
    end
    %% ros2
    msg = ros2message('std_msgs/Float64MultiArray');
    allData = vertcat(camPoses, xyzPoints);
    allDataSize = size(allData,1);
    flattenPoints = reshape(allData,[allDataSize*3 1]);
    msg.Data = flattenPoints;
    msg.Layout.Dim = ros2message('std_msgs/MultiArrayDimension');
    msg.Layout.Dim(end).Size = uint32(poseSize);
    send(cameraPub, msg);
    if isStop
        break;
    end
end
%% end of dataset 
isStop = true;

[xyzPoints, camPoses, status ] = testyCodegena(I,imageSize, ...
    principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, ...
    scaleFactor, verbose,trackFeatureRange,loopClosureThreshold,isStop );

for k = 1:numel(camPoses)/16
            temp = rigidtform3d([camPoses(4*k-3,1), camPoses(4*k-3,2), camPoses(4*k-3,3), camPoses(4*k-3,4); ...
                                 camPoses(4*k-2,1), camPoses(4*k-2,2), camPoses(4*k-2,3), camPoses(4*k-2,4); ...
                                 camPoses(4*k-1,1), camPoses(4*k-1,2), camPoses(4*k-1,3), camPoses(4*k-1,4); ...
                                 camPoses(4*k,1), camPoses(4*k,2), camPoses(4*k,3), camPoses(4*k,4);]);
            if hasView(vSet,k)
                vSet = updateView(vSet,k,temp);
            else
                vSet = addView(vSet,k,temp);
            end
            if k > 1
                if hasConnection(vSet,k-1,k)
                    vSet = updateConnection(vSet,k-1,k);
                else
                    vSet = addConnection(vSet,k-1,k);
                end
            end
end
if isEneablePlot
createViewer(visualHelper,xyzPoints,temp,vertcat(vSet.poses{:,2}.Translation));
end
if ~isEneablePlot
    visualHelper = helperVisualSLAMViewer(xyzPoints,vSet.poses{:,2});
    visualHelper.Axes.XLimMode = 'auto';
    visualHelper.Axes.YLimMode = 'auto';
    visualHelper.Axes.ZLimMode = 'auto';
    visualHelper.Axes.Children.findobj('Color','r').set('Color','magenta');
    visualHelper.Axes.Children.findobj('Color','b').set('Color','cyan');
end
function keyPressCallback(~, event)
    if strcmp(event.Key, 'q')
       assignin('base', 'isStop', true);
        fprintf('Naciśnięto klawisz "q". Kończenie pętli...');% Zamknięcie okna figure
    end
end