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

#include "type.hpp"

Type::Type(const std::string& typeName, DataType type)
{
    this->typeName = std::string(std::move(typeName));
    this->type = type;
}
const std::string& Type::GetName() const 
{
    return this->typeName;
}

const DataType& Type::GetDataType() const 
{
    return this->type;
}