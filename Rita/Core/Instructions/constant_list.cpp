/**
 * @file constant_list.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantList implementation
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "constant_list.hpp"

namespace Core
{
    namespace Instructions
    {
        ConstantList::ConstantList(const std::vector<std::shared_ptr<Instruction>>& list) : list(std::move(list))
        {
            this->type = InstructionType::CONSTANT_LIST;
        }

        const std::vector<std::shared_ptr<Instruction>>& ConstantList::GetList()
        {
            return this->list;
        }
    }
}