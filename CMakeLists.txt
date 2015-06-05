cmake_minimum_required (VERSION 2.6)
project (math)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(math Main.c math.c)
