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
                    throw std::runtime_error("Expected '\"', but found '\\n' (" + std::to_string(currentLine) + "," + std::to_string(currChar) + ")");
                    break;
                }
                break;
            case TokenType::IDENTIFIER:
                if (Current() == ' ' || Current() == '\n')
                {
                    working = false;
                }
                break;
                //TODO(Ilyas): Add another here
            case TokenType::INTEGER:
            case TokenType::FLOAT:
                if (Current() == '.' && currentTokenType == TokenType::FLOAT)
                {
                    /*
                    * If some integer contains dot, parse it as float
                    */
                    currentTokenType = TokenType::FLOAT;
                }
                else if (!std::isdigit(Current()))
                {
                    working = false;
                }
                break;
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

            if (std::isalpha(Current()))
            {
                /*
                * If some alha passed, we parse it as an IDENTIFIER
                */
                currentTokenType = TokenType::IDENTIFIER;
                ParseToken();
            }
            else if (std::isdigit(Current()))
            {
                /*
                * If some number passed, parse it as some INTEGER (or FLOAT)
                *
                */
                currentTokenType = TokenType::INTEGER;
                ParseToken();
            }
            else
            {
                switch (Current())
                {
                case ' ':
                    break;
                case '\n':
                    currentLine++;
                    break;
                case '+':
                    parsedTokens.emplace_back(Token(TokenType::PLUS));
                    break;
                case '-':
                    parsedTokens.emplace_back(Token(TokenType::MINUS));
                    break;
                case '/':
                    parsedTokens.emplace_back(Token(TokenType::DIVISION));
                    break;
                case '*':
                    parsedTokens.emplace_back(Token(TokenType::MULTIPLY));
                    break;
                case '\"':
                    currentTokenType = TokenType::STRING;
                    Next();
                    ParseToken();
                    break;
                case '=':
                    // Check for EQUAL_EQUAL
                    if (CheckNext('='))
                    {
                        parsedTokens.emplace_back(Token(TokenType::EQUAL_EQUAL));
                        Next();
                    }
                    else
                    {
                        parsedTokens.emplace_back(Token(TokenType::EQUAL));
                    }
                    break;
                default:
                    std::cout << "WHAT? " << Current() << std::endl;
                }
                Next();
            }
            
        }
        return Tokenator(Lexer::parsedTokens);
    }
}