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

#include "instruction.hpp"

InstructionType Instruction::GetType() const
{
    return this->type;
}

std::ostream& operator<<(std::ostream& os, const Instruction& instr)
{
	os << "Instruction<";

	switch (instr.GetType())
	{
	case InstructionType::ASSIGNMENT:
		os << "ASSIGNMENT";
		break;
	case InstructionType::BINOP:
		os << "BINOP";
		break;
	case InstructionType::IF:
		os << "IF";
		break;
	case InstructionType::LEAF:
		os << "LEAF";
		break;
	case InstructionType::WHILE:
		os << "WHILE";
		break;
	}
	os << ">";
	return os;
}
