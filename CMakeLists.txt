cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILEON ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
# 声明一个 cmake 工程
project(list)
add_executable(list
	MyList.cpp)
