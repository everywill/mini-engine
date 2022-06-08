cmake_minimum_required(VERSION 3.6)
project(example CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(../include)
link_directories(../build)

add_executable(example main.cpp)
target_link_libraries(example libengine.a)