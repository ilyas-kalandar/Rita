/**
 * @file type.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>

#include "type.hpp"

namespace Core
{
	Type::Type(std::string name) : typeName(name)
	{
		this->refCounter = 0;
		this->objectType = this;
	}

	void Type::AddField(std::string& field, RitaObject* obj)
	{
		this->definedFields[field] = obj;
	}

	RitaObject* Type::GetField(std::string& fieldName)
	{
		return this->definedFields[fieldName];
	}

	const std::map<std::string, RitaObject*>& Type::GetFields()
	{
		return this->definedFields;
	}
}