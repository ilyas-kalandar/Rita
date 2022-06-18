#include "token_types.h"

namespace Lexer
{
    std::ostream& operator<<(std::ostream& os, TokenType type)
    {
        switch (type)
        {
        case TokenType::DIVISION:
            os << "DIVISION";
            break;
        case TokenType::DOT:
            os << "DOT";
            break;
        case TokenType::END_OF_FILE:
            os << "END_OF_FILE";
            break;
        case TokenType::EQUAL:
            os << "EQUAL";
            break;
        case TokenType::EQUAL_EQUAL:
            os << "EQUAL_EQUAL";
            break;
        case TokenType::FLOAT:
            os << "FLOAT";
            break;
        case TokenType::FOR:
            os << "FOR";
            break;
        case TokenType::GREATER_OR_EQUAL_THAN:
            os << "GREATER_OR_EQUAL_THAN";
            break;
        case TokenType::GREATER_THAN:
            os << "GREATER_THAN";
            break;
        case TokenType::IDENTIFIER:
            os << "IDENTIFIER";
            break;
        case TokenType::IF:
            os << "IF";
            break;
        case TokenType::INTEGER:
            os << "INTEGER";
            break;
        case TokenType::MINUS:
            os << "MINUS";
            break;
        case TokenType::MULTIPLY:
            os << "MUL";
            break;
        case TokenType::PLUS:
            os << "PLUS";
            break;
        case TokenType::WHILE:
            os << "WHILE";
            break;
        case TokenType::STRING:
            os << "STRING";
            break;
        case TokenType::LESS_THAN:
            os << "LESTT_THAN";
            break;
        case TokenType::LESS_OR_EQUAL_THAN:
            os << "LESS_OR_EQUAL_THAN";
            break;
        default:
            os << "Unknown token!";
        }
        return os;
    }
}