cmake_minimum_required(VERSION 3.20)
project(robot_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)

# Generate Messages
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/RobotState.msg"
  "msg/BatteryState.msg"
  "msg/Task.msg"
  "msg/Shelf.msg"
  "msg/InventoryItem.msg"
  "msg/DetectedObject.msg"
  "srv/GetRobotState.srv"
  "srv/OpenGripper.srv"

  DEPENDENCIES
      geometry_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)

  ament_lint_auto_find_test_dependencies()
endif()

ament_package()