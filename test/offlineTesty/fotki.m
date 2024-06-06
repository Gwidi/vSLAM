function [I] = fotki()
%FOTKI Summary of this function goes here
%   Detailed explanation goes here
persistent cam 
if isempty(cam)
    cam = webcam;
end
I = snapshot(cam);
I = rgb2gray(I);
end

