#pragma once

// for cmake
// 用于在CMakeLists文件中解析用
// 这里版本编号的管理使用常见的major.minor(.patch)格式，major是最大的版本编号，minor为其次，patch对应着小版本里的补丁级别。
// 0.1.0
#define ROBOT_APP_VER_MAJOR 0                       
#define ROBOT_APP_VER_MINOR 1                       
#define ROBOT_APP_VER_PATCH 0                       

#define ROBOT_APP_VERSION (ROBOT_APP_VER_MAJOR * 10000 + ROBOT_APP_VER_MINOR * 100 + ROBOT_APP_VER_PATCH)

// for source code
// 用于在项目源码中获取版本号字符串
// v0.1.0
#define _ROBOT_APP_STR(s) #s
#define ROBOT_PROJECT_VERSION(major, minor, patch) "v" _ROBOT_APP_STR(major.minor.patch)