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
	Type::Type(const std::string& name, Type* inheritedFrom=nullptr) : RitaObject(this), typeName(name)
	{
		this->refCounter = 0;
		this->inheritedFrom = inheritedFrom;
	}

	const std::string& Type::GetTypeName()
	{
		return this->typeName;
	}

	void Type::AddField(std::string& field, RitaObject* obj)
	{
		this->definedFields[field] = obj;
	}

	RitaObject* Type::GetField(std::string& fieldName)
	{
		// Lookup
		if(this->definedFields.find(fieldName) != this->definedFields.end())
		{
			return this->definedFields[fieldName];
		}

		//lookup base-class for field
		
		if(this->inheritedFrom != nullptr)
		{
			return this->inheritedFrom->GetField(fieldName);
		}

		throw std::runtime_error("Field not found!");
	}

	const std::map<std::string, RitaObject*>& Type::GetFields()
	{
		return this->definedFields;
	}
}