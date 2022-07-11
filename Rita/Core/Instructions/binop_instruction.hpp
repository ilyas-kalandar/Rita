/**
 * @file binop_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Definition for binop-instructions.
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright Awaitable(c) 2022
 * 
 */

#include <memory>

#include "instruction.hpp"
#include "op_type.hpp"

#ifndef binop_instruction_hpp
#define binop_instruction_hpp

/**
 * @brief Class for storing instructions like: 
 *              (1 + 1) / 2 + 3, etc...
 * 
 * This class contains first argument, second argument and opeartion's type.
 * 
 */
class BinOpInstruction : public Instruction
{
private:
    std::shared_ptr<Instruction> first;
    std::shared_ptr<Instruction> second;
    OpType operation_type;
public:
    /**
     * @brief Construct a new Bin Op Instruction object
     * 
     * @param first First Instruction for execute
     * @param second Second Instruction for execute
     * @param op_type Operation's type (+, -, /, *)
     */
    BinOpInstruction(std::shared_ptr<Instruction> first, std::shared_ptr<Instruction> second, OpType op_type);
    /**
     * @brief Get the First instruction
     * 
     * @return std::shared_ptr<Instruction> 
     */
    std::shared_ptr<Instruction> GetFirst();
    /**
     * @brief Get the Second instruction
     * 
     * @return std::shared_ptr<Instruction> 
     */
    std::shared_ptr<Instruction> GetSecond();
    /**
     * @brief Get the Operation Type object
     * 
     * @return OpType 
     */
    OpType GetOperationType();
};

#endif