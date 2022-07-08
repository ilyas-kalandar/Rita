/**
 * @file lexer.h
 * @author Ilyas (t.me/awaitable)
 * @brief Lexer's definition
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */


#pragma once

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

#include "tokenator.hpp"

namespace Lexer 
{
    class Lexer
    {
    private:
        size_t currChar;
        size_t currentLine;
        size_t sourceLength;

        TokenType currentTokenType;

        std::string givenSource;
        std::string currentLexeme;
        std::vector<Token> parsedTokens;

        /**
         * @brief Resets inner fields
         */
        void Reset();

        /**
         * @brief 
         * 
         * @param t 
         */
        void PushToken(TokenType t);

        /**
         * @brief 
         * 
         * @param keyword 
         * @return true 
         * @return false 
         */
        bool CheckKeyWord(const std::string& keyword);

        /**
         * @brief 
         * 
         */
        void ParseToken();
        
        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        inline bool HasNext();

        /**
         * @brief 
         * 
         */
        inline void Next();

        /**
         * @brief Get the Next object
         * 
         * @return char 
         */
        inline char GetNext();

        /**
         * @brief 
         * 
         * @param ch 
         * @return true 
         * @return false 
         */
        inline bool CheckNext(char ch);

        /**
         * @brief 
         * 
         * @return char 
         */
        inline char Current();
    public:
        /**
         * @brief Tokenize given source
         * 
         * @param code Your source code
         * @return Tokenator 
         */
        Tokenator Tokenize(std::string& code);
    };
}