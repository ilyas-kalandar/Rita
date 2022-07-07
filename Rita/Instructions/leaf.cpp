/**
 * @file leaf.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "leaf.hpp"

Leaf::Leaf(RitaObject* obj)
{
    this->type = InstructionType::LEAF;
    this->obj = obj;
}

RitaObject* Leaf::GetObj()
{
    return this->obj;
}