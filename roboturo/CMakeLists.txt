cmake_minimum_required(VERSION 3.5)
project(roboturo)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# Add the executable for move_robot
add_executable(move_robot src/move_robot.cpp)

# Link dependencies for the executable
ament_target_dependencies(move_robot rclcpp geometry_msgs)

# Install the executable
install(TARGETS
  move_robot
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()