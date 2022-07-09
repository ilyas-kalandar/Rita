/**
 * @file data_types.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Data types definition
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#ifndef data_types_hpp
#define data_types_hpp

enum class DataType
{
    // Native types
    INT,
    FLOAT,
    BOOL,
    STRING, 

    // Complex-types.
    STRUCTURE, 
    LIST,
    NONE,
};

#endif