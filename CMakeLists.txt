cmake_minimum_required(VERSION 3.8)

project ("rpg")

add_executable(rpg main.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET rpg PROPERTY CXX_STANDARD 17)
endif()