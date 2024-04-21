principalPoint=[651.7301,433.2670];
focalLength=[951.6815,955.0682];
imageSize=[720,1280];
intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize);

vslam = monovslam(intrinsics, MaxNumPoints=1000, SkipMaxFrames=20);

% Connect to the webcam.
cam = webcam;  % Assumes the default webcam.

duration=30;

% Rozpocznij pomiar czasu
startTime = tic;

while toc(startTime) < duration
    I=snapshot(cam);
    I=rgb2gray(I)
    addFrame(vslam,I)

    if hasNewKeyFrame(vslam)
        % Query 3-D map points and camera poses
        xyzPoints = mapPoints(vslam);
        [camPoses,viewIds] = poses(vslam);

        % Display 3-D map points and camera trajectory
        plot(vslam);
    end

    % Get current status of system
    status = checkStatus(vslam);
end 

% Clean up and release the webcam resource, regardless of how the try block exits.
clear cam;