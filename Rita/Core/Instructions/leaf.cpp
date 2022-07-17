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
        Leaf::Leaf(const std::string& id) : identifier(id)
        {
            this->type = InstructionType::LEAF;
        }

        const std::string& Leaf::GetID()
        {
            return this->identifier;
        }
    }
}