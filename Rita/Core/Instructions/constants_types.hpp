/**
 * @file constants_types.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Definition of ConstantType
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#ifndef constants_types_hpp
#define constants_types_hpp

namespace Core
{
    namespace Instructions
    {
        enum class ConstantType
        {
            INT, 
            STRING,
            FLOAT,
            LIST,
        };
    }
}

#endif