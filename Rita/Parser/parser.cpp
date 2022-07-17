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

    return std::vector<std::shared_ptr<Core::Instructions::Instruction>>();
}

std::shared_ptr<Core::Instructions::Instruction> Parser::ParseExpression(Lexer::Tokenator& tok)
{
    this->tokens = tok;
    return ParseByPriority(1);
}

std::shared_ptr<Core::Instructions::Instruction> Parser::ParseByPriority(size_t priority = 1)
{
    if(priority < 3)
    {
        std::shared_ptr<Core::Instructions::Instruction> result = ParseByPriority(priority + 1);

        while(this->tokens.HasNext() && GetPriority(this->tokens.Current().GetTokenType()) == priority)
        {
            Core::Instructions::OpType opType = GetOpType(tokens.Current());
            tokens.Next();
            
            auto tmp = std::shared_ptr<Core::Instructions::Instruction>(new Core::Instructions::BinOpInstruction(result, ParseByPriority(priority + 1), opType));
            result.swap(tmp);
        }   

        return result;
    }

    switch (this->tokens.Current().GetTokenType())
    {
    case Lexer::TokenType::LEFT_PAREN:
    {
        // ok
        this->tokens.Next();
        auto expr = ParseByPriority(1);

        if (this->tokens.Next().GetTokenType() != Lexer::TokenType::RIGHT_PAREN)
        {
            throw std::runtime_error("Expected ')'!");
        }

        this->tokens.Next();

        return expr;
    }
    case Lexer::TokenType::IDENTIFIER:
        // Check for function-call
        if (this->tokens.CheckNext(Lexer::TokenType::LEFT_PAREN))
        { 
            std::string funcName = this->tokens.Current().GetLiteral();
            std::vector<std::shared_ptr<Core::Instructions::Instruction>> args;

            this->tokens.Next();
            this->tokens.Next();

            while (this->tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_PAREN)
            {

                if (this->tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_FILE)
                {
                    throw std::runtime_error("Unexpected EOF!");
                }

                args.push_back(ParseByPriority(1));

                if (this->tokens.Current().GetTokenType() == Lexer::TokenType::COMMA)
                    tokens.Next();
            }

           
            return std::shared_ptr<Core::Instructions::FunctionCallInstruction>(new Core::Instructions::FunctionCallInstruction(funcName, args));
        }
        {
            auto leaf = std::make_shared<Core::Instructions::Leaf>(this->tokens.Current().GetLiteral());
            this->tokens.Next();
            return leaf;
        }
    default:
        throw std::runtime_error(std::string("Unexpected token ") + this->tokens.Current().GetLiteral());
    }
}