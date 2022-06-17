#include <stdexcept>

#include "lexer.h"
#include "tokenator.h"


namespace Lexer
{
    size_t Lexer::currentLine;
    size_t Lexer::currChar;


    /*
    * I need make Lexer::Lexer non-static
    * This code absolutely crashed.
    * 
    * Why Lexer::Lexer must be non-static?
    * 
    * 
    * Because in C++, fucking references must be initialized, but I can't initialize Lexer::source without constructor!
    * 
    */

    std::string& Lexer::source;
    std::string Lexer::currentLexeme;    
    TokenType Lexer::currentTokenType;
    std::vector<Token> Lexer::parsedTokens;

    void Lexer::Reset()
    {
        currChar = 0;
        currentLine = 1;
    }

    void Lexer::ParseToken()
    {
        bool working = true;

        while (true)
        {
            switch (currentTokenType)
            {
            case TokenType::STRING:
                switch (source[currChar])
                {
                case '\"':
                    working = false;
                    break;
                case '\n':
                    currentLine++;
                    throw std::runtime_error("Parsing error, expected '\"', found '\\n'");
                }
                break;
            case TokenType::IDENTIFIER:
                if (!isalnum(source[currChar]))
                {
                    working = false;
                }
                break;
            case TokenType::FLOAT:
                //TODO
                break;
            case TokenType::INTEGER:
                //todo
                break;
            }

            if (!working)
                break;

            currentLexeme.push_back(source[currChar]);
            currChar++;
        }
        parsedTokens.emplace_back(currentTokenType, currentLexeme);
    }

    Tokenator Lexer::Tokenize(std::string& code)
    {
        Reset();
        source = code; // not copy, just reference creation.
        
        while (currChar < code.size())
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

        return Tokenator(parsedTokens);
    }
}