/**
 * @file attribute_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief AttributeInstruction implementation
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "attribute_instruction.hpp"

namespace Core
{
	namespace Instructions
	{
		AttributeInstruction::AttributeInstruction(std::shared_ptr<Instruction> value, const std::string& attr, bool bind)
			:
			attr(attr),
			value(value)
		{
			this->type = InstructionType::ATTRIBUTE;
			this->bind = bind;
		}
		const std::string& AttributeInstruction::GetAttr()
		{
			return this->attr;
		}

		std::shared_ptr<Core::Instructions::Instruction> AttributeInstruction::GetValue()
		{
			return this->value;
		}

		bool AttributeInstruction::IsBindAllowed()
		{
			return bind;
		}
	}
}