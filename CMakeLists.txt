cmake_minimum_required(VERSION 3.5)

project(allocator)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra -Werror -D_FILE_OFFSET_BITS=64")

add_executable(allocator main.cpp src/PoolAllocator.cpp include/PoolAllocator.h src/Chunk.cpp include/Chunk.h)
