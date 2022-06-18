#include <stdexcept>

#include "lexer.h"
#include "tokenator.h"


namespace Lexer
{
    size_t Lexer::currentLine;
    size_t Lexer::currChar;
    size_t Lexer::sourceLength;

    std::string* Lexer::sourcePointer;
    std::string Lexer::currentLexeme;
    TokenType Lexer::currentTokenType;
    std::vector<Token> Lexer::parsedTokens;

    void Lexer::Reset()
    {
        currChar = 0;
        currentLine = 1;
    }

    inline char Lexer::Current()
    {
        return (*sourcePointer)[currChar];
    }

    inline bool Lexer::HasNext()
    {
        return currChar < sourceLength;
    }

    inline char Lexer::GetNext()
    {
        if (!HasNext()) 
            return '\0';
        return (*sourcePointer)[currChar + 1];
    }

    inline bool Lexer::CheckNext(char ch) 
    {
        return GetNext() == ch;
    }

    void Lexer::Next()
    {
        if (HasNext())
        {
            currChar++;
        }
    }

    void Lexer::ParseToken()
    {

        bool working = true;

        while (Current() != '\0')
        {
            switch (Lexer::currentTokenType)
            {
            case TokenType::STRING:
                switch (Current())
                {
                case '\"':
                    working = false;
                    break;
                case '\n':
                    //TODO(Ilyas): Throw exception
                    break;
                }
                break;
            case TokenType::IDENTIFIER:
                // TODO 
                break;
            //TODO(Ilyas): Add another here
            }

            if (!working)
            {
                /*
                * Maybe here will be something like 
                *    
                *       Lexer::Next();
                * 
                */
                break;
            }
            
            currentLexeme.push_back(Current());
            Next();
        }
        parsedTokens.emplace_back(currentTokenType, currentLexeme);
    }

    Tokenator Lexer::Tokenize(std::string& code)
    {
        Reset();

        sourceLength = code.size();
        sourcePointer = &code;

        while (HasNext())
        {
            // Heart of lexer is here, lets check current charachter

            if (std::isalpha(code[currChar]))
            {
                /*
                * If some alha passed, we parse it as an IDENTIFIER
                */
                currentTokenType = TokenType::IDENTIFIER;
            }
            ParseToken();
        }

        return Tokenator(Lexer::parsedTokens);
    }
}