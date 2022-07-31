namespace Lexer
{
    const static std::unordered_map<std::string, TokenType> RESERVED_WORDS =
    {
        {"if", TokenType::IF},
        {"else", TokenType::ELSE},
        {"fun", TokenType::FUN},
        {"while", TokenType::WHILE},
        {"var", TokenType::VAR},
        {"or", TokenType::OR}, 
        {"and", TokenType::AND},
        {"break", TokenType::BREAK},
        {"return", TokenType::RETURN},
    };
}