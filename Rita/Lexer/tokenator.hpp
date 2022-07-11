/**
 * @file tokenator.h
 * @author Ilyas (t.me/awaitable)
 * @brief Just Tokenator declaration.
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) Awaitable (Ilyas) 2022
 * 
 */

#pragma once

#include <vector>

#include "token.hpp"

namespace Lexer
{
    /**
     * @brief Just class for containing tokens 
     * You can use Current, Next and HasNext methods for iterating through Tokens.
     */
    class Tokenator
    {
    private:
        std::vector<Token> Tokens;
        size_t currentToken = -1;
    public:
        /**
         * @brief Check for next Token
         * 
         * @return true If token exist
         * @return false If token does not exist (EOF)
         */
        bool HasNext();

        /**
        * @brief Checks next token
        *
        * @return true If next's token's type is ``tokenType``
        * @return false If next's token's type is not ``tokenType``
        */
        bool CheckNext(const TokenType tokenType);
        

        /**
         * @brief Get next Token
         * 
         * @return const Token& Just next token
         */
        const Token& Next();

        /**
         * @brief Get current token
         * 
         * @return const Token& Current token
         */
        const Token& Current();

        /**
         * @brief Construct a new Tokenator object
         * 
         * @param tokens Your tokens (warning, will be moved!)
         */
        Tokenator(std::vector<Token>& tokens);

        /**
         * @brief Construct a new Tokenator object (with empty tokens vector)
         * 
         */
        Tokenator();
    };
}