#include <functional>
#include <iostream>

#include "object.hpp"
#include "lexer.hpp"
#include "type.hpp"
#include "Builtins/types.hpp"
#include "Instructions/binop_instruction.hpp"
#include "native_function.hpp"
#include "engine.hpp"
#include "Instructions/leaf.hpp"
#include "parser.hpp"

#include "string_obj.hpp"

void print_spaces(size_t lvl)
{
    while(lvl--)
        std::cout << " ";
}

void print_expr(Core::Instructions::Instruction* expr, size_t level=0)
{
    switch(expr->GetType())
    {
    case Core::InstructionType::BINOP:{
        print_spaces(level);
        std::cout << "BinaryOperation" << std::endl;
        
        auto casted_ex = static_cast<Core::Instructions::BinOpInstruction*>(expr);
        print_expr(casted_ex->GetFirst().get(), level + 2);

        switch(casted_ex->GetOperationType())
        {
        case Core::Instructions::OpType::PLUS:
            std::cout << "+" << std::endl;
        }
        break;
    }
    case Core::InstructionType::LEAF:
        print_spaces(level);
        auto ex = static_cast<Core::Instructions::Leaf*>(expr);
        std::cout << ex->GetID() << std::endl;
        return;
    }
}

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

    print_expr(expr.get());

}   