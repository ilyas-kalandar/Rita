/**
 * @file module_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ModuleInstruction definition
 * @version 0.1
 * @date 2022-08-03
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <vector>
#include <memory>

#include "instruction.hpp"

#ifndef module_instr_hpp
#define module_instr_hpp

namespace Core
{
    namespace Instructions
    {
        class ModuleInstruction : public Instruction
        {
        protected:
            std::vector<std::shared_ptr<Instruction>> instructions;
        public:
            /**
             * @brief Construct a new Module Instruction object
             * 
             * @param instructions 
             */
            ModuleInstruction(std::vector<std::shared_ptr<Instruction>> instructions);

            /**
             * @brief Get the Instructions object
             * 
             * @return const std::vector<std::shared_ptr<Instruction>>& 
             */
            std::vector<std::shared_ptr<Instruction>>& GetInstructions();
        };
    }
}

#endif