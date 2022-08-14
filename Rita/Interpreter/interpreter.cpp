#include <fstream>
#include <cstring>
#include <iostream>

#include "ast_printer.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "engine.hpp"
#include "rita_exception.hpp"
#include "interpreter.hpp"

namespace Interpreter
{
    Interpreter::Interpreter(const char* argv[], int argc)
    {
        // we must parse arguments.

        for(int i = 1; i < argc; ++i)
        {
            std::string key = argv[i];

            if(key == "-ast" || key == "--ast")
            {
                outputAst = true;
            }
            else if(key == "-v" || key == "--version")
            {
                outputVersion = true;
            }
            else if(key == "-tokens" || key == "--tokens")
            {
                outputTokens = true;
            }
            else if(key == "--help" || key == "-h")
            {
                outputHelp = true;
            }
            else if(key == "-file" || key == "--file")
            {
                isFile = true;
                if(argc <= (i + 1))
                {
                    throw Utils::RitaException("ArgumentsParser", "Expected filename!");
                }

                fileName = std::string(argv[i + 1]);
                ++i;
            }
            else 
            {
                 throw Utils::RitaException("ArgumentsParser", "Unexpcted key \"" + key + "\"");
            }
        }
    }

    void Interpreter::Run()
    {
        if(outputHelp)
        {
            std::cout << "Usage: rita --file filename.rt" << std::endl;
            std::cout << "--ast - Show ast." << std::endl;
            std::cout << "--tokens - Show tokens from tokenizer." << std::endl;
            std::cout << "--help - Show this menu." << std::endl;
            std::cout << "--version - Output version of language." << std::endl;

            return;
        }
        
        if(outputVersion)
        {
            std::cout << "Rita interpreter, created by Awaitable (Ilyas Qalandarzoda) " << std::endl;
            std::cout << "Version: 0.1" << std::endl;
            std::cout << "https://t.me/Awaitable" << std::endl;
            return;
        }

        Lexer::Lexer lex;
        Parser::Parser parser;
        Executor::Engine engine;
        Utils::AstPrinter printer(2);

        size_t line = 1;
        std::string buff;

        std::string source;

        if(isFile)
        {
            std::ifstream fstream(fileName);

            while(std::getline(fstream, buff))
            {
                source += buff;
            }
        }

        if(!isFile)
        {
            do
            {
                std::cout << "[Line " << line << "]: ";
                std::getline(std::cin, buff);
                source += buff;
                line++;
            } while (buff.size() > 0);
        }


        auto toks = lex.Tokenize(source);

        if(outputTokens)
        {
            while(toks.HasNext())
            {
                std::cout << toks.Current() << std::endl;
                toks.Next();
            }
        }

        toks.Reset();

        std::shared_ptr<Core::Instructions::Instruction> md = parser.Parse(toks);

        if(outputAst)
        {
            printer.Print(md.get());
        }
        
        engine.ExecuteInstruction(md);
    }
}