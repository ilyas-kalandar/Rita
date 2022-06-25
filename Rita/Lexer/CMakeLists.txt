project (Lexer)

set(SOURCE_LEXER lexer.cpp token_types.cpp token.cpp tokenator.cpp)
set(HEADER_LEXER lexer.h token_types.h token.h tokenator.h)

add_library(Lexer STATIC ${SOURCE_LEXER} ${HEADER_LEXER})

include_directories(Constants)

target_include_directories(Lexer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})