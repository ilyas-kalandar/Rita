/**
 * @file constant_bool.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantBool implementation.
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "constant_bool.hpp"

namespace Core
{
    namespace Instructions
    {
        ConstantBool::ConstantBool(bool data)
        {
            this->data = data;
            type = InstructionType::CONSTANT_BOOL;
        }

        bool ConstantBool::GetData()
        {
            return data;
        }
    }
}
