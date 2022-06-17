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
        static size_t currChar;
        static size_t currentLine;
        static TokenType currentTokenType;

        static std::string& source;
        static std::string currentLexeme;

        static std::vector<Token> parsedTokens;

        /// <summary>
        /// Resets inner fields
        /// </summary>
        static void Reset();

        /// <summary>
        /// Parses a token and pushes it to parsedTokens vector.
        /// </summary>
        static void ParseToken();
    public:
        /// <summary>
        /// Divide your code into tokens
        /// </summary>
        /// <param name="code">An std::string with your code</param>
        /// <returns>Tokens</returns>
        static Tokenator Tokenize(std::string& code);
    };
}