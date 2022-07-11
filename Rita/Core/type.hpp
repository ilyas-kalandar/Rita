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

#include "data_types.hpp"

/**
 * @brief 
 * 
 */
class Type
{
private:
    std::string typeName;
    DataType type;
public:
    /**
     * @brief Construct a new Type object
     * 
     * @param typeName 
     * @param type 
     */
    Type(std::string& typeName, DataType type);
    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    const std::string& GetName() const;
    /**
     * @brief Get the Data Type object
     * 
     * @return const DataType& 
     */
    const DataType& GetDataType() const;
};