project (Core)

include_directories(
    ../Lexer
    ./Instructions
)


set(
    CORE_SOURCES
        object.cpp
        type.cpp
        int_obj.cpp
)

set(
    CORE_HEADERS
        object.hpp
        type.hpp
        types.hpp
        string_obj.hpp
        native_function.hpp
        int_obj.hpp
)



set(
    INSTRUCTIONS_HEADERS
        Instructions/instruction.hpp
        Instructions/instructions_types.hpp
        Instructions/leaf.hpp
        Instructions/while_instruction.hpp
        Instructions/if_instruction.hpp
        Instructions/assignment_instruction.hpp
        Instructions/binop_instruction.hpp
        Instructions/op_type.hpp
)

set(
    INSTRUCTIONS_SOURCES
        Instructions/instruction.cpp
        Instructions/if_instruction.cpp
        Instructions/while_instruction.cpp
        Instructions/assignment_instruction.cpp
        Instructions/leaf.cpp
        Instructions/binop_instruction.cpp
)


add_library(
    Core
    STATIC
        ${CORE_SOURCES}
        ${CORE_HEADERS}
        ${INSTRUCTIONS_HEADERS}
        ${INSTRUCTIONS_SOURCES}
)