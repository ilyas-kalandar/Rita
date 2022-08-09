Project(Executor)

set(
    EXECUTOR_HEADERS
        Builtins/functions.hpp
        Builtins/constants.hpp
        engine.hpp
        enviropment_type.hpp
        enviropment.hpp
)

set(
    EXECUTOR_SOURCES
        Builtins/functions.cpp
        Builtins/types.hpp
        engine.cpp
        enviropment.cpp
)

include_directories("../Core")
include_directories("../Utils")

add_library(
    Executor
    STATIC
        ${EXECUTOR_HEADERS}
        ${EXECUTOR_SOURCES}
)

target_link_libraries(Executor 
    PUBLIC 
        Core
        Utils
)