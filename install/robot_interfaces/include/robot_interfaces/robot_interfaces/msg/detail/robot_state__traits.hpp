// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robot_interfaces/msg/robot_state.hpp"


#ifndef ROBOT_INTERFACES__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "robot_interfaces/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "robot_interfaces/msg/detail/position__traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: battery
  {
    out << "battery: ";
    rosidl_generator_traits::value_to_yaml(msg.battery, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: battery
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery: ";
    rosidl_generator_traits::value_to_yaml(msg.battery, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, robot_interfaces::msg::RobotState>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).position,
    std::forward<T>(msg).battery);
}

}  // namespace msg

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<robot_interfaces::msg::RobotState>()
{
  return "robot_interfaces::msg::RobotState";
}

template<>
constexpr const char * name<robot_interfaces::msg::RobotState>()
{
  return "robot_interfaces/msg/RobotState";
}

template<>
struct has_fixed_size<robot_interfaces::msg::RobotState>
  : std::integral_constant<bool, has_fixed_size<robot_interfaces::msg::Position>::value> {};

template<>
struct has_bounded_size<robot_interfaces::msg::RobotState>
  : std::integral_constant<bool, has_bounded_size<robot_interfaces::msg::Position>::value> {};

template<>
struct is_message<robot_interfaces::msg::RobotState>
  : std::true_type {};

template<>
struct MessageTraits<robot_interfaces::msg::RobotState>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "position",
    "battery",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
