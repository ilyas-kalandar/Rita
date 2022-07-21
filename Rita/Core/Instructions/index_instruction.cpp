/**
 * @file index_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief IndexInstruction implementation.
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "index_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        IndexInstruction::IndexInstruction(std::shared_ptr<Instruction> val, std::shared_ptr<Instruction> index)
            :
            value(val),
            index(index)
        {
            this->type = InstructionType::INDEX;
        }

        std::shared_ptr<Instruction> IndexInstruction::GetIndex()
        {
            return this->index;
        }

        std::shared_ptr<Instruction> IndexInstruction::GetValue()
        {
            return this->value;
        }
    }
}