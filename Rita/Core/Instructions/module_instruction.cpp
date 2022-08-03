/**
 * @file module_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ModuleInstruction implementation.
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "module_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        ModuleInstruction::ModuleInstruction(std::vector<std::shared_ptr<Instruction>> instructions)
            :
            instructions(instructions)
        {
            type = InstructionType::MODULE;
        }

        const std::vector<std::shared_ptr<Instruction>>& ModuleInstruction::GetInstructions()
        {
            return instructions;
        }
    }
}