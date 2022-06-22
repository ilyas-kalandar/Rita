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
        size_t line;
        size_t character;
    public:
        /// <summary>
        /// Default constructor
        /// </summary>
        /// <param name="type">Just type of token</param>
        /// <param name="literal">Just literal (will moved!)</param>
        /// <param name="line">Just line, where token located</param>
        /// <param name="character">Character</param>
        Token(TokenType type, std::string& literal, size_t line, size_t character);
        /// <summary>
        /// Constructor without literal
        /// </summary>
        /// <param name="type">Type of token</param>
        /// <param name="line">Line where token located</param>
        /// <param name="character">Character</param>
        Token(TokenType type, size_t line, size_t character);
        /// <summary>
        /// Get Token's literal
        /// </summary>
        /// <returns>Token's literal</returns>
        const std::string& GetLiteral() const;  

        /// <summary>
        /// Returns type of token
        /// </summary>
        /// <returns></returns>
        const TokenType& GetTokenType() const;

        const size_t& GetLine() const;

        const size_t& GetCharacter() const;
    };

    const Token EOF_TOKEN = Token(TokenType::END_OF_FILE, 0, 0);
    
    std::ostream& operator<<(std::ostream& os, const Token& tok);
}