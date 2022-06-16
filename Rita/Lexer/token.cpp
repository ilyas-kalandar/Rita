#include "token.h"

namespace Lexer
{
    Token::Token(TokenType type, std::string& literal) : Literal(std::move(literal))
    {
        this->Type = type;
    }

    Token::Token(TokenType type)
    {
        this->Type = type;
    }

    const std::string& Token::GetLiteral()
    {
        return this->Literal;
    }
}