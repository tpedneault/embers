cmake_minimum_required(VERSION 3.6)
project(embers LANGUAGES C VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB_RECURSE EMBERS_SRCS src/**.c)

add_library(embers STATIC ${EMBERS_SRCS})
