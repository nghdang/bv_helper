cmake_minimum_required(VERSION 3.16)

project(bv_helper VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_FW_GMOCK ON)
set(BUILD_FW_UNIT_TESTS ON)
set(BUILD_UNIT_TESTS ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Core Quick Scxml)

add_subdirectory(framework)
add_subdirectory(application)
