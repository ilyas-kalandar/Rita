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
        FunctionCallInstruction::FunctionCallInstruction(std::shared_ptr<Core::Instructions::Instruction> func, const std::vector<std::shared_ptr<Instruction>>& args)
        :
        func(func), functionArguments(std::move(args))
        {
            this->type = InstructionType::FUNCTION_CALL;
        }

        std::shared_ptr<Core::Instructions::Instruction> FunctionCallInstruction::GetFunction()
        {
            return this->func;
        }

        const std::vector<std::shared_ptr<Instruction>> FunctionCallInstruction::GetFunctionArguments()
        {
            return this->functionArguments;
        }
    }
}