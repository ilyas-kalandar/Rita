#include <functional>
#include <iostream>

#include "object.hpp"
#include "lexer.hpp"
#include "type.hpp"
#include "Instructions/binop_instruction.hpp"
#include "native_function.hpp"
#include "Instructions/leaf.hpp"
#include "parser.hpp"

#include "string_obj.hpp"


int main()
{
    Lexer::Lexer lex;
    std::string buff;

    std::getline(std::cin, buff);
    auto toks = lex.Tokenize(buff);

    while(toks.Current().GetTokenType() != Lexer::TokenType::END_OF_FILE)
    {
        std::cout << toks.Current() << std::endl;
        toks.Next();
    }

    toks.Reset();

    Parser parser;
    auto expr = parser.ParseExpression(toks);

}   