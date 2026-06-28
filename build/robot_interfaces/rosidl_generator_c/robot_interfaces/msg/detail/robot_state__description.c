// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robot_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice

#include "robot_interfaces/msg/detail/robot_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robot_interfaces
const rosidl_type_hash_t *
robot_interfaces__msg__RobotState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x77, 0x76, 0x0c, 0x78, 0x39, 0xc5, 0x14, 0x1a,
      0x33, 0x48, 0xec, 0x28, 0x13, 0x97, 0x50, 0x62,
      0x79, 0x1e, 0x67, 0x69, 0xaf, 0xa5, 0x89, 0x1a,
      0x9d, 0x75, 0x96, 0x9a, 0x2d, 0x50, 0x0c, 0x2a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "robot_interfaces/msg/detail/position__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t robot_interfaces__msg__Position__EXPECTED_HASH = {1, {
    0x0d, 0x6b, 0x47, 0x68, 0x00, 0x5f, 0xb2, 0xe1,
    0x43, 0xca, 0x1e, 0x67, 0xf7, 0xb7, 0x22, 0x6e,
    0x3e, 0xb9, 0x70, 0xa9, 0x73, 0x53, 0x9b, 0x9d,
    0x37, 0x53, 0xd9, 0xb0, 0xf9, 0xfd, 0x7b, 0xac,
  }};
#endif

static char robot_interfaces__msg__RobotState__TYPE_NAME[] = "robot_interfaces/msg/RobotState";
static char robot_interfaces__msg__Position__TYPE_NAME[] = "robot_interfaces/msg/Position";

// Define type names, field names, and default values
static char robot_interfaces__msg__RobotState__FIELD_NAME__position[] = "position";
static char robot_interfaces__msg__RobotState__FIELD_NAME__battery[] = "battery";

static rosidl_runtime_c__type_description__Field robot_interfaces__msg__RobotState__FIELDS[] = {
  {
    {robot_interfaces__msg__RobotState__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robot_interfaces__msg__Position__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {robot_interfaces__msg__RobotState__FIELD_NAME__battery, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robot_interfaces__msg__RobotState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {robot_interfaces__msg__Position__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robot_interfaces__msg__RobotState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robot_interfaces__msg__RobotState__TYPE_NAME, 31, 31},
      {robot_interfaces__msg__RobotState__FIELDS, 2, 2},
    },
    {robot_interfaces__msg__RobotState__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&robot_interfaces__msg__Position__EXPECTED_HASH, robot_interfaces__msg__Position__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = robot_interfaces__msg__Position__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "Position position\n"
  "float32 battery";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robot_interfaces__msg__RobotState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robot_interfaces__msg__RobotState__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 33, 33},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robot_interfaces__msg__RobotState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robot_interfaces__msg__RobotState__get_individual_type_description_source(NULL),
    sources[1] = *robot_interfaces__msg__Position__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
