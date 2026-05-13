cmake_minimum_required(VERSION 3.20)
project(esercitazione8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(MAIN_SOURCE test.cpp)

add_executable(test_grafo ${MAIN_SOURCE} ${GRAFO_HEADERS})

enable_testing()
add_test(NAME test_funzionale_grafo COMMAND test_grafo)