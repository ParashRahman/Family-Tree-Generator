cmake_minimum_required(VERSION 3.6)
project(gs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    connection.cpp
    connection.h
    helpers.cpp
    helpers.h
    main.cpp
    person.cpp
    person.h
    prayers.cpp
    prayers.h
    world.cpp
    world.h)

add_executable(gs ${SOURCE_FILES})