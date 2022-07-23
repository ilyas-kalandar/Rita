/**
 * @file instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Definition of instruction-class
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <sstream>

#include "instruction.hpp"

namespace Core
{
	namespace Instructions
	{
		InstructionType Instruction::GetType() const
		{
			return this->type;
		}

		Instruction::operator std::string()
		{
			std::stringstream ss;
			ss << "Instruction<";
			ss << type;
			ss << ">";
			return ss.str();	
		}

	}
}