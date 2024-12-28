from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.actions import ExecuteProcess
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    urdf_path = os.path.join(get_package_share_directory('roboturo'), 'urdf', 'robo.urdf')  
    if not os.path.exists(urdf_path):
        raise FileNotFoundError(f"URDF file not found: {urdf_path}")

    return LaunchDescription([
        ExecuteProcess(
            cmd=['gazebo', '--verbose', '-s', 'libgazebo_ros_factory.so'],
            output='screen'
        ),
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=['-entity', 'robot_uro', '-file', urdf_path],
            output='screen'
        ),
    ])
# ros2 launch roboturo robot_launch.py urdf_path:=/home/tukanglas/tubes_uro/workspace/src/SEKURO17_TubesProg/roboturo/urdf/robo.urdf