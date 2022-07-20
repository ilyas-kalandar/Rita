#include "constant_string.hpp"

namespace Core
{
    namespace Instructions
    {
        ConstantString::ConstantString(const std::string& str) : data(std::move(str))
        {
            this->type = InstructionType::CONSTANT_STRING;
        }

        const std::string& ConstantString::GetData()
        {
            return this->data;
        }
    }
}