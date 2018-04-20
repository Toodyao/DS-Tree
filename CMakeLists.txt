cmake_minimum_required(VERSION 3.10)
project(DS_Tree)

include_directories(
        C:/Users/DELL/Codes/my-ugly-headers      #laptop
        C:/Users/Toodyao/Desktop/my-ugly-headers #desktop
)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS_Tree main.cpp tree_node.hpp binary_tree.hpp express_tree.hpp)