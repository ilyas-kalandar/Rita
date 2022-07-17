/**
 * @file binon_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Implementations of BinOpInstruction's functions.
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright Awaitable(c) 2022
 * 
 */

#include "binop_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        BinOpInstruction::BinOpInstruction(std::shared_ptr<Instruction> first, std::shared_ptr<Instruction> second, OpType op_type) : first(first), second(second)
        {
            this->operation_type = op_type;
            this->type = InstructionType::BINOP;
        }

        std::shared_ptr<Instruction> BinOpInstruction::GetFirst()
        {
            return this->first;
        } 

        std::shared_ptr<Instruction> BinOpInstruction::GetSecond()
        {
            return this->second;
        }

        OpType BinOpInstruction::GetOperationType()
        {
            return this->operation_type;
        }
    }
}
