/**
 * @file attribute_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Definition of AttributeInstruction
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright Awaitable(c) 2022
 * 
 */

#include <memory>
#include "instruction.hpp"

#ifndef attribute_instruction_hpp
#define attribute_instruction_hpp

namespace Core
{
	namespace Instructions
	{
		/**
		 * @brief Class for storing instructions like
		 * 
		 * someObject.someField
		 * 
		 */
		class AttributeInstruction : public Instruction
		{
		protected:
			std::shared_ptr<Core::Instructions::Instruction> value;
			std::string attr;
		public:
			/**
			 * @brief Construct a new Attribute Instruction object
			 * 
			 * @param value Another instruction 
			 * @param attr Attribute
			 */
			AttributeInstruction(std::shared_ptr<Instruction> value, const std::string& attr);
			/**
			 * @brief Get the Value object
			 * 
			 * @return std::shared_ptr<Core::Instructions::Instruction> 
			 */
			std::shared_ptr<Core::Instructions::Instruction> GetValue();
			/**
			 * @brief Get the Attr object
			 * 
			 * @return const std::string& 
			 */
			const std::string& GetAttr();
		};
	}
}

#endif