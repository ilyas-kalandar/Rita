#include "attribute_instruction.hpp"

namespace Core
{
	namespace Instructions
	{
		AttributeInstruction::AttributeInstruction(std::shared_ptr<Instruction> value, const std::string& attr)
			:
			attr(attr),
			value(value)
		{
			this->type = InstructionType::ATTRIBUTE;
		}
		const std::string& AttributeInstruction::GetAttr()
		{
			return this->attr;
		}

		std::shared_ptr<Core::Instructions::Instruction> AttributeInstruction::GetValue()
		{
			return this->value;
		}
	}
}