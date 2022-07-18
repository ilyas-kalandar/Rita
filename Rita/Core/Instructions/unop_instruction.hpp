#include "instruction.hpp"
#include "op_type.hpp"

#ifndef unop_instruction_hpp
#define unop_instruction_hpp

namespace Core
{
	namespace Instructions
	{
		class UnaryOperatorInstruction : public Instruction
		{
		protected:
			OpType operation_type;
			std::shared_ptr<Instruction> instr;
		public:
			UnaryOperatorInstruction(std::shared_ptr<Instruction> value, OpType opType);
			std::shared_ptr<Instruction> GetValue();
			OpType GetOperationType();
		};
	}
}
#endif