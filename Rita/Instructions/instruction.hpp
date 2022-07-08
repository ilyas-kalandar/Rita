/**
 * @file instruction.hpp
 * @author your name (you@domain.com)
 * @brief Instruction definition.
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "instructions_types.hpp"

#ifndef instruction_hpp
#define instruction_hpp

/**
 * @brief Base class for Interpreter's instruction
 * Don't create instance of this class, use inherited classes instead
 */
class Instruction
{
protected: 
    InstructionType type;
public:
    /**
     * @brief Get the Type of bject
     * 
     * @return InstructionType 
     */
    InstructionType GetType();
};

#endif