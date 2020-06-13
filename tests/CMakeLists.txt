CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
# compiler configuration

INCLUDE(${PROJECT_SOURCE_DIR}/cmake/toolchain_options.cmake)

PROJECT(Tests)

INCLUDE_DIRECTORIES(
    ${SPDLOG_INCLUDE_DIR}
    ${LIBZMQ_INCLUDE_DIR}
    ${SERIAL_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

LINK_DIRECTORIES(
    ${SPDLOG_LIBRARY_DIR}
    ${LIBZMQ_LIBRARY_DIR}
    ${SERIAL_LIBRARY_DIR}
)

FILE(GLOB APP_SOURCES *.cpp)
FOREACH(testsourcefile ${APP_SOURCES})
    STRING(REGEX MATCH "[^/]+$" testsourcefilewithoutpath ${testsourcefile})
    STRING(REPLACE ".cpp" "" testname ${testsourcefilewithoutpath})
    ADD_EXECUTABLE( ${testname} ${testsourcefile})
    SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests)
    TARGET_LINK_LIBRARIES(${testname}
        ${SPDLOG_LIBS}
        ${LIBZMQ_LIBS}
        ${SERIAL_LIBS}
        module_logger
        )

    INSTALL(TARGETS ${testname}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
ENDFOREACH(testsourcefile ${APP_SOURCES})
