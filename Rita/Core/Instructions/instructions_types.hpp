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

#include <iostream>

#ifndef instruction_types_hpp
#define instruction_types_hpp

namespace Core
{
    namespace Instructions
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
            CONSTANT_INT,
            CONSTANT_FLOAT,
            CONSTANT_STRING,
            CONSTANT_LIST,
            INDEX,
            VAR_DECL,
            PRINT,
            FUNCTION_DEFINITION,
        };

        /**
         * @brief For using InstructionType with cout object.
         * 
         * @param os 
         * @param instr_type 
         * @return std::ostream& 
         */
        std::ostream& operator <<(std::ostream& os, InstructionType instr_type);
    }
}

#endif