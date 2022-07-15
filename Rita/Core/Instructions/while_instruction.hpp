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

#ifndef if_instruction_hpp
#define if_instruction_hpp

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
        class WhileInstruction : public IfInstruction
        {
        public:
            /**
             * @brief Construct a new While Instruction object
             * 
             * @param body Vector with instructions of body
             * @param expr Expression for checking
             */
            WhileInstruction(std::vector<std::shared_ptr<Instruction>>& body, std::shared_ptr<Instruction> expr);
        };
    }
}

#endif