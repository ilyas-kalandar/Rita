project (Interpreter)

# Prepare executable

set(SOURCE_EXE main.cpp)

add_executable(main ${SOURCE_EXE})

target_link_libraries(main PUBLIC Lexer)
target_link_libraries(main PUBLIC Parser)