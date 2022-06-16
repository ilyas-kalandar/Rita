#pragma once

#include <vector>

#include "token.h"

namespace Lexer
{
    const Token EOF_TOKEN = Token(TokenType::END_OF_FILE);
    
    /// <summary>
    /// Class for containing Token-objects.
    /// </summary>
    class Tokenator
    {
    private:
        std::vector<Token> Tokens;
        size_t currentToken = -1;
    public:
        /// <summary>
        /// Checks for next token
        /// </summary>
        /// <returns>true or false (depends on result)</returns>
        bool HasNext();

        /// <summary>
        /// Returns a const reference to next token, EOF_TOKEN will be returned if there is no token.
        /// </summary>
        /// <returns>Reference to next token</returns>
        const Token& Next();

        /// <summary>
        /// Returns a reference to current token.
        /// </summary>
        /// <returns></returns>
        const Token& Current();

        /// <summary>
        /// Constructor for Tokenator
        /// </summary>
        /// <param name="tokens">Just vector with tokens (will be moved!)</param>
        Tokenator(std::vector<Token>& tokens);
    };
}