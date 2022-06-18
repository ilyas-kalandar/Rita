#include "tokenator.h"

namespace Lexer
{
    Tokenator::Tokenator(std::vector<Token>& vec) : Tokens(std::move(vec))
    {
        /*
        * If received vector's size is equals to zero, we don't have next token
        * So, I need set this->currentToken to zero, because by default it has been set to -1
        */
        
        this->currentToken = 0;
    }
    
    const Token& Tokenator::Current()
    {
        if (this->currentToken == Tokens.size())
            return EOF_TOKEN;
        return this->Tokens[this->currentToken];
    }

    bool Tokenator::HasNext()
    {
        return this->currentToken < this->Tokens.size();
    }

    const Token& Tokenator::Next()
    {
        if (this->HasNext())
        {
            return this->Tokens[++this->currentToken];
        }
        return EOF_TOKEN;
    }
}