cmake_minimum_required(VERSION 3.25)
project(gothic-chest-solver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(gothic-chest-solver ${SOURCES})

target_include_directories(gothic-chest-solver PRIVATE
    ${CMAKE_SOURCE_DIR}/include/project
)
