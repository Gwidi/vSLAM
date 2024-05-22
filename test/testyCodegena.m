function [xyzPoint, camPoses] = testyCodegena(image)

    %   Copyright 2023 The MathWorks Inc.
    
    %#codegen
    
    persistent vslam xyzPointsInternal camPosesInternal
    
    if isempty(vslam)
        % %% kalibracja kamery 
        % % kuba
        principalPoint=[644.5,355.6];
        focalLength=[983.4,989.3];

        % gwidon 
        % principalPoint=[651.7301,433.2670];
        % focalLength=[951.6815,955.0682];

        imageSize=[720,1280];
        intrinsics     = cameraIntrinsics(focalLength, principalPoint, imageSize);
        numPoints   = 2000;
        numSkipFrames = 20;
        numLevels = 8;
        scaleFactor = 1.4;
        verbose = false;
        trackFeatureRange = [30,100];
        loopClosureThreshold = 60;

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
    
    % Convert camera poses to homogeneous transformation matrices
    camPoses = cat(3, camPosesInternal.A);