/**
 * @file constant_int.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantInt definition.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "instruction.hpp"

#ifndef constant_int_hpp
#define constant_int_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing integers into instructions.
         * 
         */
        class ConstantInt : public Instruction
        {
        protected:
            int data;
        public:
            /**
             * @brief Construct a new Constant Int object
             * 
             * @param data 
             */
            ConstantInt(int data);
            /**
             * @brief Get the Data object
             * 
             * @return int 
             */
            int GetData();
        };
    }
}

#endif