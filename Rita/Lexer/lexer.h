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
        
    public:
        /// <summary>
        /// Divide your code into tokens
        /// </summary>
        /// <param name="code">An std::string with your code</param>
        /// <returns>Tokens</returns>
        Tokenator Tokenize(const std::string& code);
    };
}