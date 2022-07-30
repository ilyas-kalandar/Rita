project(Lexer)

set(
	LEXER_SOURCES
		lexer.cpp
		token.cpp
		token_types.cpp
		tokenator.cpp
)

set(
	LEXER_HEADERS
		lexer.hpp
		token.hpp
		token_types.hpp
		tokenator.hpp
)

add_library(
	Lexer 
	STATIC
		${LEXER_SOURCES}
		${LEXER_HEADERS}
)

set_target_properties(
	Lexer
	PROPERTIES
	CXX_STANDARD_REQUIRED 17
)

include_directories("../Utils")

target_link_libraries(
	Lexer
	PUBLIC
		Utils	
)