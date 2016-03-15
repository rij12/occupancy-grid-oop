cmake_minimum_required(VERSION 3.3)
project(occupancy_grid_oop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

set(SOURCE_FILES main.cpp Grid.cpp Robot.cpp Robot.h Grid.h)
add_executable(occupancy_grid_oop ${SOURCE_FILES})

