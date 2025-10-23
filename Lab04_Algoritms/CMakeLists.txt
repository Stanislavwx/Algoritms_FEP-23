cmake_minimum_required(VERSION 3.15)
project(Lab04_Trees_BST CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab04_01
    src/Lab_04_01.cpp
    src/Tree.cpp
)
target_include_directories(lab04_01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(lab04_02
    src/Lab_04_02.cpp
    src/Tree.cpp
)
target_include_directories(lab04_02 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
