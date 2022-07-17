#include "Instructions/binop_instruction.hpp"
#include "Instructions/function_call_instruction.hpp"
#include "Instructions/op_type.hpp"
#include "Instructions/leaf.hpp"
#include "Instructions/binop_instruction.hpp"

#include "parser.hpp"

size_t GetPriority(const Lexer::TokenType& type)
{
    switch(type)
    {
    case Lexer::TokenType::PLUS:
    case Lexer::TokenType::MINUS:
        return 1;
    case Lexer::TokenType::DIVISION:
    case Lexer::TokenType::MULTIPLY:
        return 2;
    case Lexer::TokenType::IDENTIFIER:
        return 3;
    default:
        return 0;
    }
}

Core::Instructions::OpType GetOpType(const Lexer::Token& tok)
{
    switch(tok.GetTokenType())
    {
    case Lexer::TokenType::PLUS:
        return Core::Instructions::OpType::PLUS;
    case Lexer::TokenType::MINUS:
        return Core::Instructions::OpType::MINUS;
    case Lexer::TokenType::MULTIPLY:
        return Core::Instructions::OpType::MUL;
    case Lexer::TokenType::DIVISION:
        return Core::Instructions::OpType::DIV;
    default:
        throw std::runtime_error("Blyat, unknown token");
    }
}

std::vector<std::shared_ptr<Core::Instructions::Instruction>> Parser::Parse(Lexer::Tokenator& tokens)
{
    this->tokens = tokens;

    
}

std::shared_ptr<Core::Instructions::Instruction> Parser::ParseExpression(Lexer::Tokenator& tok)
{
    this->tokens = tok;
    std::cout << "parsing" << std::endl;
    return ParseByPriority(1);
}

std::shared_ptr<Core::Instructions::Instruction> Parser::ParseByPriority(size_t priority)
{
    std::cout << "Parsing.." << std::endl;
    if(priority < 3)
    {
        std::shared_ptr<Core::Instructions::Instruction> result = ParseByPriority(priority + 1);

        while(this->tokens.HasNext() && GetPriority(this->tokens.Current().GetTokenType()) == priority)
        {
            Core::Instructions::OpType opType = GetOpType(tokens.Current());
            tokens.Next();
            result = std::make_shared<Core::Instructions::BinOpInstruction>(result, ParseByPriority(priority + 1), opType);
        }



        return result;
    }

    // expect leaf 

    std::cout << "Checking leaf..." << std::endl;

    if(this->tokens.Next().GetTokenType() != Lexer::TokenType::IDENTIFIER)
    {
        throw std::runtime_error("re, expected id");
    }

    return std::make_shared<Core::Instructions::Leaf>(tokens.Current().GetLiteral());
}