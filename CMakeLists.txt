cmake_minimum_required(VERSION 3.20)

project(memory_allocator)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(allocator
        src/MemoryAllocator.cpp
        src/MemoryPool.cpp
)

add_executable(app
        app/main.cpp
)

target_link_libraries(app allocator)