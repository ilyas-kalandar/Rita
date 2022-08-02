/**
 * @file return_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ReturnInstruction implementation
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "return_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        ReturnInstruction::ReturnInstruction(std::shared_ptr<Instruction> expr) : expr(expr)
        {
            type = InstructionType::RETURN;
        }

        std::shared_ptr<Instruction> ReturnInstruction::GetExpr()
        {
            return expr;
        }
    }
}