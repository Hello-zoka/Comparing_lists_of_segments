cmake_minimum_required(VERSION 3.17)
project(Codstyle)

set(CMAKE_CXX_STANDARD 17)
add_compile_options("--std=c++11")

add_executable(Codstyle main.cpp header.h WorkingWithUser.cpp Relaxing.cpp Compare.cpp)