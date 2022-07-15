/**
 * @file leaf.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Leaf's implementation
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "leaf.hpp"

namespace Core
{
    namespace Instructions
    {
        Leaf::Leaf(RitaObject* obj)
        {
            this->type = InstructionType::LEAF;
            this->obj = obj;
        }

        RitaObject* Leaf::GetObj()
        {
            return this->obj;
        }
    }
}