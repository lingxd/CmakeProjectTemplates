# shellcheck disable=SC1127
# $SRC_DIR: .proto 所在的源目录
# --cpp_out: 生成 c++ 代码
# $DST_DIR: 生成代码的目标目录
# xxx.proto: 要针对哪个 proto 文件生成接口代码


protoc -I=./ --cpp_out=./ ./CliffSensorMsg.proto
protoc -I=./ --cpp_out=./ ./PlanMsgToState.proto
protoc -I=./ --cpp_out=./ ./RangeSensorMsg.proto
protoc -I=./ --cpp_out=./ ./StateMachineMsgToAll.proto
protoc -I=./ --cpp_out=./ ./StateMsgToPlan.proto
protoc -I=./ --cpp_out=./ ./STM32MsgToCostMap.proto
