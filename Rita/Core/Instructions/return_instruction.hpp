/**
 * @file return_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ReturnInstruction definition.
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <memory>

#include "instruction.hpp"

#ifndef return_instr_hpp
#define return_instr_hpp

namespace Core
{
    namespace Instructions
    {
        class ReturnInstruction : public Instruction
        {
        protected:
            std::shared_ptr<Instruction> expr;
        public:
            /**
             * @brief Construct a new Return Instruction object
             * 
             * @param expr Expression for returning
             */
            ReturnInstruction(std::shared_ptr<Instruction> expr);
            
            /**
             * @brief Get the Expr object
             * 
             * @return std::shared_ptr<Instruction> 
             */
            std::shared_ptr<Instruction> GetExpr();
        };
    }
}

#endif