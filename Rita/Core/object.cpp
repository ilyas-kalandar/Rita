/**
 * @file object.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#include "object.hpp"

RitaObject::RitaObject()
{
    this->type = RITA_NONE;
}
RitaObject::RitaObject(bool data)
{
    this->data = data;
    this->type = RITA_BOOL;
}
RitaObject::RitaObject(int data)
{
    this->data = data;
    this->type = RITA_INT;
}
RitaObject::RitaObject(double data)
{
    this->data = data;
    this->type = RITA_FLOAT;
}
RitaObject::RitaObject(const std::string& data)
{
    this->data = std::string(std::move(data));
    this->type = RITA_STRING;
}
RitaObject::RitaObject(const std::vector<RitaObject> vec)
{
    this->arr = std::vector<RitaObject>(std::move(vec));
    this->type = RITA_LIST;
}
RitaObject::RitaObject(const std::map<std::string, RitaObject>& flds)
{
    this->type = RITA_STRUCTURE;
    this->fields = std::map<std::string, RitaObject>(std::move(flds));
}
void RitaObject::PushBack(RitaObject& obj)
{
    obj.referenceCounter++;
    this->arr.push_back(obj);
}
RitaObject* RitaObject::Plus(RitaObject& another)
{
    if(another.type.GetDataType() != this->type.GetDataType())
    {
        throw std::exception();
    }
    switch(this->type.GetDataType())
    {
    case DataType::LIST:
    case DataType::NONE:
    case DataType::STRUCTURE:
    case DataType::BOOL:
        throw std::exception();
    case DataType::FLOAT:
        return new RitaObject(std::get<double>(this->data) + std::get<double>(another.data));
    case DataType::INT:
        return new RitaObject(std::get<int>(this->data) + std::get<int>(another.data));
    case DataType::STRING:
        return new RitaObject(std::get<std::string>(this->data) + std::get<std::string>(another.data));
    default:
        throw std::exception();
    }
}

RitaObject* RitaObject::Minus(RitaObject& another)
{
    if(another.type.GetDataType() != this->type.GetDataType())
    {
        throw std::exception();
    }
    switch(this->type.GetDataType())
    {
    case DataType::LIST:
    case DataType::NONE:
    case DataType::STRUCTURE:
    case DataType::BOOL:
    case DataType::STRING:
        throw std::exception();
    case DataType::FLOAT:
        return new RitaObject(std::get<double>(this->data) - std::get<double>(another.data));
    case DataType::INT:
        return new RitaObject(std::get<int>(this->data) - std::get<int>(another.data));
    default:
        throw std::exception();
    }
}

RitaObject* RitaObject::Multiply(RitaObject& another)
{
    if(another.type.GetDataType() != this->type.GetDataType())
    {
        throw std::exception();
    }
    switch(this->type.GetDataType())
    {
    case DataType::LIST:
    case DataType::NONE:
    case DataType::STRUCTURE:
    case DataType::BOOL:
    case DataType::STRING:
        throw std::exception();
    case DataType::FLOAT:
        return new RitaObject(std::get<double>(this->data) * std::get<double>(another.data));
    case DataType::INT:
        return new RitaObject(std::get<int>(this->data) * std::get<int>(another.data));
    default:
        throw std::exception();
    }
}

RitaObject* RitaObject::Divide(RitaObject& another)
{
    if(another.type.GetDataType() != this->type.GetDataType())
    {
        throw std::exception();
    }
    switch(this->type.GetDataType())
    {
    case DataType::LIST:
    case DataType::NONE:
    case DataType::STRUCTURE:
    case DataType::BOOL:
    case DataType::STRING:
        throw std::exception();
    case DataType::FLOAT:
        return new RitaObject(std::get<double>(this->data) / std::get<double>(another.data));
    case DataType::INT:
        return new RitaObject(std::get<int>(this->data) / std::get<int>(another.data));
    default:
        throw std::exception();
    }
}

std::string RitaObject::ToString()
{
    std::string rt;
    switch(this->type.GetDataType())
    {
    case DataType::BOOL:
        if(std::get<bool>(this->data))
        {
            return "true";
        }
        return "false";
    case DataType::FLOAT:
        return std::to_string(std::get<double>(this->data));
    case DataType::STRING:
        return std::get<std::string>(this->data);
    case DataType::INT:
        return std::to_string(std::get<int>(this->data));
    case DataType::LIST:
        rt += "List[";
        for(size_t i = 0; i < this->arr.size(); ++i)
        {
            rt += arr[i].ToString();
            if(i != arr.size() - 1)
            {
                rt += ", ";
            }
        }
        rt += "]";
        return rt;
    case DataType::STRUCTURE:
        return  "Structure";
    }
    return "obj";
}

RitaObject* RitaObject::Greater(RitaObject& another)
{

    if(this->type.GetDataType() != another.type.GetDataType())
    {
        throw std::runtime_error("Runtime error, can't check different types!");
    }

    switch(this->type.GetDataType())
    {
    case DataType::BOOL:
        return new RitaObject(std::get<bool>(this->data) > std::get<bool>(another.data));
    case DataType::INT:
        return new RitaObject(std::get<int>(this->data) > std::get<int>(another.data));
    case DataType::FLOAT:
        return new RitaObject(std::get<double>(this->data) > std::get<double>(another.data));
    default:
        throw std::runtime_error("Using '>' operator for unsupported type!");
    }
}

// TODO(Ilyas) : Implement later

// RitaObject* RitaObject::Smaller(RitaObject& another);
// RitaObject* RitaObject::GreaterOrEqual(RitaObject& another);
// RitaObject* RitaObject::SmallerOrEqual(RitaObject& another);
// RitaObject* RitaObject::Equals(RitaObject& another);