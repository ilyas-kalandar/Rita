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

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing instructions like:
         *              test = a,
         *              test.a = 3
         * Stores an identifier (or attribe) and expr.
         */
        class AssignmentInstruction : public Instruction
        {
        private:
            std::shared_ptr<Instruction> obj;
            std::shared_ptr<Instruction> instr;
        public: 
            /**
             * @brief Construct a new Assignment Instruction object
             * 
             * @param obj
             * @param inst 
             */
            AssignmentInstruction(std::shared_ptr<Instruction>, std::shared_ptr<Instruction> inst);
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
            std::shared_ptr<Instruction> GetObject();
        };
    }
}

#endif