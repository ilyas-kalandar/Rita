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
#include "constants_types.hpp"

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