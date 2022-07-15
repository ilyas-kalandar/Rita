/**
 * @file string_obj.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief String-object implementation.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "string_obj.hpp"
#include "type.hpp"

namespace Core
{
    String::String(std::string val, Type* type) : RitaObject(type), value(val)
    {
    }

    const std::string& String::GetValue()
    {
        return this->value;
    }
}