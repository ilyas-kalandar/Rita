#include <functional>
#include <iostream>

#include "object.hpp"
#include "lexer.hpp"
#include "type.hpp"
#include "Instructions/binop_instruction.hpp"
#include "native_function.hpp"
#include "Instructions/leaf.hpp"
#include "parser.hpp"
#include "engine.hpp"
#include "ast_printer.hpp"
#include "string_obj.hpp"

int main()
{
    size_t line = 1;

    Lexer::Lexer lex;
    std::string source;
    std::string buff;


    Executor::Engine engine;
    

    do
    {
        std::cout << "[Line " << line << "]: ";
        std::getline(std::cin, buff);
        source += buff;
        line++;
    } while (buff.size() > 0);

    auto toks = lex.Tokenize(source);
    while (toks.Current().GetTokenType() != Lexer::TokenType::END_OF_FILE)
    {
        //std::cout << toks.Current() << std::endl;
        toks.Next();
    }

    toks.Reset();

    Parser::Parser parser;

    std::shared_ptr<Core::Instructions::Instruction> program;

    try
    {
        program = parser.Parse(toks);
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
        return -1; // compilation error
    }

    Utils::AstPrinter printer(2);

    printer.Print(program.get());

    engine.ExecuteInstruction(program);
}
