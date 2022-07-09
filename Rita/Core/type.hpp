/**
 * @file type.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once


#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <variant>

enum class DataType
{
    INT,
    FLOAT,
    BOOL,
    STRING, 
    STRUCTURE, 
    LIST,
    NONE,
};

class Type
{
private:
    std::string typeName;
    DataType type;
public:
    Type(const std::string& typeName, DataType type)
    {
        this->typeName = std::string(std::move(typeName));
        this->type = type;
    }
    const std::string& GetName() const 
    {
        return this->typeName;
    }
    
    const DataType& GetDataType() const 
    {
        return this->type;
    }
};

const auto RITA_INT = Type("int", DataType::INT);
const auto RITA_FLOAT = Type("float", DataType::FLOAT);
const auto RITA_STRUCTURE = Type("structure", DataType::STRUCTURE);
const auto RITA_STRING = Type("str", DataType::STRING);
const auto RITA_BOOL = Type("bool", DataType::BOOL);
const auto RITA_LIST = Type("list", DataType::LIST);
const auto RITA_NONE = Type("None", DataType::NONE);

class RitaObject
{
    std::variant<int, double, std::string, bool> data;
    size_t referenceCounter = 0;
    Type type = RITA_NONE;
    std::map<std::string, RitaObject> fields;
    std::vector<RitaObject> arr;
public:
    RitaObject()
    {
        this->type = RITA_NONE;
    }
    RitaObject(int data)
    {
        this->data = data;
        this->type = RITA_INT;
    }
    RitaObject(double data)
    {
        this->data = data;
        this->type = RITA_FLOAT;
    }
    RitaObject(const std::string& data)
    {
        this->data = std::string(std::move(data));
        this->type = RITA_STRING;
    }
    RitaObject(const std::vector<RitaObject> vec)
    {
        this->arr = std::vector<RitaObject>(std::move(vec));
        this->type = RITA_LIST;
    }
    RitaObject(const std::map<std::string, RitaObject>& flds)
    {
        this->type = RITA_STRUCTURE;
        this->fields = std::map<std::string, RitaObject>(std::move(flds));
    }
    void PushBack(RitaObject& obj)
    {
        obj.referenceCounter++;
        this->arr.push_back(obj);
    }
    RitaObject* Plus(RitaObject& another)
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

    RitaObject* Minus(RitaObject& another)
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

    RitaObject* Multiply(RitaObject& another)
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

    RitaObject* Divide(RitaObject& another)
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
    
    std::string ToString()
    {
        std::string rt;
        switch(this->type.GetDataType())
        {
        case DataType::BOOL:
            return std::to_string(std::get<bool>(this->data));
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
};