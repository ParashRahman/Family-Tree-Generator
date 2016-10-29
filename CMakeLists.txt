cmake_minimum_required(VERSION 3.6)
project(gs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp src/Person.cpp src/Person.h src/groups/Group.cpp src/groups/Group.h src/groups/Marriage.cpp src/groups/Marriage.h src/groups/Family.cpp src/groups/Family.h src/groups/Religion.cpp src/groups/Religion.h src/groups/Philanthropic.cpp src/groups/Philanthropic.h src/groups/Social.cpp src/groups/Social.h src/groups/Health.cpp src/groups/Health.h)

add_executable(gs ${SOURCE_FILES})