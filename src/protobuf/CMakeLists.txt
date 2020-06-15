CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Find required protobuf package
find_package(Protobuf REQUIRED)
if(PROTOBUF_FOUND)
    message(STATUS "protobuf library found")
else()
    message(FATAL_ERROR "protobuf library is needed but cant be found")
endif()


## protobuf
PROTOBUF_GENERATE_CPP(
        PROTO_SRCS
        PROTO_HDRS
        ${CMAKE_CURRENT_LIST_DIR}/RangeSensorMsg.proto
        ${CMAKE_CURRENT_LIST_DIR}/CliffSensorMsg.proto
        ${CMAKE_CURRENT_LIST_DIR}/PlanMsgToState.proto
        ${CMAKE_CURRENT_LIST_DIR}/STM32MsgToCostMap.proto
        ${CMAKE_CURRENT_LIST_DIR}/StateMachineMsgToAll.proto
        ${CMAKE_CURRENT_LIST_DIR}/StateMsgToPlan.proto
        ${CMAKE_CURRENT_LIST_DIR}/Stm32ToState.proto
        ${CMAKE_CURRENT_LIST_DIR}/Bmi160ToData.proto
        ${CMAKE_CURRENT_LIST_DIR}/IMUMessage.proto
        ${CMAKE_CURRENT_LIST_DIR}/Vector3d.proto
        ${CMAKE_CURRENT_LIST_DIR}/RobotPose.proto
        )
