% Inicjalizacja ROS2 node w Matlabie
clear;
ros2snd = ros2node('/matlab_snd',0);
ros2rcv = ros2node('/matlab_rcv',0);
% Subskrybowanie tematu obrazu
imageSnd = ros2publisher(ros2snd,'/selftest', 'sensor_msgs/Image',"History",'keeplast','Depth',30,'Reliability','besteffort','Durability','transientlocal')
% imageRcv = ros2subscriber(ros2rcv, '/selftest', 'sensor_msgs/Image', @testHelperRos2);
cam = webcam;
% Ustawienia wiadomości
img_msg = ros2message('sensor_msgs/Image');
img_msg.encoding = 'mono8';
img_msg.is_bigendian = uint8(0);
img = snapshot(cam);img = snapshot(cam);
img = snapshot(cam);
img_msg.height = uint32(size(img, 1));
img_msg.width = uint32(size(img, 2));
img_msg.step = uint32(size(img, 2));
global imgArr

f1 = figure;
% f2 = figure;
while true
tic
% Przechwyć obraz z kamery
img = snapshot(cam);
img = rgb2gray(img);
figure(f1);
imshow(img);
% Ustaw parametry obrazu w wiadomości ROS
 % Jeden kanał dla obrazu w skali szarości

% Zmiana kształtu obrazu
% img_reshaped = img'; % Transpozycja obrazu, aby dostosować do układu danych ROS
img_msg = rosWriteImage(img_msg,img);

% Publikacja obrazu
send(imageSnd, img_msg);
disp('wysłano');

    % Opcjonalnie: dodaj krótką przerwę, żeby uniknąć zbyt dużej ilości danych
    % przerwa 100 ms
% 
% [imgMsg,status,statustext] = receive(imageRcv, 60);
%    disp('odebrano');
% % Przetwarzanie danych obrazu
% imgData = imgMsg.data;
% width = imgMsg.width;
% height = imgMsg.height;
% step = imgMsg.step;
% 
% % Przykład dla obrazu RGB
% imageArray = reshape(imgData, [step, height]);
% imageArray = imageArray(1:3*width, :); % Wybierz tylko dane obrazu
% imageArray = permute(reshape(imageArray, [3, width, height]), [3, 2, 1]);
% 
% % Wyświetlenie obrazu
% figure(f2);
% imshow(imgArr);
toc
end