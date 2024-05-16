cmake_minimum_required(VERSION 3.8)
project("rpg")

file(GLOB classes "*.h" "*.cpp")

add_executable(rpg main.cpp ${classes})

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET rpg PROPERTY CXX_STANDARD 17)
endif()