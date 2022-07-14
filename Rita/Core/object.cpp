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

namespace Core
{
	size_t RitaObject::GetRefCount()
	{
		return this->refCounter;
	}

	RitaObject* RitaObject::GetType()
	{
		return this->objectType;
	}
}