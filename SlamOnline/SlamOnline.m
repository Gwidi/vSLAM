clear;
close all;
clear waitCodegen_mex720;
clear helperVisualSLAMViewer;
clear node;
rosshutdown;
rosinit

%% kalibracja kamery 

% EuRoC dataset 
% Intrinsics
% ----------
% Focal length (pixels):   [  734.4191 +/- 0.5139      735.9122 +/- 0.5117  ]
% Principal point (pixels):[  628.2064 +/- 0.6888      507.9858 +/- 0.5796  ]
% Radial distortion:       [   -0.2524 +/- 0.0006        0.0536 +/- 0.0003  ]
% principalPoint=[628.2,507.98];
% focalLength=[734.42,735.91];
% radialDistortion = [-0.2524,0.0536];
% imageSize=[1024,1280];

% % kuba
principalPoint=[644.5,355.6];
focalLength=[983.4,989.3];

% gwidon 
% principalPoint=[651.7301,433.2670];
% focalLength=[951.6815,955.0682];

imageSize=[720,1280];
radialDistortion = [0, 0];

% kalibracja kamery  
intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize,'RadialDistortion',radialDistortion);
cam = webcam();


%% Konfiguracja obiektu vslam

% Czy wlaczyc wizualizacje lokalna 
isEneablePlot = false; % mapa 3d + trajektoria
isEneablePic = true; % przetwarzana klatka
isEneablePlotAtEnd = false; % czy wyswietlic mape + traj na koniec lokalnie
if isEneablePic
    keyImage = figure('Name',"Last Frame from camera",'NumberTitle','off','KeyPressFcn', @keyPressCallback);
end
if isEneablePlot || isEneablePlotAtEnd
    vSet = imageviewset; % obiekt do przychowywania trajektori
    vSetIndex = 0;
end

% parametry obiektu monovslam
numPoints   = 3000;
numSkipFrames = 15; 
numLevels = 30; % obliczanie max leveli i scali
scaleFactor = 1.1; % floor((log(1024)-log(63))/(log(1.1)))+1
verbose = false;
trackFeatureRange = [15,300];
loopClosureThreshold = 60;
% struktura obiektu monovslam 
% vslam = monovslam(intrinsics,MaxNumPoints=numPoints,SkipMaxFrames=numSkipFrames, ...
%     NumLevels=numLevels,ScaleFactor=scaleFactor,Verbose=verbose, ...
%     TrackFeatureRange=trackFeatureRange,LoopClosureThreshold=loopClosureThreshold);

%% warunki sprawdzajace czy aby kontynuowac petle i trackingu 

isStop = false; % warunek zatrzymania
camLastPose = zeros(4); % ostatnia pozycja kamery
camPoses = eye(4); % obecna pozycja kamery;
isMapInit = false; % czy mapa zaincjalizowana 
isMapInitLast = false;

%% Ros2 - PointCloud

% Tworzenie węzła ROS
node = ros2node('/slam');

%Tworzenie publishera
pubCloud = ros2publisher(node, '/PointsCloud', 'sensor_msgs/PointCloud2');

% Tworzenie wiadomosci 
msgCloud = ros2message('sensor_msgs/PointCloud2');
msgCloud.header.frame_id = 'map';

msgCloud.height = uint32(1);
msgCloud.width = uint32(0);
msgCloud.point_step = uint32(12);

% Ustawianie parametrow wiadmosci 
msgCloud.fields(1) = ros2message('sensor_msgs/PointField');
msgCloud.fields(1).name = 'x';
msgCloud.fields(1).offset = uint32(0);
msgCloud.fields(1).datatype = uint8(7);
msgCloud.fields(1).count = uint32(1);

msgCloud.fields(2) = ros2message('sensor_msgs/PointField');
msgCloud.fields(2).name = 'y';
msgCloud.fields(2).offset = uint32(4);
msgCloud.fields(2).datatype = uint8(7);
msgCloud.fields(2).count = uint32(1);

msgCloud.fields(3) = ros2message('sensor_msgs/PointField');
msgCloud.fields(3).name = 'z';
msgCloud.fields(3).offset = uint32(8);
msgCloud.fields(3).datatype = uint8(7);
msgCloud.fields(3).count = uint32(1);

%% Ros 2 - Camera Marker

% Tworzenie publishera
pubMarker = ros2publisher(node, '/Marker', 'visualization_msgs/Marker');

% Tworzenie wiadomosci
msgMarker = ros2message('visualization_msgs/Marker');

msgMarker.header.frame_id = 'map';
msgMarker.ns = 'map';
msgMarker.type = int32(3);

% Ustawienie koloru
msgMarker.scale.x = 0.1;
msgMarker.scale.y = 0.1;
msgMarker.scale.z = 0.3;

% Wybranie koloru 
msgMarker.color.a = single(0.5);
msgMarker.color.r = single(255);
msgMarker.color.g = single(255);
msgMarker.color.b = single(0);

%% Ros2 - Path

% Tworzenie publishera
pubPath = ros2publisher(node, '/Path', 'nav_msgs/Path');

% Tworzenie wiadomosci
msgPath = ros2message('nav_msgs/Path');
msgPath.header.frame_id = 'map';
msgPath.poses = [];

%% Ros2 - koniec publishers

%Tworzenie publishera
pubCloudEnd = ros2publisher(node, '/PointsCloudEnd', 'sensor_msgs/PointCloud2');
pubMarkerEnd = ros2publisher(node, '/MarkerEnd', 'visualization_msgs/Marker');
pubPathEnd = ros2publisher(node, '/PathEnd', 'nav_msgs/Path');

% Pomiar czasu
tic;
FrameId = uint32(0);
%% petla główna 
while (toc < 300) && ~isStop
    %% Warunek Stopu
    if isStop
        break;
    end
    FrameId = FrameId + 1;
    %% Przygotowanie kolejnej klatki 
    I = snapshot(cam);
    
    % Wczytanie kolejnej klatki 
    % I = readimage(imds,i);
    I = rgb2gray(I);

    % Pozbywanie sie znieksztalcen z przetwarzanej klatki
    I = DistWrapper_mex3_720(I);
   

    %% Algorytm SLAM
    [xyzPoints, camPoses, status] = waitCodegen_mex720(I,imageSize, principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels,scaleFactor, verbose,trackFeatureRange,loopClosureThreshold,false );

    %% Instrukcja w przypadku dodaniu kolejnej pozycji 
    if ~(isequal(camPoses,camLastPose))
        camLastPose = camPoses;
        % Wyswietlanie przetwarzanej klatki obrazu
        if isEneablePic
            figure(keyImage);
            imagesc(I);
            drawnow;
            colormap('gray');
            hold off;
        end

        if isEneablePlot
            % update zmiennych pomocniczych
            vSetIndex = vSetIndex + 1;
           
            % Jesli pozycja nie zostala dodana do trajektorii, dodaj 
            if ~(hasView(vSet,vSetIndex))
                temp = rigidtform3d(camPoses);
                vSet = addView(vSet,vSetIndex,temp);
            end
    
            % Inicjalizacja mapy 3d + trajektorii
            if vSetIndex == 2
                    visualHelper = helperVisualSLAMViewer(xyzPoints,vSet.poses{:,2});
                    visualHelper.Axes.XLimMode = 'auto';
                    visualHelper.Axes.YLimMode = 'auto';
                    visualHelper.Axes.ZLimMode = 'auto';
                    visualHelper.Axes.Children.findobj('Color','r').set('Color','magenta')
                    visualHelper.Axes.Children.findobj('Color','b').set('Color','cyan')
            end
    
            % Jesli trajektoria ma conajmniej 2 pozycje
            if vSetIndex > 1
    
                % Sprawdzanie czy nalezy dodac polaczenie pomiedzy klatkami
                if ~(hasConnection(vSet,vSetIndex-1,vSetIndex))
                    vSet = addConnection(vSet,vSetIndex-1,vSetIndex);
                end
    
                % Update mapy 3d + trajektori jesli aktywna lokalnie
                if isEneablePlot
                    updatePlot(visualHelper,xyzPoints,vSet.poses{:,2});
                end
            end
        end
        %% ros2 - PointCloud
        temp_time = toc;
        czas = ros2time(floor(temp_time),floor((temp_time - floor(temp_time))*1000));

        if size(xyzPoints,1) > 0
            
            % ustawianie czasu wiadomosci
            msgCloud.header.stamp = czas;
            
            % przygotowanie danych do wysylki
            xyzPointsArr = reshape(xyzPoints',[],1);
            xyzPointsArrSingle = single(xyzPointsArr);
            xyzPointsArrUint8 = typecast(xyzPointsArrSingle,'uint8');
            msgCloud.data = xyzPointsArrUint8;
           
            % okreslenie parametrow wysylanych danych
            msgCloud.width = uint32(size(xyzPoints,1));
            msgCloud.row_step = uint32(numel(xyzPointsArrUint8));
            
            % wysylanie wiadomosci
            send(pubCloud,msgCloud)
        end

        %% ros2 - Camera Marker
        % ustawienia headera 
        msgMarker.header.stamp = czas;
        
        % zmienne pomocniczne 
        tempPoseSe3 = se3(camPoses);
        tempQuat = tempPoseSe3.xyzquat;

        % pozycja kamery
        msgMarker.pose.position.x = tempQuat(1);
        msgMarker.pose.position.y = tempQuat(2);
        msgMarker.pose.position.z = tempQuat(3);

        % orientacja kamery za pomoca quaternionu
        msgMarker.pose.orientation.w = tempQuat(4);
        msgMarker.pose.orientation.x = tempQuat(5);
        msgMarker.pose.orientation.y = tempQuat(6);
        msgMarker.pose.orientation.z = tempQuat(7);

        send(pubMarker, msgMarker)

        %% ros2 - Path
        % zmienna pomocnicza
        tempMsg = ros2message('geometry_msgs/PoseStamped');

        % ustawienia headera 
        tempMsg.header.frame_id = 'map';
        tempMsg.header.stamp = czas;
        msgPath.header.frame_id = 'map';
        msgPath.header.stamp = czas;

        % pozycja kamery
        tempMsg.pose.position.x = tempQuat(1);
        tempMsg.pose.position.y = tempQuat(2);
        tempMsg.pose.position.z = tempQuat(3);

        % orientacja kamery za pomoca quaternionu
        tempMsg.pose.orientation.w = tempQuat(4);
        tempMsg.pose.orientation.x = tempQuat(5);
        tempMsg.pose.orientation.y = tempQuat(6);
        tempMsg.pose.orientation.z = tempQuat(7);
        
        %dodowanie pozycji
        msgPath.poses = [msgPath.poses; tempMsg];

        send(pubPath, msgPath)
        
    end
    %% Informacje stanie algortymu SLAM
    % Status inicjaliztacji mapy
    if ~(isMapInit == isMapInitLast)
        fprintf('======== Map Initializted ========\n Tracking started at %d Frame\n', FrameId);
        isMapInitLast = true;
    end

    % status przetwarzanych klatek
    switch status
        case 0 
            fprintf('%d ,Tracking lost\n', FrameId);
        case 1
            fprintf('%d ,TrackingSuccessful\n', FrameId);
        case 2
            fprintf('%d ,FrequentKeyFrames\n', FrameId);
    end
end
%% Koniec datasetu 
fprintf('Czas trwania algorytmu: %f \n',toc);
isStop = true;

% pobranie pelnej informacji
[xyzPoints, camPoses, status ] = waitCodegen_mex720(I,imageSize,principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels, scaleFactor, verbose,trackFeatureRange,loopClosureThreshold,isStop );

% przygotowanie danych do wyswietlania lokalnie jesli potrzbne
if isEneablePlot || isEneablePlotAtEnd
      for k = 1:numel(camPoses)/16
                temp = rigidtform3d([camPoses(4*k-3,1), camPoses(4*k-3,2), camPoses(4*k-3,3), camPoses(4*k-3,4); ...
                                     camPoses(4*k-2,1), camPoses(4*k-2,2), camPoses(4*k-2,3), camPoses(4*k-2,4); ...
                                     camPoses(4*k-1,1), camPoses(4*k-1,2), camPoses(4*k-1,3), camPoses(4*k-1,4); ...
                                     camPoses(4*k,1), camPoses(4*k,2), camPoses(4*k,3), camPoses(4*k,4);]);
                if hasView(vSet,k)
                    vSet = updateView(vSet,k,temp);
                else
                    vSet = addView(vSet,k,temp);
                end
                if k > 1
                    if hasConnection(vSet,k-1,k)
                        vSet = updateConnection(vSet,k-1,k);
                    else
                        vSet = addConnection(vSet,k-1,k);
                    end
                end
    end
end    

% Update mapy po zakonczonym procesie jesli aktywne
if isEneablePlot
    createViewer(visualHelper,xyzPoints,temp,vertcat(vSet.poses{:,2}.Translation));
end

% Wyswietalnie mapy po zakonoczonym procesie jesli aktywne
if isEneablePlotAtEnd && ~isEneablePlot
    visualHelper = helperVisualSLAMViewer(xyzPoints,vSet.poses{:,2});
    visualHelper.Axes.XLimMode = 'auto';
    visualHelper.Axes.YLimMode = 'auto';
    visualHelper.Axes.ZLimMode = 'auto';
    visualHelper.Axes.Children.findobj('Color','r').set('Color','magenta');
    visualHelper.Axes.Children.findobj('Color','b').set('Color','cyan');
end 
%% Ros 2 - Update koncowy algorytmu
temp_time = toc;
czas = ros2time(floor(temp_time),floor((temp_time - floor(temp_time))*1000));

% Tworzenie wiadomosci 
msgCloudEnd = ros2message('sensor_msgs/PointCloud2');
msgCloudEnd.header.frame_id = 'map';

msgCloudEnd.height = uint32(1);
msgCloudEnd.width = uint32(0);
msgCloudEnd.point_step = uint32(12);

% Ustawianie parametrow wiadmosci 
msgCloudEnd.fields(1) = ros2message('sensor_msgs/PointField');
msgCloudEnd.fields(1).name = 'x';
msgCloudEnd.fields(1).offset = uint32(0);
msgCloudEnd.fields(1).datatype = uint8(7);
msgCloudEnd.fields(1).count = uint32(1);

msgCloudEnd.fields(2) = ros2message('sensor_msgs/PointField');
msgCloudEnd.fields(2).name = 'y';
msgCloudEnd.fields(2).offset = uint32(4);
msgCloudEnd.fields(2).datatype = uint8(7);
msgCloudEnd.fields(2).count = uint32(1);

msgCloudEnd.fields(3) = ros2message('sensor_msgs/PointField');
msgCloudEnd.fields(3).name = 'z';
msgCloudEnd.fields(3).offset = uint32(8);
msgCloudEnd.fields(3).datatype = uint8(7);
msgCloudEnd.fields(3).count = uint32(1);

% ustawianie czasu wiadomosci
msgCloudEnd.header.stamp = czas;

% przygotowanie danych do wysylki
xyzPointsArr = reshape(xyzPoints',[],1);
xyzPointsArrSingle = single(xyzPointsArr);
xyzPointsArrUint8 = typecast(xyzPointsArrSingle,'uint8');
msgCloudEnd.data = xyzPointsArrUint8;

% okreslenie parametrow wysylanych danych
msgCloudEnd.width = uint32(size(xyzPoints,1));
msgCloudEnd.row_step = uint32(numel(xyzPointsArrUint8));

% wysylanie wiadomosci
send(pubCloudEnd,msgCloudEnd)

%% Ros 2 - Camera Marker

% Tworzenie wiadomosci
msgMarkerEnd = ros2message('visualization_msgs/Marker');

msgMarkerEnd.header.frame_id = 'map';
msgMarkerEnd.ns = 'map';
msgMarkerEnd.type = int32(3);

% Ustawienie koloru
msgMarkerEnd.scale.x = 0.1;
msgMarkerEnd.scale.y = 0.1;
msgMarkerEnd.scale.z = 0.3;

% Wybranie koloru 
msgMarkerEnd.color.a = single(0.5);
msgMarkerEnd.color.r = single(255);
msgMarkerEnd.color.g = single(0);
msgMarkerEnd.color.b = single(255);

% ustawienia headera 
msgMarkerEnd.header.stamp = czas;

% zmienne pomocniczne
numOfPoses = numel(camPoses)/16;
tempPoseSe3 = se3([camPoses(4*numOfPoses-3,1), camPoses(4*numOfPoses-3,2), camPoses(4*numOfPoses-3,3), camPoses(4*numOfPoses-3,4); ...
                   camPoses(4*numOfPoses-2,1), camPoses(4*numOfPoses-2,2), camPoses(4*numOfPoses-2,3), camPoses(4*numOfPoses-2,4); ...
                   camPoses(4*numOfPoses-1,1), camPoses(4*numOfPoses-1,2), camPoses(4*numOfPoses-1,3), camPoses(4*numOfPoses-1,4); ...
                   camPoses(4*numOfPoses,1), camPoses(4*numOfPoses,2), camPoses(4*numOfPoses,3), camPoses(4*numOfPoses,4);]);
tempQuat = tempPoseSe3.xyzquat;

% pozycja kamery
msgMarkerEnd.pose.position.x = tempQuat(1);
msgMarkerEnd.pose.position.y = tempQuat(2);
msgMarkerEnd.pose.position.z = tempQuat(3);

% orientacja kamery za pomoca quaternionu
msgMarkerEnd.pose.orientation.w = tempQuat(4);
msgMarkerEnd.pose.orientation.x = tempQuat(5);
msgMarkerEnd.pose.orientation.y = tempQuat(6);
msgMarkerEnd.pose.orientation.z = tempQuat(7);

send(pubMarkerEnd, msgMarkerEnd)

%% Ros2 - Path

% Tworzenie wiadomosci
msgPathEnd = ros2message('nav_msgs/Path');
msgPathEnd.header.frame_id = 'map';
msgPathEnd.poses = [];

% header
msgPathEnd.header.frame_id = 'map';
msgPathEnd.header.stamp = czas;

% zmienna pomocnicza
tempPathPoses = [];

for k = 1:numOfPoses
    tempPoseSe3 = se3([camPoses(4*k-3,1), camPoses(4*k-3,2), camPoses(4*k-3,3), camPoses(4*k-3,4); ...
                         camPoses(4*k-2,1), camPoses(4*k-2,2), camPoses(4*k-2,3), camPoses(4*k-2,4); ...
                         camPoses(4*k-1,1), camPoses(4*k-1,2), camPoses(4*k-1,3), camPoses(4*k-1,4); ...
                         camPoses(4*k,1), camPoses(4*k,2), camPoses(4*k,3), camPoses(4*k,4);]);
    
    tempQuat = tempPoseSe3.xyzquat;
    tempMsg = ros2message('geometry_msgs/PoseStamped');
    
    % ustawienia headera 
    tempMsg.header.frame_id = 'map';
    tempMsg.header.stamp = czas;
    
    % pozycja kamery
    tempMsg.pose.position.x = tempQuat(1);
    tempMsg.pose.position.y = tempQuat(2);
    tempMsg.pose.position.z = tempQuat(3);
    
    % orientacja kamery za pomoca quaternionu
    tempMsg.pose.orientation.w = tempQuat(4);
    tempMsg.pose.orientation.x = tempQuat(5);
    tempMsg.pose.orientation.y = tempQuat(6);
    tempMsg.pose.orientation.z = tempQuat(7);
    
    %dodowanie pozycji
    tempPathPoses = [tempPathPoses; tempMsg];
end

%dodowanie trajektorii
msgPathEnd.poses = tempPathPoses;

send(pubPathEnd, msgPathEnd)

%% wylaczenie rosa2
fprintf('Czas trwania programu: %f \n',toc);
rosshutdown
clear cam
%% funkcja pomocnicza do stopu przyciskiem q jesli jest podglad lokalny
function keyPressCallback(~, event)
    if strcmp(event.Key, 'q')
       assignin('base', 'isStop', true);
        fprintf('Naciśnięto klawisz "q". Kończenie pętli... \n');% Zamknięcie okna figure
    end
end
