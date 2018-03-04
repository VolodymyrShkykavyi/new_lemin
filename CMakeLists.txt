cmake_minimum_required(VERSION 3.9)
project(lem_in2 C)

set(CMAKE_C_STANDARD 99)


include_directories(${CMAKE_SOURCE_DIR}/libft/includes)
include_directories(${CMAKE_SOURCE_DIR}/includes)

add_executable(lem_in2 src/main.c)