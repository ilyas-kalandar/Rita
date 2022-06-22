#include <iostream>

#include "token.h"

namespace Lexer
{
    Token::Token(TokenType type, std::string& literal, size_t line, size_t character) : Literal(std::move(literal))
    {
        this->Type = type;
        this->line = line;
        this->character = character;
    }

    Token::Token(TokenType type, size_t line, size_t character)
    {
        this->Type = type;
        this->line = line;
        this->character = character;
    }

    const std::string& Token::GetLiteral() const
    {
        return this->Literal;
    }
    
    const TokenType& Token::GetTokenType() const
    {
        return this->Type;
    }

    const size_t& Token::GetLine() const
    {
        return this->line;
    }

    const size_t& Token::GetCharacter() const
    {
        return this->character;
    }
    
    std::ostream& operator<<(std::ostream& os, const Token& tok)
    {
        os << "Token<" << tok.GetTokenType() << ", " << tok.GetLiteral() << ", (" << tok.GetLine() << "," << tok.GetCharacter() << ")" << ">";
        return os;
    }
}