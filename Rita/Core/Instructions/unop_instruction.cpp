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