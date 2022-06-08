cmake_minimum_required(VERSION 3.6)
project(engine CXX)

# Include custom cmake rules
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# include(cmake/clang-cxx-dev-tools.cmake OPTIONAL)

include_directories(include)

add_library(engine
	src/component.cpp
	src/system.cpp
	src/world.cpp
	src/componentMask.cpp
	src/entityManager.cpp)