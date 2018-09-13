cmake_minimum_required(VERSION 3.10)
project(DS_Tree)

include_directories(
        C:/Users/DELL/Codes/my-ugly-headers      #laptop
        C:/Users/Toodyao/Desktop/my-ugly-headers #desktop
)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS_Tree main.cpp tree_node.hpp binary_tree.hpp express_tree.hpp expression_calculate.h expression_calculate.cpp binary_search_tree.cpp binary_search_tree.h heap.cpp heap.h compare.hpp)
add_executable(DS_Heap_Test heap_test.cpp heap.h heap.cpp compare.hpp heap.hpp)
add_executable(DS_Tree_Test tree_node.hpp tree_test.cpp binary_tree_better.hpp)