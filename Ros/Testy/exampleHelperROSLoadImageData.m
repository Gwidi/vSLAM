%exampleHelperROSLoadImageData Load image data 
%   This script will load an image that was recorded from a robotic
%   sensor.
%
%   See also ROSSpecializedMessagesExample.

%   Copyright 2021 The MathWorks, Inc.

% Load image message
imgCell = load('specialROSMessageData.mat', 'img');
imgMsg = imgCell.img;
% Extract data
img = rosReadImage(imgMsg);

% Clear variables from the workspace that are not needed anymore

clear imgCell imgMsg