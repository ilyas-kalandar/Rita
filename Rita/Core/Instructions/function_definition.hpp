/**
 * @file function_definition.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief FunctionDefinitionInstruction definition
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <memory>
#include <vector>

#include "instruction.hpp"

#ifndef func_def_instr_hpp
#define func_def_instr_hpp

namespace Core
{
    namespace Instructions
    {
        class FunctionDefinitionInstruction : public Instruction
        {
        protected:
            std::vector<std::shared_ptr<Instruction>> body;
            std::vector<std::string> args;
            std::string name;
        public:
            /**
             * @brief Construct a new Function Definition Instruction object
             * @param 
             * 
             */
            FunctionDefinitionInstruction(std::string& name, std::vector<std::string>& args, std::vector<std::shared_ptr<Instruction>>& body);

            /**
             * @brief Get function's arguments.
             * 
             */
            const std::vector<std::string>& GetArgs();

            /**
             * @brief Get function's body
             * 
             */
            const std::vector<std::shared_ptr<Instruction>>& GetBody();

            /**
             * @brief Get function's name 
             * 
             */
            const std::string& GetName();
        };
    }
}

#endif