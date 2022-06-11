cmake_minimum_required(VERSION 3.5)
project(dsi_project)

include_directories(inc)
file(GLOB SOURCES "src/*.cpp")
add_executable(out ${SOURCES})
set_property(TARGET out PROPERTY CXX_STANDARD 17)
