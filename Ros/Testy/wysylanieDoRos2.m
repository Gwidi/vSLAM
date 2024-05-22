% Inicjalizacja ROS2

% Tworzenie węzła ROS2
%node = ros2node('/camera_node',0);

% Tworzenie wydawcy ROS2
%publisher = ros2publisher(node, '/camera_data', 'sensor_msgs/Image');

% Inicjalizacja kamery
camera = webcam;
principalPoint=[644.5,355.6];
focalLength=[983.4,989.3];
imageSize=[720,1280];
intrinsics=cameraIntrinsics(focalLength,principalPoint,imageSize);


while true
    % Pobieranie obrazu z kamery
    img = snapshot(camera);
    %img = undistortImage(img, intrinsics);
    % Konwersja obrazu na skalę szarości
    gray_img = rgb2gray(img);
    
    % Tworzenie wiadomości ROS2
    msg = ros2message('sensor_msgs/Image');
    msg.Encoding = 'mono8';
    msg.Height = size(gray_img, 1);
    msg.Width = size(gray_img, 2);
    msg.Step = size(gray_img, 2);
    msg.Data = reshape(gray_img', 1, []);
    
    % Publikowanie wiadomości ROS2
    send(publisher, msg);
    
    % Oczekiwanie na kolejną klatkę
    pause(10);
end

% Zamykanie kamery
clear camera;

% Zamykanie węzła ROS2
ros2node('destroy');