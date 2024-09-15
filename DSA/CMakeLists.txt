cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DSA)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/header)
#Add files of header and Src
# Add source files
file(GLOB_RECURSE SOURCES "Lab3_27_28/src/*.cpp")
file(GLOB_RECURSE SOURCES "Lab3_27_28/Linked_list/src/*.cpp")
file(GLOB_RECURSE SOURCES "Lab3_27_28/BinarySearchTree/src/*.cpp")
file(GLOB_RECURSE SOURCES "Lab4_27_28/*.cpp")
file(GLOB_RECURSE SOURCES "Lab5_27_28/src/*.cpp")

# Add executable
add_executable(DSA ${SOURCES} ${HEADERS})


# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)