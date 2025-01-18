cmake_minimum_required(VERSION 3.29)
project(DataProject1)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataProject1 main.cpp
        Item.cpp
        Item.h
        PerishableItem.cpp
        PerishableItem.h
        NonPerishableItem.cpp
        NonPerishableItem.h
        Inventory.cpp
        Inventory.h)
