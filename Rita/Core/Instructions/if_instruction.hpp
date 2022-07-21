/**
 * @file if_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Definition of IfInstruction
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <memory>
#include <vector>

#include "instruction.hpp"

#ifndef if_instruction_hpp
#define if_instruction_hpp

namespace Core
{
    namespace Instructions
    {

        /**
         * @brief Class for storing if statements
         * 
         * For example:
         *      if(a == 3) {
         *          print "hello!";
         *      }
         *      else{
         *          print "bye!"
         *      }
         * 
         *      will be
         *  
         *      IfInstruction(
         *          {
         *          PrintInstruction("hello"),
         *          },
         *          BinOpInstruction("a", "3", EQUAL_EQUAL)
         *      )
         * 
         */
        class IfInstruction : public Instruction
        {
        protected:
            std::shared_ptr<Instruction> expr;
            std::vector<std::shared_ptr<Instruction>> body;
            std::vector<std::shared_ptr<Instruction>> elseBody;
        public:
            /**
             * @brief Construct a new IfInstruction object
             * 
             * @param body vector with instructions
             * @param expr expression which will return boolean value
             */
            IfInstruction(std::vector<std::shared_ptr<Instruction>>& body,std::vector<std::shared_ptr<Instruction>>& elseBody, std::shared_ptr<Instruction> expr);
            /**
             * @brief Get the Expr object
             * 
             * @return std::shared_ptr<Instruction> 
             */
            std::shared_ptr<Instruction> GetExpr();
            /**
             * @brief Get the Body of IfInstruction
             * 
             * @return std::vector<std::shared_ptr<Instruction>> 
             */
            std::vector<std::shared_ptr<Instruction>> GetBody();
        };
    }
}

#endif