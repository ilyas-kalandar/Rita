/**
 * @file leaf.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Instruction's leaf definition
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "instruction.hpp"
#include "../object.hpp"

#ifndef leaf_hpp
#define leaf_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing Objects into instructions.
         * 
         */
        class Leaf : public Instruction
        {
        private: 
            RitaObject* obj;
        public:
            /**
             * @brief Construct a new Leaf object
             * 
             * @param obj Object for storing
             */
            Leaf(RitaObject* obj);
            /**
             * @brief Get the stored object
             * 
             * @return RitaObject* 
             */
            RitaObject* GetObj();
        };
    }
}

#endif