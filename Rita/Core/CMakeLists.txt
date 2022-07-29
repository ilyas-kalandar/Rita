project (Core)

include_directories(
    ../Lexer
    ./Instructions
)


set(
    CORE_SOURCES
        object.cpp
        type.cpp
        string_obj.cpp
        native_function.cpp
        int_obj.cpp
        list_obj.cpp
        user_object.cpp
        func_obj.cpp
)

set(
    CORE_HEADERS
        object.hpp
        type.hpp
        string_obj.hpp
        native_function.hpp
        int_obj.hpp
        list_obj.hpp
        user_object.hpp
        func_obj.hpp
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
        Instructions/function_call_instruction.hpp
        Instructions/unop_instruction.hpp
        Instructions/attribute_instruction.hpp
        Instructions/constant_string.hpp
        Instructions/constant_int.hpp
        Instructions/constant_float.hpp
        Instructions/constant_list.hpp
        Instructions/index_instruction.hpp
        Instructions/var_decl_instruction.hpp
        Instructions/function_definition.hpp
)

set(
    INSTRUCTIONS_SOURCES
        Instructions/instruction.cpp
        Instructions/instructions_types.cpp
        Instructions/if_instruction.cpp
        Instructions/while_instruction.cpp
        Instructions/assignment_instruction.cpp
        Instructions/leaf.cpp
        Instructions/binop_instruction.cpp
        Instructions/function_call_instruction.cpp
        Instructions/unop_instruction.cpp
        Instructions/attribute_instruction.cpp
        Instructions/constant_string.cpp
        Instructions/constant_int.cpp
        Instructions/constant_float.cpp
        Instructions/constant_list.cpp
        Instructions/index_instruction.cpp
        Instructions/var_decl_instruction.cpp
        Instructions/op_type.cpp
        Instructions/function_definition.cpp
)


add_library(
    Core
    STATIC
        ${CORE_SOURCES}
        ${CORE_HEADERS}
        ${INSTRUCTIONS_HEADERS}
        ${INSTRUCTIONS_SOURCES}
)

include_directories(
    "../Utils"
)

target_link_libraries(
    Core
    PUBLIC
        Utils
)