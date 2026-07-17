cmake_minimum_required(VERSION 3.16)
project(concurrency LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_library(spin_mutex "src/spin_mutex.cpp")
add_library(sleep_mutex "src/sleep_mutex.cpp")

target_include_directories(spin_mutex PUBLIC include)
target_include_directories(sleep_mutex PUBLIC include)

enable_testing()
add_subdirectory(tests)
