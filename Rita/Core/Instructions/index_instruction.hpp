/**
 * @file index_instruction.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief IndexInstruction definition
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <memory>

#include "instruction.hpp"

#ifndef index_instruction_hpp
#define index_instruction_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing instructions like 
         *      ``x[19]``
         * 
         *  X  ->  value
         *  19 ->  index
         * 
         */
        class IndexInstruction : public Instruction
        {
        protected:
            std::shared_ptr<Instruction> value;
            std::shared_ptr<Instruction> index;
        public:
            /**
             * @brief Construct a new Index Instruction object
             * 
             * @param val 
             * @param index 
             */
            IndexInstruction(std::shared_ptr<Instruction> val, std::shared_ptr<Instruction> index);
            /**
             * @brief Get the Value object
             * 
             * @return std::shared_ptr<Instruction> 
             */
            std::shared_ptr<Instruction> GetValue();
            /**
             * @brief Get the Index object
             * 
             * @return std::shared_ptr<Instruction> 
             */
            std::shared_ptr<Instruction> GetIndex();
        };
    }
}

#endif