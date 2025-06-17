cmake_minimum_required(VERSION 3.24)
project(geometry)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(geometry
    src/circle.cpp
    src/line.cpp
    src/point.cpp
    src/polygon.cpp
    src/ray.cpp
    src/segment.cpp
    src/vector.cpp
    circle.h
    IShape.h
    line.h
    point.h
    polygon.h
    ray.h
    segment.h
    vector.h)
