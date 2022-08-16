/**
 * @file while_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief WhileInstruction implementation
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "while_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        WhileInstruction::WhileInstruction(std::vector<std::shared_ptr<Instruction>>& body, std::shared_ptr<Instruction> expr) : body(std::move(body)), expr(expr)
        {
            this->type = InstructionType::WHILE;
        }

        std::shared_ptr<Instruction> WhileInstruction::GetExpression()
        {
            return this->expr;
        }

        std::vector<std::shared_ptr<Instruction>>& WhileInstruction::GetBody()
        {
            return this->body;
        }
    }
}