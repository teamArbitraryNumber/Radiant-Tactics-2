cmake_minimum_required(VERSION 3.10)  # Update minimum version
project(RadiantTactics LANGUAGES CXX)  # Remove space and specify language

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# Modern C++ standard specification
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/header
    ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
    ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

# Only add googletest if you have it
# add_subdirectory(googletest)