% Inicjalizacja węzła ROS 2
node = ros2node('/vSlam');
topicName = "macierz_trans";
messageType = "std_msgs/Float64MultiArray";
pub = ros2publisher(node, topicName, messageType);

topicName2 = "xyz_data1";
messageType2 = "std_msgs/Float64MultiArray";
pub2 = ros2publisher(node, topicName2, messageType2);

while true
    % Publikowanie
    %msg.data = reshape(camPoses(i).A, 1, []);
    send_ROS(xyzPoints, pub2, camPoses, pub)
    pause(0.01);
    break;
end