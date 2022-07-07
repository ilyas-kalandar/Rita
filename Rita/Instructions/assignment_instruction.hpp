/**
 * @file assignment_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief AssignmentInstruction definition
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <string>
#include <memory>

#include "instruction.hpp"

#ifndef assignment_instruction_hpp
#define assignment_instruction_hpp

/**
 * @brief Class for storing instructions like:
 *              var x = 1;
 * Stores identifier (variable), and parameter (may be another instruction).
 */
class AssignmentInstruction : public Instruction
{
private:
    std::string& identifier;
    std::shared_ptr<Instruction> instr;
public: 
    /**
     * @brief Construct a new Assignment Instruction object
     * 
     * @param id 
     * @param inst 
     */
    AssignmentInstruction(std::string& id, std::shared_ptr<Instruction> inst) : identifier(id);
    /**
     * @brief Get the Right Instr object
     * 
     * @return std::shared_ptr<Instruction> 
     */
    std::shared_ptr<Instruction> GetRightInstr();

    /**
     * @brief Get the Identifier object
     * 
     * @return const std::string& 
     */
    const std::string& GetIdentifier();
};

#endif