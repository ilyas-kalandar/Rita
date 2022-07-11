#pragma once

#include <iostream>

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

        // Parens

        RIGHT_PAREN,
        LEFT_PAREN,

        // Braces
        LEFT_BRACE,
        RIGHT_BRACE,

        // Keywords
        FUN, 
        IF,
        ELSE,
        WHILE,
        FOR,
        PRINT,

        // Other
        DOT,
        END_OF_FILE
    };

    /*
    * Needed for using this Enum with <code>cout</code>
    */
    std::ostream& operator<<(std::ostream& os, TokenType type);
}