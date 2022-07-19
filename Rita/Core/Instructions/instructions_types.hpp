/**
 * @file instruction_type.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Instructions types.
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#ifndef instruction_types_hpp
#define instruction_types_hpp

namespace Core
{
    enum class InstructionType
    {
        BINOP,
        LEAF,
        ASSIGNMENT,
        IF,
        WHILE,
        FUNCTION_CALL,
        ATTRIBUTE,
        UNOP,
        CONSTANT,
    };
}

#endif