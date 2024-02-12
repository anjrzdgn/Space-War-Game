cmake_minimum_required(VERSION 3.26)
project(space_war C)

set(CMAKE_C_STANDARD 23)

add_executable(space_war main.c)
# Link against the Windows Multimedia API library
target_link_libraries (space_war winmm)
target_link_libraries (space_war ole32)
target_link_libraries (space_war avrt)