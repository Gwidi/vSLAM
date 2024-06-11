function [xyzPoint, camPoses, status, MapInit] = testyCodegena(image,imageSize, ...
    principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, ...
    scaleFactor, verbose,trackFeatureRange,loopClosureThreshold, isReturnAll)

    %   Copyright 2023 The MathWorks Inc.
    % image,imageSize, ...
    % principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, ...
    % verbose,trackFeatureRange
    %#codegen
    
    persistent vslam xyzPointsInternal camPosesInternal
    
    if isempty(vslam)
      
        intrinsics     = cameraIntrinsics(focalLength, principalPoint, ...
            imageSize,'RadialDistortion',radialDistortion);

        vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames, ...
            NumLevels=numLevels,ScaleFactor=scaleFactor,Verbose=verbose, ...
            TrackFeatureRange=trackFeatureRange,LoopClosureThreshold=loopClosureThreshold);
    end
    
    % Process each image frame
    
    addFrame(vslam, image);
    

    % Get 3-D map points and camera poses
    if isempty(camPosesInternal) || hasNewKeyFrame(vslam)
        xyzPointsInternal = mapPoints(vslam);
        camPosesInternal = poses(vslam);
    end
    xyzPoint = xyzPointsInternal;

    status = checkStatus(vslam);
    numPoses = numel(camPosesInternal);
    % Convert camera poses to homogeneous transformation matrices
    % czy Zwrocic caly Poses czy nie 
    if ~(isReturnAll)
        if numPoses > 0
            camPoses  = camPosesInternal(end).A;
        else
            camPosesInternal = [rigidtform3d(eye(4))];
            camPoses = eye(4);
        end
    else
        if numPoses > 0
            camPoses = [zeros(numPoses*4,4,'double')];
            for k = 1:numPoses
                camPoses(k*4-3:k*4,1:4) = camPosesInternal(k).A;
            end
        else
            camPosesInternal = [rigidtform3d(eye(4))];
            camPoses = eye(4);
        end
    end
   MapInit = isMapInitialized(vslam);
   if isReturnAll
       while ~(vslam.isDone)
        a=1+1;
       end
   end
