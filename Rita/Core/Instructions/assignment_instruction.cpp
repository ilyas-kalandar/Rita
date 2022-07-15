/**
 * @file assignment_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Implementation of AssignmentInstruction
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "assignment_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        AssignmentInstruction::AssignmentInstruction(std::string& id, std::shared_ptr<Instruction> inst) : identifier(id)
        {
            this->type = InstructionType::ASSIGNMENT;
            this->instr = inst;
        }

        std::shared_ptr<Instruction> AssignmentInstruction::GetRightInstr()
        {
            return this->instr;
        }

        const std::string& AssignmentInstruction::GetIdentifier()
        {
            return this->identifier;
        }
    }
}
