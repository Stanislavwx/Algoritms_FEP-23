cmake_minimum_required(VERSION 3.10)
project(lab3_methodic_final CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3
    main.cpp
    Sort/Sort.cpp
)
target_include_directories(lab3 PRIVATE ${CMAKE_SOURCE_DIR})
