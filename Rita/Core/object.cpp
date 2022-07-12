/**
 * @file object.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Implementation of RitaObject
 * @version 0.2
 * @date 2022-07-12
 * 
 * @copyright Awaitable Copyright (c) 2022
 * 
 */

#include <iostream>

#include "object.hpp"

RitaObject::RitaObject() : type(RITA_NONE)
{
	this->referenceCounter = 0;
}

const Type& RitaObject::GetType()
{
	return this->type;
}

const size_t& RitaObject::GetReferenceCount()
{
	return this->referenceCounter;
}

