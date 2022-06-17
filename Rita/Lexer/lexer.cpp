#include "lexer.h"
#include "tokenator.h"

namespace Lexer
{
    void Lexer::Reset()
    {
        this->currChar = 0;
        this->currentLine = 1;
    }

    void Lexer::ParseToken()
    {
        while (true)
        {
            switch (this->currentTokenType)
            {
            case TokenType::STRING:
                //TODO
                break;
            }
        }
    }

    Tokenator Lexer::Tokenize(std::string& code)
    {
        this->Reset();
        this->source = code; // not copy, just reference creation.
        
        while (this->currChar < code.size())
        {
            // Heart of lexer is here, lets check current charachter

            if (std::isalpha(code[this->currChar]))
            {
                /*
                * If some alha passed, we parse it as an IDENTIFIER
                */
                this->currentTokenType = TokenType::IDENTIFIER;
            }
            this->ParseToken();
        }
    }
}