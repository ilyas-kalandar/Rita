/**
 * @file types.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Collection of built-in types.
 * @version 0.1
 * @date 2022-07-16
 * 
 * @copyright Awaitable Copyright (c) 2022
 * 
 */

#include "object.hpp"
#include "type.hpp"
#include "constants.hpp"

#ifndef executor_types.hpp
#define executor_types.hpp

namespace Executor
{
    namespace Builtins
    {
        namespace Types
        {
            Core::Type* ObjectType = new Core::Type(Constants::ObjectName, nullptr); 
            Core::Type* StringType = new Core::Type(Constants::StringName, ObjectType);
            Core::Type* IntType = new Core::Type(Constants::IntName, ObjectType);
            Core::Type* BoolType = new Core::Type(Constants::BoolName, ObjectType);
            Core::Type* BuiltinFunctionType = new Core::Type(Constants::BuiltinFunctionName, ObjectType);
        }
    }
}

#endif