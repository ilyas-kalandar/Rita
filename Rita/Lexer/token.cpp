#include <iostream>

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

    const std::string& Token::GetLiteral() const
    {
        return this->Literal;
    }
    
    const TokenType& Token::GetTokenType() const
    {
        return this->Type;
    }

    std::ostream& operator<<(std::ostream& os, const Token& tok)
    {
        os << "Token<" << tok.GetTokenType() << ", " << tok.GetLiteral() << ">";
        return os;
    }
}