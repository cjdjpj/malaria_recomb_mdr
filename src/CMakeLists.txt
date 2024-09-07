cmake_minimum_required(VERSION 3.27.1)

set (CMAKE_CXX_STANDARD 20)

project(MalariaPopSim)

add_executable(${PROJECT_NAME} utils.cpp host.cpp simulator.cpp )