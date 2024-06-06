% Inicjalizacja węzła ROS 2
node = ros2node('/vSlam');
topicName = "macierz_trans";
messageType = "sensor_msgs/";
pub = ros2publisher(node, topicName, messageType);

topicName2 = "xyz_data1";
messageType2 = "sensor_msgs/PointCloud";
pub2 = ros2publisher(node, topicName2, messageType2);

while true
    % Publikowanie
    %msg.data = reshape(camPoses(i).A, 1, []);
    send_ROS(xyzPoints, pub2, camPoses, pub)
    break;
end