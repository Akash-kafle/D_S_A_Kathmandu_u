

cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MyProject main.cpp Linked_list_queue.cpp Linked_list_queue.h Linked_list_stack.cpp Linked_list_stack.h )
add_executable(MhProject Array_queue.cpp Array_queue.h Array_stack.cpp Array_stack.h Queue.h Stack.h )

target_link_libraries(MyProject PRIVATE MyLibrary)

add_subdirectory(subdirectory)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_compile_options(-Wall -Wextra -pedantic -Werror)