/**
 * @file instructions_types.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Implementation of functions declared at instructions_types.hpp
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "rita_exception.hpp"
#include "instructions_types.hpp"

namespace Core
{
    namespace Instructions
    {
        std::ostream& operator <<(std::ostream& os, InstructionType instr_type)
        {
            switch(instr_type)
            {
            case InstructionType::ASSIGNMENT:
                os << "Assignment";
                break;
            case InstructionType::ATTRIBUTE:
                os << "GetAttribute";
                break;
            case InstructionType::BINOP:
                os << "BinaryOperation";
                break;
            case InstructionType::CONSTANT_FLOAT:
                os << "FloatConstant";
                break;
            case InstructionType::IF:
                os << "IfStatement";
                break;
            case InstructionType::CONSTANT_LIST:
                os << "ListConstant";
                break;
            case InstructionType::CONSTANT_INT:
                os << "IntConstant";
                break;
            case InstructionType::FUNCTION_CALL:
                os << "Call";
                break;
            case InstructionType::LEAF:
                os << "Name";
                break;
            case InstructionType::INDEX:
                os << "GetIndex";
                break;
            case InstructionType::CONSTANT_STRING:
                os << "StringConstant";
                break;
            case InstructionType::UNOP:
                os << "UnaryOperation";
                break;
            case InstructionType::VAR_DECL:
                os << "VariableDeclaration";
                break;
            case InstructionType::WHILE:
                os << "WhileStatement";
                break;
            case InstructionType::FUNCTION_DEFINITION:
                os << "FunctionDefinition";
                break;
            default:
                throw Utils::RitaException("ostream operator<<", "Unsupported instruction type: " + std::to_string((int)instr_type));
            }
            return os;
        }
    }
}