#include "string_obj.hpp"
#include "type.hpp"

String::String(std::string val, Type* type) : value(val)
{
    this->objectType = type;
}

const std::string& String::GetValue()
{
    return this->value;
}
