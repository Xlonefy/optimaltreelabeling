cmake_minimum_required(VERSION 3.5.0)
project(OptimalTreeLabeling)

find_package (Threads REQUIRED)

add_definitions(-Wall -Wextra -Wpedantic -std=c++17 -O3 -march=native -pthread)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_library(OptimalTreeLabeling SHARED ${SOURCES})

add_executable(main main.cc)
target_link_libraries(main OptimalTreeLabeling)
target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
