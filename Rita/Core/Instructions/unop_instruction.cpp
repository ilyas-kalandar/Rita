/**
 * @file unop_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief UnaryOperatorInstruction implementation.
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright Awaitable(c) 2022
 * 
 */

#include "unop_instruction.hpp"

namespace Core
{
	namespace Instructions
	{
		UnaryOperatorInstruction::UnaryOperatorInstruction(std::shared_ptr<Instruction> val, OpType op_type)
		{
			this->instr = val;
			this->operation_type = op_type;
			this->type = InstructionType::UNOP;
		}
		OpType UnaryOperatorInstruction::GetOperationType()
		{
			return this->operation_type;
		}
		std::shared_ptr<Instruction> UnaryOperatorInstruction::GetValue()
		{
			return this->instr;
		}
	}
}