cmake_minimum_required(VERSION 3.12.2 FATAL_ERROR)

project(diff VERSION 0.0.0 LANGUAGES CXX)
add_executable(${PROJECT_NAME} "main.cpp" "diff.hpp")

target_compile_features( ${PROJECT_NAME} PRIVATE cxx_std_20)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
