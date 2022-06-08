cmake_minimum_required(VERSION 3.6)
project(engine CXX)

# Include custom cmake rules
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include(../cmake/clang-cxx-dev-tools.cmake OPTIONAL)

add_library(engine
	src/component.cpp
	include/entity.h
	include/componentManager.h
	src/system.cpp
	src/world.cpp
	include/world.h
	src/componentMask.cpp
	include/componentMask.h
	src/entityManager.cpp
	include/entityManager.h
	include/entityHandle.h
	include/componentHandle.h)