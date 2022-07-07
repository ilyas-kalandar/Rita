/**
 * @file instruction.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "instruction_type.hpp"

#ifndef instruction_hpp
#define instruction_hpp

class Instruction
{
protected: 
    InstructionType type;
public:
    InstructionType GetType();
};

#endif