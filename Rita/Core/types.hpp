/**
 * @file types.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "type.hpp"

#ifndef types_hpp
#define types_hpp

const auto RITA_INT = Type("int", DataType::INT);
const auto RITA_FLOAT = Type("float", DataType::FLOAT);
const auto RITA_STRUCTURE = Type("structure", DataType::STRUCTURE);
const auto RITA_STRING = Type("str", DataType::STRING);
const auto RITA_BOOL = Type("bool", DataType::BOOL);
const auto RITA_LIST = Type("list", DataType::LIST);
const auto RITA_NONE = Type("None", DataType::NONE);

#endif