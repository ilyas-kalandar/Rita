/**
 * @file unop_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief UnaryOperatorInstruction definition
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <memory>

#include "instruction.hpp"
#include "op_type.hpp"

#ifndef unop_instruction_hpp
#define unop_instruction_hpp

namespace Core
{
	namespace Instructions
	{
		/**
		 * @brief Class for storing instruction like
		 * 
		 * "- someObject"
		 * 
		 */
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