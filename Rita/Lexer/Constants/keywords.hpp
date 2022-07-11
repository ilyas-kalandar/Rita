namespace Lexer
{
    const static std::unordered_map<std::string, TokenType> RESERVED_WORDS =
    {
        {"if", TokenType::IF},
        {"else", TokenType::ELSE},
        {"fun", TokenType::FUN},
        {"while", TokenType::WHILE},
        {"print", TokenType::PRINT},
    };
}