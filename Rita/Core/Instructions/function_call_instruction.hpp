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
#define function_call_instruction_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief 
         * 
         */
        class FunctionCallInstruction : public Instruction
        {
        protected:
            std::string functionName;
            std::vector<std::shared_ptr<Instruction>> functionArguments;
        public:
            /**
             * @brief Construct a new Function Call Instruction object
             * 
             * @param functionName 
             * @param args 
             */
            FunctionCallInstruction(const std::string& functionName, const std::vector<std::shared_ptr<Instruction>>& args);
            /**
             * @brief Get the Function Name object
             * 
             * @return const std::string& 
             */
            const std::string& GetFunctionName();
            /**
             * @brief Get the Function Arguments object
             * 
             * @return const std::vector<Core::Instructions::Instruction*> 
             */
            const std::vector<std::shared_ptr<Core::Instructions::Instruction>> GetFunctionArguments();
        };
    }
}

#endif