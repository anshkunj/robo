// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/Position.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robot_interfaces/msg/position.hpp"


#ifndef ROBOT_INTERFACES__MSG__DETAIL__POSITION__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Position_z
{
public:
  explicit Init_Position_z(::robot_interfaces::msg::Position & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::Position z(::robot_interfaces::msg::Position::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::Position msg_;
};

class Init_Position_y
{
public:
  explicit Init_Position_y(::robot_interfaces::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_z y(::robot_interfaces::msg::Position::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Position_z(msg_);
  }

private:
  ::robot_interfaces::msg::Position msg_;
};

class Init_Position_x
{
public:
  Init_Position_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_y x(::robot_interfaces::msg::Position::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Position_y(msg_);
  }

private:
  ::robot_interfaces::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::Position>()
{
  return robot_interfaces::msg::builder::Init_Position_x();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__POSITION__BUILDER_HPP_
