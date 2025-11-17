# =========================
# File: CMakeLists.txt (root)
# =========================
# Збірка:
#   mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

cmake_minimum_required(VERSION 3.15)
project(Lab_02_QuickSort_And_OS_NoSTL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Sort STATIC Sort/Sort.cpp)

add_executable(Lab_02_01 Lab_02_01/main.cpp)
add_executable(Lab_02_02 Lab_02_02/main.cpp)

foreach(exe Lab_02_01 Lab_02_02)
  target_include_directories(${exe} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
  target_link_libraries(${exe} PRIVATE Sort)
endforeach()
