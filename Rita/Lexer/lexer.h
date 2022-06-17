#pragma once

#include <vector>
#include <memory>
#include <string>

#include "tokenator.h"

namespace Lexer 
{
    class Lexer
    {
    private:
        size_t currChar = -1;
        size_t currentLine = 0;
        TokenType currentTokenType;

        std::string& source;
        std::string currentLexeme;

        std::vector<Token> parsedTokens;

        /// <summary>
        /// Resets inner fields
        /// </summary>
        void Reset();

        /// <summary>
        /// Parses a token and pushes it to parsedTokens vector.
        /// </summary>
        void ParseToken();
    public:
        /// <summary>
        /// Divide your code into tokens
        /// </summary>
        /// <param name="code">An std::string with your code</param>
        /// <returns>Tokens</returns>
        Tokenator Tokenize(std::string& code);
    };
}