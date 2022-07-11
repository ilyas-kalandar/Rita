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

const auto RITA_INT = Type(std::string("int"), DataType::INT);
const auto RITA_FLOAT = Type(std::string("float"), DataType::FLOAT);
const auto RITA_STRUCTURE = Type(std::string("structure"), DataType::STRUCTURE);
const auto RITA_STRING = Type(std::string("str"), DataType::STRING);
const auto RITA_BOOL = Type(std::string("bool"), DataType::BOOL);
const auto RITA_LIST = Type(std::string("list"), DataType::LIST);
const auto RITA_NONE = Type(std::string("None"), DataType::NONE);

#endif