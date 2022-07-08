/**
 * @file token.h
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Token definition
 * @version 0.1
 * @date 2022-06-08
 * 
 * @copyright Copyright Awaitable(c) 2022
 * 
 */

#include <string>
#include <memory>

#include "token_types.hpp"

#ifndef token_hpp
#define token_hpp

namespace Lexer
{
    /**
     * @brief Class which represents a token, contains data like:
     *        Type - type of token
     *        Literal 
     *        Line
     *        Character
     */
    class Token
    {
    private:
        TokenType Type;
        std::string Literal;
        size_t line;
        size_t character;
    public:
        /**
         * @brief Construct a new Token object
         * 
         * @param type Type of token
         * @param literal Just string with literal
         * @param line Line of token
         * @param character Character of token.
         */
        Token(TokenType type, std::string& literal, size_t line, size_t character);
        /**
         * @brief Construct a new Token object
         * 
         * @param type Type of token
         * @param line Line of token
         * @param character Character of token
         */
        Token(TokenType type, size_t line, size_t character);
        /**
         * @brief Get the Literal of token
         * 
         * @return const std::string& 
         */
        const std::string& GetLiteral() const;  

        /**
         * @brief Get the type of token
         * 
         * @return const TokenType& 
         */
        const TokenType& GetTokenType() const;

        /**
         * @brief Get the Line of token
         * 
         * @return const size_t& 
         */
        const size_t& GetLine() const;

        /**
         * @brief Get the Character of token
         * 
         * @return const size_t& 
         */
        const size_t& GetCharacter() const;
    };

    const Token EOF_TOKEN = Token(TokenType::END_OF_FILE, 0, 0);
    
    std::ostream& operator<<(std::ostream& os, const Token& tok);
}

#endif