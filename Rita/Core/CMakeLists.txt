project (Core)

set(SOURCE_CORE "type.h")
set(HEADER_CORE "type.cpp")

add_library(CORE STATIC ${SOURCE_LEXER} ${HEADER_LEXER})

target_include_directories(CORE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})