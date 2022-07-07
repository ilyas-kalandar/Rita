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

InstructionType Instruction::GetType()
{
    return this->type;
}