cmake_minimum_required(VERSION 3.10)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -pedantic)

enable_testing()

include_directories(3rd-party)

add_subdirectory(2019)
