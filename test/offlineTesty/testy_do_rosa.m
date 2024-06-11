% Tworzenie węzła ROS
node = ros2node('/my_node');

% Tworzenie wydawcy wiadomości PointCloud2
pub = ros2publisher(node, '/my_topic', 'sensor_msgs/PointCloud2');
pubPose = ros2publisher(node, '/path', 'visualization_msgs/Marker');

% Tworzenie wiadomości PointCloud2
msgCloud = ros2message('sensor_msgs/PointCloud2');
msgPose = ros2message('visualization_msgs/Marker');

% Ustawianie nagłówków wiadomości
msgCloud.header.frame_id = 'base_link';
msgCloud.header.stamp = ros2time(node,"now");

% Ustawianie rozmiaru macierzy punktów
numPoints = size(xyzPoints, 1);
msgCloud.height = uint32(1);
msgCloud.width = uint32(numPoints);

% Tworzenie struktury pola danych
msgCloud.fields(1) = ros2message('sensor_msgs/PointField');
msgCloud.fields(1).name = 'x';
msgCloud.fields(1).offset = uint32(0);
msgCloud.fields(1).datatype = field1.FLOAT32;
msgCloud.fields(1).count = uint32(1);

msgCloud.fields(2) = ros2message('sensor_msgs/PointField');
msgCloud.fields(2).name = 'y';
msgCloud.fields(2).offset = uint32(4);
msgCloud.fields(2).datatype = field2.FLOAT32;
msgCloud.fields(2).count = uint32(1);

msgCloud.fields(3) = ros2message('sensor_msgs/PointField');
msgCloud.fields(3).name = 'z';
msgCloud.fields(3).offset = uint32(8);
msgCloud.fields(3).datatype = field3.FLOAT32;
msgCloud.fields(3).count = uint32(1);

msgCloud.fields = [field1, field2, field3];

% Konwersja macierzy punktów na pojedynczy wektor
points = reshape(xyzPoints', 1, []);

% Ustawianie danych punktów w wiadomości
msgCloud.data = typecast(single(points), 'uint8');

% Publikowanie wiadomości
send(pub, msgCloud);

% Zamykanie węzła ROS
% ros2shutdown
