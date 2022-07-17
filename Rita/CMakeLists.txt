# CMakeList.txt : CMake project for Rita, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add global configuration 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("Lexer")
add_subdirectory("Core")
add_subdirectory("Parser")
add_subdirectory("Executor")
add_subdirectory("Interpreter")
