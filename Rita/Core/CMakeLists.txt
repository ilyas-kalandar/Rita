project (Core)

set(
    CORE_SOURCES
        object.cpp
        type.cpp

)

set(
    CORE_HEADERS
        object.hpp
        type.hpp
        types.hpp
        data_types.hpp
)

add_library(
    Core
    STATIC
        ${CORE_SOURCES}
        ${CORE_HEADERS}
)

# set_target_properties(
#     Core
#     PROPERTIES
#     CXX_STANDARD 20
#     CXX_STANDARD_REQUIRED ON
# )