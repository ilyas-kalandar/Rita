#include "instruction.hpp"

#ifndef attribute_instruction_hpp
#define attribute_instruction_hpp

namespace Core
{
	namespace Instructions
	{
		class AttributeInstruction : public Instruction
		{
		protected:
			std::shared_ptr<Core::Instructions::Instruction> value;
			std::string attr;
		public:
			AttributeInstruction(std::shared_ptr<Instruction> value, const std::string& attr);
			std::shared_ptr<Core::Instructions::Instruction> GetValue();
			const std::string& GetAttr();
		};
	}
}

#endif