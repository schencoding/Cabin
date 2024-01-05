cmake_minimum_required(VERSION 3.16)
project(Cabin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g -mavx -mavx2 -mbmi2 -mbmi")

# Include directories
include_directories(include)

# Add source files
set(SOURCES
    src/column.cpp
    src/queryqueue.cpp 
    src/simd_compute.cpp 
    src/cabin.cpp
    src/test.cpp
)

# Define the executable
add_executable(Cabin ${SOURCES})

# Set the output directory for the executable
set_target_properties(Cabin PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)