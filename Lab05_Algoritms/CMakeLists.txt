cmake_minimum_required(VERSION 3.10)
project(HEAP_refactor_split LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Heap STATIC Heap.cpp)
target_include_directories(Heap PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(Part1 Part1/main.cpp)
target_link_libraries(Part1 PRIVATE Heap)

add_executable(Part2 Part2/main.cpp)
target_link_libraries(Part2 PRIVATE Heap)