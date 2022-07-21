/**
 * @file var_decl_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief VariableDeclarationInstruction definition.
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <memory>

#include "instruction.hpp"

#ifndef var_decl_instruction_hpp
#define var_decl_instruction_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing variable-declarations.
         * 
         */
        class VariableDeclarationInstruction : public Instruction
        {
        protected:
            std::string varName;
            std::shared_ptr<Instruction> expr;
        public:
            /**
             * @brief Construct a new Variable Declaration Instruction object
             * 
             * @param varName 
             * @param expr 
             */
            VariableDeclarationInstruction(std::string& varName, std::shared_ptr<Instruction> expr);
            /**
             * @brief Get the Var Name object
             * 
             * @return const std::string& 
             */
            const std::string& GetVarName();
            /**
             * @brief Get the Expression object
             * 
             * @return std::shared_ptr<Instruction> 
             */
            std::shared_ptr<Instruction> GetExpression();
        }
    }
}

#endif