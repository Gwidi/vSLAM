function [xyzPoint, camPoses, status] = testyCodegena(image,imageSize, ...
    principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, ...
    scaleFactor, verbose,trackFeatureRange,loopClosureThreshold )

    %   Copyright 2023 The MathWorks Inc.
    % image,imageSize, ...
    % principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, ...
    % verbose,trackFeatureRange
    %#codegen
    
    persistent vslam xyzPointsInternal camPosesInternal
    
    if isempty(vslam)
        % %% kalibracja kamery 
        % % kuba
  

        % gwidon 
        % principalPoint=[651.7301,433.2670];
        % focalLength=[951.6815,955.0682];

        intrinsics     = cameraIntrinsics(focalLength, principalPoint, ...
            imageSize,'RadialDistortion',radialDistortion);

        vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames, ...
            NumLevels=numLevels,ScaleFactor=scaleFactor,Verbose=verbose, ...
            TrackFeatureRange=trackFeatureRange,LoopClosureThreshold=loopClosureThreshold);
    end
    
    % Process each image frame
    addFrame(vslam, image);
    
    % Get 3-D map points and camera poses
    if isempty(xyzPointsInternal) || hasNewKeyFrame(vslam)
        xyzPointsInternal = mapPoints(vslam);
        camPosesInternal = poses(vslam);
    end
    xyzPoint = xyzPointsInternal;

    status = checkStatus(vslam);
    numPoses = numel(camPosesInternal)
    % Convert camera poses to homogeneous transformation matrices
    if numPoses > 0
        camPoses = [zeros(numPoses*4,4,'double')];
        for k = 1:numPoses
            camPoses(k*4-3:k*4,1:4) = camPosesInternal(k).A;

        end
    else
        camPoses = eye(4);
    end