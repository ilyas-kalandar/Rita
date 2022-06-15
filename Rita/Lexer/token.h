#pragma once

#include <string>
#include <memory>

#include "token_types.h"

namespace Lexer
{
    class Token
    {
    private:
        TokenType Type;
        std::string Literal;
    public:
        /// <summary>
        /// Default constructor
        /// </summary>
        /// <param name="type">Just type of token</param>
        /// <param name="literal">Just literal (will moved!)</param>
        Token(TokenType type, std::string& literal);
        /// <summary>
        /// Constructor without literal
        /// </summary>
        /// <param name="type"></param>
        Token(TokenType type);
        /// <summary>
        /// Get Token's literal
        /// </summary>
        /// <returns>Token's literal</returns>
        const std::string& GetLiteral();
    };
}