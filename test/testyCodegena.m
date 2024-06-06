function [xyzPoint, camPoses, status] = testyCodegena(image,imageSize, ...
    principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, ...
    scaleFactor, verbose,trackFeatureRange,loopClosureThreshold, isReturnAll)

    %   Copyright 2023 The MathWorks Inc.
    % image,imageSize, ...
    % principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, ...
    % verbose,trackFeatureRange
    %#codegen
    
    persistent vslam xyzPointsInternal camPosesInternal
    
    if isempty(vslam)
        % %% kalibracja kamery 
        % % kuba
        % principalPoint=[644.5,355.6];
        % focalLength=[983.4,989.3];

        % gwidon 
        principalPoint=[651.7301,433.2670];
        focalLength=[951.6815,955.0682];

        imageSize=[720,1280];
        intrinsics     = cameraIntrinsics(focalLength, principalPoint, imageSize);
        numPoints   = 2000; 
        numSkipFrames = 20;
        numLevels = 8;
        scaleFactor = 1.4;
        verbose = false;
        trackFeatureRange = [30,100];
        loopClosureThreshold = 60;
      
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
    numPoses = numel(camPosesInternal);
    % Convert camera poses to homogeneous transformation matrices
    % czy Zwrocic caly Poses czy nie 
    if ~(isReturnAll)
        if numPoses > 0
            camPoses  = camPosesInternal(numPoses).A;
        else
            camPoses = eye(4);
        end
    else
        if numPoses > 0
            camPoses = [zeros(numPoses*4,4,'double')];
            for k = 1:numPoses
                camPoses(k*4-3:k*4,1:4) = camPosesInternal(k).A;
            end
        else 
            camPoses = eye(4);
        end
    end