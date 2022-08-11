/**
 * @file bool_obj.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "bool_obj.hpp"
#include "type.hpp"

namespace Core
{
    BoolObject::BoolObject(bool val,  Type* type)
        :
        RitaObject(type)
    {
        this->val = val;
    }

    bool BoolObject::GetValue()
    {
        return val;
    }

    void BoolObject::SetValue(bool val)
    {
        this->val = val;
    }
}