/**
 * @file constant_int.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantInstruction implementation.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "constant_int.hpp"

namespace Core
{
    namespace Instructions
    {
        ConstantInt::ConstantInt(int data)
        {
            this->data = data;
            this->type = InstructionType::CONSTANT_INT;
        }

        int ConstantInt::GetData()
        {
            return this->data;
        }
    }
}