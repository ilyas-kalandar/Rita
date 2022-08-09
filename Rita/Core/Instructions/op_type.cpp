#include <iostream>
#include <string>

#include "rita_exception.hpp"
#include "op_type.hpp"

namespace Core
{
    namespace Instructions
    {
        std::ostream& operator<<(std::ostream& os, OpType op)
        {
            switch(op)
            {
            case OpType::AND:
                os << "And &&";
                break;
            case OpType::DIV:
                os << "Divide /";
                break;
            case OpType::LESS_OR_EQUAL_THAN:
                os << "Less or equal <=";
                break;
            case OpType::EQUAL_EQUAL:
                os << "Equal-equal ==";
                break;
            case OpType::PLUS:
                os << "Plus +";
                break;
            case OpType::MUL:
                os << "Multiply *";
                break;
            case OpType::NOT:
                os << "Not !";
                break;
            case OpType::GREATER_OR_EQUAL_THAN:
                os << "Greater or equal >=";
                break;
            case OpType::MINUS:
                os << "Minus -";
                break;
            case OpType::GREATER_THAN:
                os << "Greater than >";
                break;
            default:
                throw Utils::RitaException(
                    "ostream& operator<<(ostream, OpType)",
                    "Unsupported OpType " + std::to_string((int)op)
                );
            }
            return os;
        }
    }
}