Project(Utils)

set(
    UTILS_SOURCES
        ast_printer.cpp
        rita_exception.cpp
)

set(
    UTILS_HEADERS
        ast_printer.hpp
        rita_exception.hpp
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