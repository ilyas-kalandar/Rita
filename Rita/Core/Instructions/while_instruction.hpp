/**
 * @file while_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief WhileInstruction definition
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "if_instruction.hpp"

#ifndef while_instruction_hpp
#define while_instruction_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing instructions like:
         *  
         *  while(a > 3) {
         *      print(a);
         *      a = a - 1;
         *  }
         * 
         *  This will be stored like
         *      
         *      WhileInstruction(
         *          {
         *              PrintInstruction(a),
         *              AssignmentInstruction(a, BinOpInstruction(a, 1, -)),
         *          },
         *          BinOpInstruction(a, 3, >)
         *      )
         * 
         */
        class WhileInstruction : public Instruction
        {
        protected:
            std::vector<std::shared_ptr<Instruction>> body;
            std::shared_ptr<Instruction> expr;
        public:
            /**
             * @brief Construct a new While Instruction object
             * 
             * @param body Vector with instructions of body
             * @param expr Expression for checking
             */
            WhileInstruction(std::vector<std::shared_ptr<Instruction>>& body, std::shared_ptr<Instruction> expr);

            /**
             * @brief Get the Body object
             * 
             * @return const std::vector<std::shared_ptr<Instruction>>& 
             */
            const std::vector<std::shared_ptr<Instruction>>& GetBody();

            /**
             * @brief Get the Expression object
             * 
             * @return std::shared_ptr<Instruction> 
             */
            std::shared_ptr<Instruction> GetExpression();
        };
    }
}

#endif