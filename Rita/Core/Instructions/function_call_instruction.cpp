/**
 * @file function_call_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief FunctionCallInstruction implementation
 * @version 0.1
 * @date 2022-07-16
 * 
 * @copyright Copyright Awaitable(c) 2022
 * 
 */

#include "function_call_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        FunctionCallInstruction::FunctionCallInstruction(const std::string& functionName, const std::vector<std::shared_ptr<Instruction>>& args)
        :
        functionName(functionName), functionArguments(args)
        {
            this->type = InstructionType::FUNCTION_CALL;
        }

        const std::string& FunctionCallInstruction::GetFunctionName()
        {
            return this->functionName;
        }

        const std::vector<std::shared_ptr<Instruction>> FunctionCallInstruction::GetFunctionArguments()
        {
            return this->functionArguments;
        }
    }
}