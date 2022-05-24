cmake_minimum_required(VERSION 3.15.0)

project(easy2d LANGUAGES CXX C)

add_definitions(-w)

file(GLOB_RECURSE PROJECT_SOURCES src/source/*.cpp)

file(GLOB_RECURSE PROJECT_SCRIPT ar.py)

include_directories(easy2d to src/include)

add_library(easy2d STATIC ${PROJECT_SOURCES})

add_custom_command(TARGET easy2d
                POST_BUILD
                COMMAND python ${PROJECT_SCRIPT}
)