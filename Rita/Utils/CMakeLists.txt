Project(Utils)

set(
    UTILS_SOURCES
        ast_printer.cpp
)

set(
    UTILS_HEADERS
        ast_printer.hpp
)

add_library(
    Utils
    STATIC
        ${UTILS_SOURCES} ${UTILS_HEADERS}
)

include_directories(
    ../Core
)

target_link_libraries(
    Utils
    PUBLIC
        Core
)