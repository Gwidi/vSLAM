function [outimage] = DistWrapper(image)
%DISTWRAPPER Summary of this function goes here
%   Detailed explanation goes here
persistent intrinsics
if isempty(intrinsics)
    % principalPoint=[628.2,507.98];
    % focalLength=[734.42,735.91];
    % radialDistortion = [-0.2524,0.0536];
    % imageSize=[1024,1280];
    principalPoint=[644.5,355.6];
    focalLength=[983.4,989.3];
    imageSize=[720,1280];
    radialDistortion = [0, 0];
    intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize,'RadialDistortion',radialDistortion);
end
outimage = undistortImage(image,intrinsics);
end

