CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# compiler configuration
INCLUDE(${PROJECT_SOURCE_DIR}/cmake/toolchain_options.cmake)

INCLUDE_DIRECTORIES(
    ./
    ${SPDLOG_INCLUDE_DIR}
    ${LIBZMQ_INCLUDE_DIR}
    ${SERIAL_INCLUDE_DIR}
    ${COMMON_INCLUDE_DIR}
)

LINK_DIRECTORIES(
    ${SPDLOG_LIBRARY_DIR}
    ${LIBZMQ_LIBRARY_DIR}
    ${SERIAL_LIBRARY_DIR}
    ${COMMON_LIBRARY_DIR}
)

# submodule
ADD_SUBDIRECTORY(common)
ADD_SUBDIRECTORY(logger)

# main app                                                                      
SET(SRC_LIST ./main/main.cpp)                                                   
MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
ADD_EXECUTABLE(RobotCleanState ${SRC_LIST})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
TARGET_LINK_LIBRARIES(RobotCleanState
            ${SPDLOG_LIBS}
            ${LIBZMQ_LIBS}
            ${SERIAL_LIBS}
            module_logger
        )

INSTALL(TARGETS RobotCleanState
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)
