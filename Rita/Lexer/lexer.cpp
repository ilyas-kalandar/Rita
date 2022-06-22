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

    void Lexer::PushToken(TokenType t = TokenType::END_OF_FILE)
    {
        if (t == TokenType::END_OF_FILE)
        {
            t = currentTokenType;
        }
        parsedTokens.emplace_back(t, currentLexeme, currentLine, currChar);
    }

    bool Lexer::CheckKeyWord(const std::string& keyword)
    {
        size_t offset = 0;
        size_t currentKeywordChar = 0;

        while (currentKeywordChar != keyword.size())
        {
            if (Current() != keyword[currentKeywordChar])
            {
                currChar -= offset;
                return false;
            }

            currentKeywordChar++;
            offset++;
            Next();
        }

        if (std::isalpha(Current()))
        {
            currChar -= offset;
            return false;
        }

        return true;
    }

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
            case TokenType::INTEGER:
            case TokenType::FLOAT:
                if (Current() == '.' && !(currentTokenType == TokenType::FLOAT))
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
        PushToken();
    }

    Tokenator Lexer::Tokenize(std::string& code)
    {
        Reset();

        sourceLength = code.size();
        sourcePointer = &code;

        while (HasNext())
        {
            // Heart of lexer is here, lets check current charachter

            // Firstly, check for keyword

            bool is_keyword = false;

            for (const std::pair<const std::string&, TokenType>& keyword : RESERVED_WORDS)
            {
                if(CheckKeyWord(keyword.first))
                {
                    PushToken(keyword.second);
                    is_keyword = true;
                    break;
                }
            }

            if (is_keyword)
                continue;

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
                case '.':
                    PushToken(TokenType::DOT);
                    break;
                case ')':
                    PushToken(TokenType::RIGHT_PAREN);
                    break;
                case '(':
                    PushToken(TokenType::LEFT_PAREN);
                    break;
                case '+':
                    PushToken(TokenType::PLUS);
                    break;
                case '}':
                    PushToken(TokenType::RIGHT_BRACE);
                    break;
                case '{':
                    PushToken(TokenType::LEFT_BRACE);
                    break;
                case '-':
                    PushToken(TokenType::MINUS);
                    break;
                case '/':
                    PushToken(TokenType::DIVISION);
                    break;
                case '*':
                    PushToken(TokenType::MULTIPLY);
                    break;
                case '>':
                    PushToken(TokenType::GREATER_THAN);
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
                        PushToken(TokenType::EQUAL_EQUAL);
                        Next();
                    }
                    else
                    {
                        PushToken(TokenType::EQUAL);
                    }
                    break;
                default:
                    throw std::runtime_error(
                        "Unknown character passed: \'" + std::to_string(Current()) + "\' (" + std::to_string(currentLine) + "," + std::to_string(currChar) + ")");
                }
                Next();
            }
            
        }
        return Tokenator(Lexer::parsedTokens);
    }
}