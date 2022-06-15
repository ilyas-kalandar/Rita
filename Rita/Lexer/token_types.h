#pragma once

namespace Lexer
{
    enum class TokenType
    {
        // Literals
        INTEGER, 
        FLOAT, 
        STRING, 
        IDENTIFIER,

        // Binary operators
        EQUAL,
        EQUAL_EQUAL, 
        LESS_THAN,
        GREATER_THAN,
        LESS_OR_EQUAL_THAN,
        GREATER_OR_EQUAL_THAN,
        DIVISION,
        MULTIPLY,
        MINUS,
        PLUS,
        
        // Keywords
        IF,
        WHILE,
        FOR,

        // Other
        DOT,
        ENF_OF_FILE
    };
}