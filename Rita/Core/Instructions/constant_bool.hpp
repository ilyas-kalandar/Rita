/**
 * @file constant_bool.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantBool definition.
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright Awaitable (Ilyas Qalandarzoda) (c) 2022
 * 
 */

#include "instruction.hpp"

#ifndef constant_bool_hpp
#define constant_bool_hpp

namespace Core
{
    namespace Instructions
    {
        class ConstantBool : public Instruction
        {
        protected:
            bool data;
        public:
            /**
             * @brief Construct a new Constant Bool object
             * 
             * @param data 
             */
            ConstantBool(bool data);

            /**
             * @brief Get the Data object
             * 
             * @return true 
             * @return false 
             */
            bool GetData();
        };
    }
}
#endif