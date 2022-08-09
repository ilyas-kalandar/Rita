/**
 * @file function_definition.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief FunctionDefinitionInstruction implementation
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "function_definition.hpp"

namespace Core
{
    namespace Instructions
    {
        FunctionDefinitionInstruction::FunctionDefinitionInstruction(std::string& name, std::vector<std::string>& args, std::vector<std::shared_ptr<Instruction>>& body)
            :
            name(std::move(name)), args(std::move(args)), body(std::move(body))
        {
            type = InstructionType::FUNCTION_DEFINITION;
        }

        std::vector<std::shared_ptr<Core::Instructions::Instruction>>& FunctionDefinitionInstruction::GetBody()
        {
            return body;
        }

        const std::vector<std::string>& FunctionDefinitionInstruction::GetArgs()
        {
            return args;
        }


        const std::string& FunctionDefinitionInstruction::GetName()
        {
            return name;
        }
    }
}