# CMakeList.txt : CMake project for Rita, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory("Lexer")
add_subdirectory("Parser")
add_subdirectory("Interpreter")

# TODO: Add tests and install targets if needed.
