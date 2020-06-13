#ifndef ROBOT_APP_LOGGER_LOGGER_HPP_
#define ROBOT_APP_LOGGER_LOGGER_HPP_


#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "spdlog/spdlog.h"

// You can define SPDLOG_ACTIVE_LEVEL to the desired log level before including "spdlog.h".
// This will turn on/off logging statements at compile time

#define ROBOT_APP_SPDLOG_LEVEL_TRACE 0
#define ROBOT_APP_SPDLOG_LEVEL_DEBUG 1
#define ROBOT_APP_SPDLOG_LEVEL_INFO 2
#define ROBOT_APP_SPDLOG_LEVEL_WARN 3
#define ROBOT_APP_SPDLOG_LEVEL_ERROR 4
#define ROBOT_APP_SPDLOG_LEVEL_CRITI 5
#define ROBOT_APP_SPDLOG_LEVEL_OFF 6

#define ROBOT_APP_SPDLOG_LOGGER_TRACE(logger, ...) SPDLOG_LOGGER_TRACE(logger, __VA_ARGS__)
#define ROBOT_APP_SPDLOG_LOGGER_DEBUG(logger, ...) SPDLOG_LOGGER_DEBUG(logger, __VA_ARGS__)
#define ROBOT_APP_SPDLOG_LOGGER_INFO(logger, ...) SPDLOG_LOGGER_INFO(logger, __VA_ARGS__)
#define ROBOT_APP_SPDLOG_LOGGER_WARN(logger, ...) SPDLOG_LOGGER_WARN(logger, __VA_ARGS__)
#define ROBOT_APP_SPDLOG_LOGGER_ERROR(logger, ...) SPDLOG_LOGGER_ERROR(logger, __VA_ARGS__)
#define ROBOT_APP_SPDLOG_LOGGER_CRITICAL(logger, ...) SPDLOG_LOGGER_CRITICAL(logger, __VA_ARGS__)

#ifdef __cplusplus
    extern "C" {
#endif

// if logger with such name exists, will return 1, else will return 0
std::shared_ptr<spdlog::logger> RobotAppSpdlogGet(const char* logger_name);

// set global formatting
// detail see https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
// example: spdlog::set_pattern("%Y-%m-%d %H:%M:%S.%e %l : %v");
void RobotAppSpdlogSetPattern(const char* format_string);

// set global logging level
void RobotAppSpdlogSetLevel(int log_level);

// second
void RobotAppSpdlogSetFlushEvery(int interval);

// create and register multi/single threaded rotating file logger
void RobotAppSpdlogRotatingLoggerMt(const char* logger_name,
        const char* filename, size_t max_file_size, size_t max_files);

// create file logger which creates new file on the given time
// (default in  midnight)
void RobotAppSpdlogDailyLoggerMt(const char* logger_name,
        const char* filename, int hour, int minute);

// creating loggers with multiple sinks
void RobotAppSpdlogCombinedLoggerInit(
        const bool with_color_console,
        const bool with_console,
        const bool with_error,
        const bool with_trace);

void RobotAppSpdlogCombinedLoggerSetLevel(int log_level);

void RobotAppSpdlogCombinedLoggerSetPattern(const char* format_string);

// drop all loggers reference while you don't use the logger
void RobotAppSpdlogDrop();

#ifdef __cplusplus
    }
#endif

#endif

