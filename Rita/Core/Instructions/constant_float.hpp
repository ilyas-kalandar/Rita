/**
 * @file constant_float.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantFloat definition.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "instruction.hpp"

#ifndef constant_float_hpp
#define constant_float_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing long double into instruction
         * 
         */
        class ConstantFloat : public Instruction
        {
        protected:
            long double data;
        public:
            ConstantFloat(long double data);
            long double GetData();
        };
    }
}

#endif