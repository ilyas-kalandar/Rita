/**
 * @file constant_string.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantString definition.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "instruction.hpp"

#ifndef constant_string_hpp
#define constant_string_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing string into instruction
         * 
         */
        class ConstantString : public Instruction
        {
        protected:
            std::string data;
        public:
            /**
             * @brief Construct a new Constant String object
             * 
             * @param str 
             */
            ConstantString(const std::string& str);

            /**
             * @brief Get the Data object
             * 
             * @return const std::string& 
             */
            const std::string& GetData();
        };
    }
}

#endif