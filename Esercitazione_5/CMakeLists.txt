cmake_minimum_required(VERSION 3.20)
project(esercitazione5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

## Creo il target per l'eseguibile principale del mio progetto software

set(confronto_tempi confronto_tempi.cpp timecounter.cpp randfiller.h)
add_executable(confronto_tempi confronto_tempi.cpp ${confronto_tempi})

## Creo i target per gli eseguibili che effettueranno i test unitari
add_executable(test_bubble_sort test_bubble_sort.cpp)
add_test(NAME bubble_sort COMMAND test_bubble_sort)

add_executable(test_insertion_sort test_insertion_sort.cpp)
add_test(NAME insertion_sort COMMAND test_insertion_sort)

add_executable(test_selection_sort test_selection_sort.cpp)
add_test(NAME selection_sort COMMAND test_selection_sort)

add_executable(test_merge_sort test_merge_sort.cpp)
add_test(NAME merge_sort COMMAND test_merge_sort)

add_executable(test_quick_sort test_quick_sort.cpp)
add_test(NAME quick_sort COMMAND test_quick_sort)

enable_testing()
