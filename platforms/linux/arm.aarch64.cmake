MESSAGE(STATUS "Configure Cross Compiler") 
SET(CMAKE_SYSTEM_NAME Linux)                                                    
SET(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_C_COMPILER       aarch64-linux-gnu-gcc)                              
SET(CMAKE_CXX_COMPILER     aarch64-linux-gnu-g++)    

# set searching rules for cross-compiler                                        
#从来不在指定目录下查找工具程序
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#只在指定目录下查找库文件
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#只在指定目录下查找头文件
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

SET(YOUR_TARGET_OS linux)                                                       
SET(YOUR_TARGET_ARCH armv8-a)                                                   

SET(CMAKE_SKIP_BUILD_RPATH TRUE)                                                
SET(CMAKE_SKIP_RPATH TRUE)  

# set ${CMAKE_C_FLAGS} and ${CMAKE_CXX_FLAGS}flag for cross-compiled process       
#SET(CROSS_COMPILATION_ARM aarch64)                                            
#SET(CROSS_COMPILATION_ARCHITECTURE armv8-a)                                    

# set g++ param                                                                 
# -fopenmp link libgomp                                                         
SET(CMAKE_CXX_FLAGS "-std=c++11 -march=armv8-a ${CMAKE_CXX_FLAGS}")

