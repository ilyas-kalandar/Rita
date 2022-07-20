/**
 * @file constant_float.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantFloat implementation.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "constant_float.hpp"

namespace Core
{
    namespace Instructions
    {
        ConstantFloat::ConstantFloat(long double data)
        {
            this->data = data; // yes, copy =(
            this->type = InstructionType::CONSTANT_FLOAT;
        }
        
        long double ConstantFloat::GetData()
        {
            return this->data;
        }
    }
}