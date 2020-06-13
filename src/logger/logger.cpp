#include "logger/logger.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <mutex>

#include "spdlog/sinks/basic_file_sink.h"       // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h"    // support for rotating file logging
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"

#include "common/common.hpp"

// if logger with such name exists, will return 1, else will return 0
std::shared_ptr<spdlog::logger> RobotAppSpdlogGet(const char* logger_name) {
    static std::shared_ptr<spdlog::logger> logger_ptr = nullptr;
    static std::mutex mutex;

    std::lock_guard<std::mutex> guard(mutex);

    if (!logger_ptr) {
        logger_ptr = spdlog::get(logger_name);
    }

    return (logger_ptr != nullptr) ? logger_ptr : nullptr;
}

// set global formatting
// example: spdlog::set_pattern("%Y-%m-%d %H:%M:%S.%e %l : %v");
void RobotAppSpdlogSetPattern(const char* format_string) {
    spdlog::set_pattern(format_string);
}

// set global logging level
void RobotAppSpdlogSetLevel(int log_level) {
    spdlog::set_level(static_cast<spdlog::level::level_enum>(log_level));
}

void RobotAppSpdlogSetFlushEvery(int interval) {
    spdlog::flush_every(std::chrono::seconds(interval));
}

// create and register multi/single threaded rotating file logger
void RobotAppSpdlogRotatingLoggerMt(const char* logger_name,
        const char* filename, size_t max_file_size, size_t max_files) {
    auto logger = spdlog::rotating_logger_mt(logger_name, filename, max_file_size, max_files);
}

// create file logger which creates new file on the given time
// (default in  midnight)
void RobotAppSpdlogDailyLoggerMt(const char* logger_name,
        const char* filename, int hour, int minute) {
    auto logger = spdlog::daily_logger_mt(logger_name, filename, hour, minute);
}

void RobotAppSpdlogCombinedLoggerInit(
        const bool with_color_console,
        const bool with_console,
        const bool with_error,
        const bool with_trace) {
    std::vector<spdlog::sink_ptr> sinks;

    if (with_color_console) {
        auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        sink->set_level(spdlog::level::trace);
        //sink->set_pattern(ROBOT_APP_LOGGER_PATTERN);
        sinks.push_back(sink);
    } else if (with_console) {
        auto sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
        sink->set_level(spdlog::level::trace);
        //sink->set_pattern(ROBOT_APP_LOGGER_PATTERN);
        sinks.push_back(sink);
    }

    if (with_error) {
        auto with_error_logger_rotating = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
                    ROBOT_APP_LOGGER_LOGGER_ERROR_FILENAME,
                    ROBOT_APP_LOGGER_ROTATING_MAX_FILE_SIZE,
                    ROBOT_APP_LOGGER_ROTATING_MAX_FILE_NUM);
        with_error_logger_rotating->set_level(spdlog::level::err);
        //with_error_logger_rotating->set_pattern(ROBOT_APP_LOGGER_PATTERN);
        sinks.push_back(with_error_logger_rotating);
    }

    if (with_trace) {
        auto with_trace_logger_rotating = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
                    ROBOT_APP_LOGGER_LOGGER_TRACE_FILENAME,
                    ROBOT_APP_LOGGER_ROTATING_MAX_FILE_SIZE,
                    ROBOT_APP_LOGGER_ROTATING_MAX_FILE_NUM);
        with_trace_logger_rotating->set_level(spdlog::level::trace);
        //with_trace_logger_rotating->set_pattern(ROBOT_APP_LOGGER_PATTERN);
        sinks.push_back(with_trace_logger_rotating);
    }

    auto combined_logger = std::make_shared<spdlog::logger>(ROBOT_APP_LOGGER_NAME,
            begin(sinks), end(sinks));
    // register it if you need to access it globally
    // set_level will limit all sinks
    combined_logger->set_level(spdlog::level::trace);
    combined_logger->set_pattern(ROBOT_APP_LOGGER_PATTERN);
    spdlog::register_logger(combined_logger);

    // set flush every 5 seconds
    RobotAppSpdlogSetFlushEvery(5);
}

void RobotAppSpdlogCombinedLoggerSetLevel(int log_level) {
    auto combined_logger = RobotAppSpdlogGet(ROBOT_APP_LOGGER_NAME);
    if (!combined_logger) {
        std::cerr << "Failed to get combined logger, please check!" << std::endl;
    }

    combined_logger->set_level(static_cast<spdlog::level::level_enum>(log_level));
}

void RobotAppSpdlogCombinedLoggerSetPattern(const char* format_string) {
    auto combined_logger = RobotAppSpdlogGet(ROBOT_APP_LOGGER_NAME);
    if (!combined_logger) {
        std::cerr << "Failed to get combined logger, please check!" << std::endl;
    }

    combined_logger->set_pattern(format_string);
}

// drop all loggers reference
void RobotAppSpdlogDrop() {
    spdlog::drop_all();
}

