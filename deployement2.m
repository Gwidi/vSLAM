%% kalibracja kamery 
% kuba
principalPoint=[644.5,355.6];
focalLength=[983.4,989.3];
% gwidon 
% principalPoint=[651.7301,433.2670];
% focalLength=[951.6815,955.0682];
imageSize=[720,1280];
intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize);

% Connect to the webcam.
cam = webcam;  % Assumes the default webcam.

duration=30;

% Rozpocznij pomiar czasu
startTime = tic;
duration=60;

% Create figure windows
figure(1); % For camera image
numPoints   = 1000;
numSkipFrames = 20;
vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames);


while toc(startTime) < duration
    
    I=snapshot(cam);
    I = undistortImage(I, intrinsics);
    addFrame(vslam,I);

    %dispaly current undistorted image from camera
    figure(1);
    imshow(I);
    hold off;
    
    if hasNewKeyFrame(vslam)
        % Display 3-D map points and camera trajectory
        plot(vslam);   
    end
    %% Plot intermediate results and wait until all images are processed
    while ~isDone(vslam)
        if hasNewKeyFrame(vslam)
            plot(vslam);
            xyzPoints = mapPoints(vslam);
            [camPoses,viewIds] = poses(vslam);
        end
    end
    
    %% Get current status of system
    status = checkStatus(vslam);

    if status == 0
        disp('Lost tracking.')
    end
    if status == 2
        disp('FrequentKeyFrames') 
    end
end
clear cam;
%%
