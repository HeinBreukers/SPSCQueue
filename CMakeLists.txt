cmake_minimum_required(VERSION 3.2)

project(SPSCQueue)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)


