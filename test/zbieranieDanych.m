% %% kalibracja kamery 
% % kuba
principalPoint=[644.5,355.6];
focalLength=[983.4,989.3];

% gwidon 
% principalPoint=[651.7301,433.2670];
% focalLength=[951.6815,955.0682];

imageSize=[720,1280];
intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize);
%%parametry 
% Connect to the webcam.
cam = webcam();  % Assumes the default webcam.


% Konfig obiektu vslam 
currImage = figure( 'Name',"Current Image from camera",'NumberTitle','off','KeyPressFcn', @keyPressCallback);% For camera image

isStop = false;
i=10000;
%% petla główna 
while ~isStop
    i = i+1;
    I = snapshot(cam);
    I = undistortImage(I, intrinsics);

    %dispaly current undistorted image from camera
    figure(currImage);
    imagesc(I);
    drawnow;
    imwrite(I,cat(2,'./img/',num2str(i),'.png'));
    
end
clear cam;
%%
function keyPressCallback(~, event)
    if strcmp(event.Key, 'q')
       assignin('base', 'isStop', true);
        fprintf('Naciśnięto klawisz "q". Kończenie pętli...');% Zamknięcie okna figure
    end
end