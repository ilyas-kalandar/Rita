/**
 * @file func_obj.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief FunctionObject implementation
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "func_obj.hpp"

namespace Core
{
    Function::Function(Instructions::FunctionDefinitionInstruction* fn, Type* type)
        :
        funcDef(fn),
        RitaObject(type)
    {

    }

    Core::Instructions::FunctionDefinitionInstruction* Function::GetFuncDef()
    {
        return funcDef;
    }
}