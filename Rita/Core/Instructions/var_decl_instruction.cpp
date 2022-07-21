/**
 * @file var_decl_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief VariableDeclarationInstruction implementation.
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "var_decl_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        VariableDeclarationInstruction::VariableDeclarationInstruction(std::string& varName, std::shared_ptr<Instruction> instr)
            :
            varName(varName),
            expr(instr)

        {
            this->type = InstructionType::VAR_DECL;
        }
        std::shared_ptr<Instruction> VariableDeclarationInstruction::GetExpression()
        {
            return this->expr;
        }

        const std::string& VariableDeclarationInstruction::GetVarName()
        {
            return this->varName;
        }
    }
}