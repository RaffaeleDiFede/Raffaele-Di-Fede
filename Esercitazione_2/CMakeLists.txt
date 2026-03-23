cmake_minimum_required(VERSION 3.20)

project(secondo_esercizio) 

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


add_executable(esercizio1 esercizio_1.cpp)
add_executable(esercizio2 esercizio_2.cpp)