project (Interpreter)

# Prepare executable

set(SOURCE_EXE main.cpp)

add_executable(rita ${SOURCE_EXE})

include_directories("../Lexer/")
include_directories("../Core/")
include_directories("../Executor")
include_directories("../Parser")
include_directories("../Utils")

target_link_libraries(rita PUBLIC Lexer)
target_link_libraries(rita PUBLIC Core)
target_link_libraries(rita PUBLIC Parser)
target_link_libraries(rita PUBLIC Utils)
target_link_libraries(rita PUBLIC Executor)