% Inicjalizacja ROS2 node w Matlabie
clear;
%ros2snd = ros2node('/matlab_snd',0);
%ros2rcv = ros2node('/matlab_rcv',0);
% Subskrybowanie tematu obrazu
%imageSnd = ros2publisher(ros2snd,'/selftest', 'sensor_msgs/PointCloud')
% Create a PointCloud2 message
msg = ros2message('sensor_msgs/PointCloud2');

% Set header
msg.header.stamp = rostime('now', 'DataFormat', 'struct');
msg.header.frame_id = 'map';

% Set point cloud fields
msg.height = 1;
msg.width = size(points, 1);
msg.is_dense = true;
msg.is_bigendian = false;
msg.point_step = 12;  % Each point has 3 float32 fields (x, y, z)
msg.row_step = msg.point_step * msg.width;

% Define PointField for x, y, z
fields = ros2message('sensor_msgs/PointField', 3);
fields(1).name = 'x';
fields(1).offset = 0;
fields(1).datatype = 7;  % FLOAT32
fields(1).count = 1;

fields(2).name = 'y';
fields(2).offset = 4;
fields(2).datatype = 7;  % FLOAT32
fields(2).count = 1;

fields(3).name = 'z';
fields(3).offset = 8;
fields(3).datatype = 7;  % FLOAT32
fields(3).count = 1;

msg.fields = fields;

% Convert points to uint8 array and assign to msg.data
msg.data = reshape(typecast(points', 'uint8'), 1, []);

% Publish the message
send(publisher, msg);

disp('PointCloud2 message published.');