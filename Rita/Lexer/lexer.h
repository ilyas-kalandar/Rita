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
        static size_t sourceLength;

        static TokenType currentTokenType;

        static std::string currentLexeme;
        static std::string* sourcePointer;

        static std::vector<Token> parsedTokens;

        /// <summary>
        /// Resets inner fields
        /// </summary>
        static void Reset();

        /// <summary>
        /// Pushes token into <c>arsedTokens</c>
        /// </summary>
        static void PushToken(TokenType t);

        /// <summary>
        /// Parses a token and pushes it to parsedTokens vector.
        /// </summary>
        static void ParseToken();
        
        /// <summary>
        /// Checks for next character
        /// <returns>True/False depend on result</returns>
        /// </summary>
        static inline bool HasNext();

        /// <summary>
        /// Moves currChar's pointer to right (if possible)
        /// </summary>
        static inline void Next();

        /// <summary>
        /// Get next char
        /// </summary>
        /// <returns>Next charater, <c>'\0'</c> if source handled.</returns>
        static inline char GetNext();

        /// <summary>
        /// Checks for <code>GetNext() == ch</code>
        /// </summary>
        static inline bool CheckNext(char ch);

        /// <summary>
        /// Get current character
        /// </summary>
        /// <returns></returns>
        static inline char Current();
    public:
        /// <summary>
        /// Divide your code into tokens
        /// </summary>
        /// <param name="code">An std::string with your code</param>
        /// <returns>Tokens</returns>
        static Tokenator Tokenize(std::string& code);
    };
}