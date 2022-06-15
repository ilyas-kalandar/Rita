project (Parser)

set(SOURCE_PARSER foo.cpp)
set(HEADER_PARSER blyat.h)

add_library(Parser STATIC ${SOURCE_PARSER} ${HEADER_PARSER})

target_include_directories(Parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})