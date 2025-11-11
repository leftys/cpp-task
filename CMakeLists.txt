cmake_minimum_required(VERSION 3.20)
project(DepthTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library
add_library(depth src/depth.cpp)
target_include_directories(depth PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Enable testing
enable_testing()

# Test executable
add_executable(depth_test tests/depth_test.cpp)
target_link_libraries(depth_test depth)

# Add test to CTest
add_test(NAME depth_test COMMAND depth_test)
