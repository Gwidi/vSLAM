import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
import numpy as np
import open3d as o3d

class VisualizerNode(Node):

    def __init__(self):
        super().__init__('visualizer_node')
        self.subscription = self.create_subscription(
            Float64MultiArray,
            '/visualizePoints',
            self.listener_callback,
            10)
        self.subscription
        self.viewer = o3d.visualization.Visualizer()
        self.viewer.create_window()

    def listener_callback(self, msg):
        data = np.array(msg.data).reshape(-1, 3)
        offset = msg.layout.dim[0].size * 4

        cam_poses_r = data[:offset, :]
        xyz_points = data[offset:, :]

        cam_poses = []
        for i in range(msg.layout.dim[0].size):
            R = cam_poses_r[i*4+1:i*4+4, :]
            T = cam_poses_r[i*4, :]
            transform = np.eye(4)
            transform[:3, :3] = R
            transform[:3, 3] = T
            cam_poses.append(transform)

        self.visualize(xyz_points, cam_poses)

    def visualize(self, xyz_points, cam_poses):
        self.viewer.clear_geometries()
        
        # Wizualizacja punktów
        pcd = o3d.geometry.PointCloud()
        pcd.points = o3d.utility.Vector3dVector(xyz_points)
        self.viewer.add_geometry(pcd)
        
        # Wizualizacja pozycji kamer (np. jako osie)
        for pose in cam_poses:
            axis = o3d.geometry.TriangleMesh.create_coordinate_frame(size=0.1)
            axis.transform(pose)
            self.viewer.add_geometry(axis)
        
        self.viewer.poll_events()
        self.viewer.update_renderer()

def main(args=None):
    rclpy.init(args=args)
    visualizer_node = VisualizerNode()
    rclpy.spin(visualizer_node)
    visualizer_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
