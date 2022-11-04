cmake_minimum_required(VERSION 3.6)
project(embers-demo LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_CPPCHECK "cppcheck")

include_directories(include)
include_directories(lib/include)

file(GLOB_RECURSE EMBERS_DEMO_SRCS src/**.c)

add_subdirectory(lib)

add_executable(embers-demo ${EMBERS_SRCS} ${EMBERS_DEMO_SRCS})
target_link_libraries(embers-demo PRIVATE embers)



