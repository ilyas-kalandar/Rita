project (Parser)

set(
	PARSER_HEADERS
		parser.hpp
)

set(
	PARSER_SOURCES
		parser.cpp
)

add_library(
	Parser
	STATIC
		${PARSER_HEADERS}
		${PARSER_SOURCES}
)

include_directories(
	../Lexer
	Lexer
	../Core
	Core
)

target_link_libraries(
	Parser
	PUBLIC 
		Lexer
		Core
)