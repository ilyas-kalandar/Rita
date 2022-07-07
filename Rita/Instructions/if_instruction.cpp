/**
 * @file if_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Implementation of IfInstruction
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "if_instruction.hpp"

IfInstruction::IfInstruction(std::vector<std::shared_ptr<Instruction>>& body, std::shared_ptr<Instruction> expr) : body(body)
{
    this->expr = expr;
    this->type = InstructionType::IF;
}

std::shared_ptr<Instruction> IfInstruction::GetExpr()
{
    return this->expr;
}
std::vector<std::shared_ptr<Instruction>> IfInstruction::GetBody()
{
    return this->body;
}