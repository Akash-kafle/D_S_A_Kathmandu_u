cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Algorithms)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/header)

#Add files of header and Src
# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add header files
file(GLOB_RECURSE HEADERS "header/*.h")

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)