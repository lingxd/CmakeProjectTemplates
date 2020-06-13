#include <iostream>

#include "common/common.hpp"
#include "logger/logger.hpp"

void LoggerInit() {
    RobotAppSpdlogSetLevel(ROBOT_APP_SPDLOG_LEVEL_TRACE);
    RobotAppSpdlogSetPattern(ROBOT_APP_LOGGER_PATTERN);
    RobotAppSpdlogRotatingLoggerMt(ROBOT_APP_LOGGER_NAME,
            ROBOT_APP_LOGGER_LOGGER_TRACE_FILENAME,
            ROBOT_APP_LOGGER_ROTATING_MAX_FILE_SIZE,
            ROBOT_APP_LOGGER_ROTATING_MAX_FILE_NUM);
}

int main(int argc, char* argv[]) {
    // only for rotaing
    //LoggerInit();

    // creating loggers with multiple sinks
    // default level is trace
    RobotAppSpdlogCombinedLoggerInit(true, true, true, true);
    //RobotAppSpdlogCombinedLoggerSetLevel(ROBOT_APP_SPDLOG_LEVEL_TRACE);
    auto file_logger = RobotAppSpdlogGet(ROBOT_APP_LOGGER_NAME);

    // testing
    ROBOT_APP_SPDLOG_LOGGER_TRACE(file_logger, "hello, world! {}", 2020);
    ROBOT_APP_SPDLOG_LOGGER_DEBUG(file_logger, "hello, world! {}", 2020);
    ROBOT_APP_SPDLOG_LOGGER_INFO(file_logger, "hello, world! {}", 2020);
    ROBOT_APP_SPDLOG_LOGGER_WARN(file_logger, "hello, world! {}", 2020);
    ROBOT_APP_SPDLOG_LOGGER_ERROR(file_logger, "hello, world! {}", 2020);
    // drop logger
    RobotAppSpdlogDrop();

    return 0;
}

