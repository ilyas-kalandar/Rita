/**
 * @file op_type.hpp
 * @author Ilyas Awaitable - t.me/awaitable
 * @brief File for Operations types.
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#ifndef op_type_h
#define op_type_h

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Operations types.
         * 
         */
        enum class OpType
        {
            PLUS,
            MINUS,
            MUL,
            DIV,
            EQUAL_EQUAL,
            LESS_OR_EQUAL_THAN, 
            LESS_THAN,
            GREATER_THAN,
            GREATER_OR_EQUAL_THAN,
            NOT,
            AND,
            OR
        };

        /**
         * @brief 
         * 
         * @param os 
         * @param op 
         * @return std::ostream& 
         */
        std::ostream& operator<<(std::ostream& os, OpType op);
    }
}

#endif