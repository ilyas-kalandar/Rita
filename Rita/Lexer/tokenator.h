#pragma once

#include <vector>

#include "token.h"

namespace Lexer
{
    const Token EOF_TOKEN(TokenType::ENF_OF_FILE);

    class Tokenator
    {
    private:
        std::vector<Token> Tokens;
        size_t currentToken = -1;
    public:
        bool HasNext();
        Token& Next();
        Token& Current();
        Tokenator(std::vector<Token> tokens);
    };
}