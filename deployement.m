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

%Dlugosc czasu zanim funkcja sie wylaczy po uzyskaniu tracking lost.
duration=30;

% Rozpocznij pomiar czasu
startTime = tic; %od poczatku uruchomienia progrmau 
isLostTime = tic; %dlugosc czasu na statusie tracking lost

%poprzedni i obecny status obiektu vslam 
lastStatus = 0;
status = 0;

%sprawdzanie czy wyslano komunikat o uplywie czasu - status tracking lost
isLostTime10 = false;
isLostTime20 = false;
isLostTime30 = false;

% Konfig obiektu vslam 
figure(1); % For camera image
numPoints   = 1600;
numSkipFrames = 20;
vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames);

%warunki sprawdzajace czy aby kontynuowac petle i czy tracking jest
%zgubiony 
isStop = false;
isLost = false;

%% petla główna 
while ~isStop
    
    I=snapshot(cam);
    I = undistortImage(I, intrinsics);

    %dispaly current undistorted image from camera
    figure(1);
    imshow(I);
    hold off;

    I=rgb2gray(I);
    addFrame(vslam,I);

    %% Plot intermediate results and wait until all images are processed
    while ~isDone(vslam)
        if hasNewKeyFrame(vslam)
            isLost = false;
            plot(vslam);
            xyzPoints = mapPoints(vslam);
            [camPoses,viewIds] = poses(vslam);
            fprintf('Added new Keyframe\n')
            featurePlot   = helperVisualizeMatchedFeatures(I, currPoints(indexPairs(:,2)));
        end
    end
    
    %% Get current status of system
    lastStatus = status;
    status = checkStatus(vslam);

    if status == 0 % tracking lost
        isLost = true;
        if ~(lastStatus == status)
            fprintf('Lost tracking.\n')
        end
    end
    if status == 2 % odrzucony frame
        isLost = false;
        if ~(lastStatus == status)
            if lastStatus == 0
                fprintf('Praca wznowniona \n')
            end
            fprintf('Frequent Key Frames \n')
        end
    end
    %% instrukcja warunkowa czy system zgubil tracking 
    if isLost 
        tempLostTime = toc(isLostTime); 

        % funkcje wysylajace info o czasie w statusie tracking lost
        if tempLostTime > 10 && ~isLostTime10
            isLostTime10 = true;
            fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
        elseif tempLostTime > 20 && ~isLostTime20
            isLostTime20 = true;
            fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
        elseif tempLostTime > 30 && ~isLostTime30
            isLostTime30 = true;
            fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
        end 
        % funkcja wychodzaca z petli
        if tempLostTime>duration
            isStop = true;
            fprintf("tracking lost przez: %.1f sek\n",tempLostTime)
            fprintf("zatrzymana praca po: %.1f sek\n",toc(startTime))
        end
    else
        % resetowanie danych dot. zgubionego trackingu
        isLostTime10 = false;
        isLostTime20 = false;
        isLostTime30 = false;
        isLostTime = tic;
    end
    
end
clear cam;
%%
