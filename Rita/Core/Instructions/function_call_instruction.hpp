/**
 * @file function_call_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief FunctionCallInstruction definition.
 * @version 0.1
 * @date 2022-07-16
 * 
 * @copyright Copyright Awaitable(c) 2022
 * 
 */

#include <vector>
#include <memory>

#include "instruction.hpp"

#ifndef function_call_instruction_hpp
#define function_call_instruction_hppa

namespace Core
{
    namespace Instructions
    {
        class FunctionCallInstruction : public Instruction
        {
        protected:
            std::string functionName;
            std::vector<std::shared_ptr<Instruction>> functionArguments;
        public:
            FunctionCallInstruction(const std::string& functionName, const std::vector<std::shared_ptr<Instruction>>& args);
        };
    }
}

#endif