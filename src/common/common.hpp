#ifndef ROBOT_APP_COMMON_COMMON_HPP_
#define ROBOT_APP_COMMON_COMMON_HPP_

// logger setting
#define ROBOT_APP_LOGGER_NAME "robot_app"

#define ROBOT_APP_LOGGER_LOGGER_ERROR_FILENAME "logs/robot_app_error.log"
#define ROBOT_APP_LOGGER_LOGGER_TRACE_FILENAME "logs/robot_app_trace.log"

#define ROBOT_APP_LOGGER_PATTERN "[%Y-%m-%d %H:%M:%S.%e][%^%l%$][%t][%s:%#] %v"
#define ROBOT_APP_LOGGER_ROTATING_MAX_FILE_SIZE (1024*1024)
#define ROBOT_APP_LOGGER_ROTATING_MAX_FILE_NUM 5

#endif

