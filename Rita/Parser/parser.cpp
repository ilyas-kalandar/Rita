/**
 * @file parser.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Parser's implementation
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <sstream>

#include "parser.hpp"
#include "rita_exception.hpp"
#include "Instructions/constant_bool.hpp"
#include "Instructions/if_instruction.hpp"
#include "Instructions/assignment_instruction.hpp"
#include "Instructions/unop_instruction.hpp"
#include "Instructions/attribute_instruction.hpp"
#include "Instructions/function_definition.hpp"
#include "Instructions/constant_float.hpp"
#include "Instructions/constant_int.hpp"
#include "Instructions/constant_string.hpp"
#include "Instructions/constant_list.hpp"
#include "Instructions/var_decl_instruction.hpp"
#include "Instructions/while_instruction.hpp"
#include "Instructions/index_instruction.hpp"


namespace Parser
{
    /**
     * @brief Get token's priority
     * 
     * @param type 
     * @return size_t 
     */
    size_t GetPriority(const Lexer::TokenType& type)
    {
        switch (type)
        {
        case Lexer::TokenType::EQUAL_EQUAL:
        case Lexer::TokenType::LESS_OR_EQUAL_THAN:
        case Lexer::TokenType::LESS_THAN:
        case Lexer::TokenType::GREATER_OR_EQUAL_THAN:
        case Lexer::TokenType::GREATER_THAN:
            return 1;
        case Lexer::TokenType::PLUS:
        case Lexer::TokenType::MINUS:
            return 2;
        case Lexer::TokenType::DIVISION:
        case Lexer::TokenType::MULTIPLY:
            return 3;
        case Lexer::TokenType::DOT:
        case Lexer::TokenType::LEFT_PAREN:
        case Lexer::TokenType::LEFT_BRACKET:
            return 4;
        case Lexer::TokenType::IDENTIFIER:
            return 5;
        default:
            return 0; // by default, any token have 0-priority
        }
    }

    Core::Instructions::OpType GetOpType(const Lexer::Token& tok)
    {
        switch (tok.GetTokenType())
        {
        case Lexer::TokenType::PLUS:
            return Core::Instructions::OpType::PLUS;
        case Lexer::TokenType::MINUS:
            return Core::Instructions::OpType::MINUS;
        case Lexer::TokenType::MULTIPLY:
            return Core::Instructions::OpType::MUL;
        case Lexer::TokenType::DIVISION:
            return Core::Instructions::OpType::DIV;
        case Lexer::TokenType::NOT:
            return Core::Instructions::OpType::NOT;
        case Lexer::TokenType::LESS_OR_EQUAL_THAN:
            return Core::Instructions::OpType::LESS_OR_EQUAL_THAN;
        case Lexer::TokenType::GREATER_THAN:
            return Core::Instructions::OpType::GREATER_THAN;
        case Lexer::TokenType::GREATER_OR_EQUAL_THAN:
            return Core::Instructions::OpType::GREATER_OR_EQUAL_THAN;
        case Lexer::TokenType::EQUAL_EQUAL:
            return Core::Instructions::OpType::EQUAL_EQUAL;
        case Lexer::TokenType::LESS_THAN:
            return Core::Instructions::OpType::LESS_THAN;
        case Lexer::TokenType::AND:
            return Core::Instructions::OpType::AND;
        case Lexer::TokenType::OR:
            return Core::Instructions::OpType::OR;
        default:
            throw Utils::RitaException(
                "OpType::GetOpType",
                (std::stringstream() << "Unsupported token \"" << tok << "\"").str()
            );
        }
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseNotExpr()
    {
        if(tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_LINE)
        {
            throw Utils::RitaException(
                "Parser",
                "Unexpected \"END_OF_LINE\"",
                tokens.Current().GetLine(),
                tokens.Current().GetCharacter()
            );
        }

        if (this->tokens.Current().GetTokenType() != Lexer::TokenType::NOT)
        {
            return this->ParseBinop(1);
        }

        this->tokens.Next(); // skip '!'

        return std::make_shared<Core::Instructions::UnaryOperatorInstruction>(ParseNotExpr(), Core::Instructions::OpType::NOT);
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseBinop(size_t priority)
    {
        if(tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_LINE)
        {
            throw Utils::RitaException(
                "Parser",
                "Unexpected \"END_OF_LINE\"",
                tokens.Current().GetLine(),
                tokens.Current().GetCharacter()
            );
        }

        std::shared_ptr<Core::Instructions::Instruction> result;

        if (priority < 3)
        {
            result = ParseBinop(priority + 1);
        }
        else
        {
            result = ParseUnaryMinus();
        }

        while (this->tokens.HasNext() && GetPriority(this->tokens.Current().GetTokenType()) == priority)
        {
            Core::Instructions::OpType opType = GetOpType(this->tokens.Current());
            this->tokens.Next(); // Skip Operator

            if (priority < 3)
            {
                result = std::make_shared<Core::Instructions::BinOpInstruction>(result, ParseBinop(2), opType);
            }
            else
            {
                result = std::make_shared<Core::Instructions::BinOpInstruction>(result, ParseUnaryMinus(), opType);
            }
        }

        return result;
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseUnaryMinus()
    {
        if(tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_LINE)
        {
            throw Utils::RitaException(
                "Parser",
                "Unexpected \"END_OF_LINE\"",
                tokens.Current().GetLine(),
                tokens.Current().GetCharacter()
            );
        }

        if (this->tokens.Current().GetTokenType() == Lexer::TokenType::MINUS)
        {
            this->tokens.Next();
            return std::make_shared<Core::Instructions::UnaryOperatorInstruction>(ParseUnaryMinus(), Core::Instructions::OpType::MINUS);
        }
        
        return ParseHighPriorityExpr();
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseHighPriorityExpr()
    {
        if(tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_LINE)
        {
            throw Utils::RitaException(
                "Parser",
                "Unexpected \"END_OF_LINE\"",
                tokens.Current().GetLine(),
                tokens.Current().GetCharacter()
            );
        }

        std::shared_ptr<Core::Instructions::Instruction> result;
        auto leaf = ParseLeaf();

        bool resultIsEmpty = true;

        if (leaf.has_value())
        {
            result = leaf.value();
            resultIsEmpty = false;
        }

        while (this->tokens.HasNext() && GetPriority(this->tokens.Current().GetTokenType()) == 4)
        {
            if(tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_LINE)
            {
                throw Utils::RitaException(
                    "Parser",
                    "Unexpected \"END_OF_LINE\"",
                    tokens.Current().GetLine(),
                    tokens.Current().GetCharacter()
                );
            }

            switch (this->tokens.Current().GetTokenType())
            {
            case Lexer::TokenType::DOT:
                if (resultIsEmpty)
                {
                    throw Utils::RitaException(
                        "Parser", 
                        "Expected expression before '.'-token!",
                        this->tokens.Current().GetLine(),
                        this->tokens.Current().GetCharacter()
                    );
                }
                else
                {
                    this->tokens.Next(); // skip dot
                    if (this->tokens.Current().GetTokenType() != Lexer::TokenType::IDENTIFIER)
                    {
                        throw Utils::RitaException(
                            "Parser", 
                            (std::stringstream() << "Expected an identifier, got \"" << tokens.Current().GetTokenType() << "\"").str(),
                            tokens.Current().GetLine(),
                            tokens.Current().GetCharacter()
                        );
                    }

                    result = std::make_shared<Core::Instructions::AttributeInstruction>(result, tokens.GetAndNext().GetLiteral());
                }
                break;
            case Lexer::TokenType::LEFT_BRACKET: 
            {
                if(resultIsEmpty)
                {
                    throw Utils::RitaException(
                        "Parser", 
                        "Expected expression before '['",
                        tokens.Current().GetLine(),
                        tokens.Current().GetCharacter()
                    );
                }

                this->tokens.Next(); // skip LEFT_BRACKET

                auto index = ParseNotExpr();
                ExpectAndSkip(Lexer::TokenType::RIGHT_BRACKET);
                result = std::make_shared<Core::Instructions::IndexInstruction>(result, index);
                break;
            }
            case Lexer::TokenType::LEFT_PAREN:
                if (resultIsEmpty) // not func-call
                {
                    this->tokens.Next(); // skip left paren
                    result = ParseNotExpr();
                    ExpectAndSkip(Lexer::TokenType::RIGHT_PAREN);
                    return result;
                }
                else
                {
                    std::vector<std::shared_ptr<Core::Instructions::Instruction>> funcArgs;
                    tokens.Next(); // skip left paren

                    while (tokens.HasNext() && tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_PAREN)
                    {
                        funcArgs.push_back(ParseNotExpr());
                        
                        if (tokens.Current().GetTokenType() == Lexer::TokenType::COMMA)
                            tokens.Next(); // skip comma
                    }
                    ExpectAndSkip(Lexer::TokenType::RIGHT_PAREN);
                    result = std::make_shared<Core::Instructions::FunctionCallInstruction>(result, funcArgs);
                }
            }
        }

        if (!resultIsEmpty)
            return result;

        throw Utils::RitaException(
            "Parser", 
            (std::stringstream() << "Expected a constant or identifier, got \"" <<  tokens.Current().GetTokenType() << "\"").str(),
            tokens.Current().GetLine(),
            tokens.Current().GetCharacter()
        );
    }

    std::optional<std::shared_ptr<Core::Instructions::Instruction>> Parser::ParseLeaf()
    {
        if(tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_LINE || tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_FILE)
        {
            throw Utils::RitaException(
                "Parser",
                (std::stringstream() << "Unexpected \"" << tokens.Current().GetTokenType() << "\"").str(),
                tokens.Current().GetLine(),
                tokens.Current().GetCharacter()
            );
        }

        switch(this->tokens.Current().GetTokenType())
        {
        case Lexer::TokenType::IDENTIFIER:
        {
            const std::string& name = tokens.GetAndNext().GetLiteral();
            return std::make_shared<Core::Instructions::Leaf>(name);
        }
        case Lexer::TokenType::FLOAT:
        {
            // I think will be better if I create my own converter...
            long double value = std::atof(tokens.GetAndNext().GetLiteral().c_str());
            return std::make_shared<Core::Instructions::ConstantFloat>(value);
        }
        case Lexer::TokenType::INTEGER:
        {
            // I think will be better if I create my own converter...
            int value = std::stoi(tokens.GetAndNext().GetLiteral());
            return std::make_shared<Core::Instructions::ConstantInt>(value);
        }
        case Lexer::TokenType::STRING:
        {
            // I think will be better if I create my own converter...
            auto val = tokens.GetAndNext().GetLiteral();
            return std::make_shared<Core::Instructions::ConstantString>(val);
        }
        case Lexer::TokenType::FALSE:
        {
            // skip false
            tokens.Next();
            return std::make_shared<Core::Instructions::ConstantBool>(false);
        }
        case Lexer::TokenType::TRUE:
        {
            // skip true
            tokens.Next();
            return std::make_shared<Core::Instructions::ConstantBool>(true);
        }
        case Lexer::TokenType::LEFT_BRACKET:
        {
            // skip bracket
            this->tokens.Next();
            std::vector<std::shared_ptr<Core::Instructions::Instruction>> list;


            while(this->tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_BRACKET && this->tokens.HasNext())
            {
                list.push_back(this->ParseNotExpr());

                // also we expect ','

                if(this->tokens.Current().GetTokenType() == Lexer::TokenType::COMMA)
                {
                    this->tokens.Next(); // skip comma
                }
            }

            ExpectAndSkip(Lexer::TokenType::RIGHT_BRACKET);
            return std::make_shared<Core::Instructions::ConstantList>(list);
        }
        }

        return std::nullopt;
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseExpression()
    {
        return this->ParseNotExpr();
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseVarDecl()
    {
        this->tokens.Next(); // skip var token

        if(this->tokens.Current().GetTokenType() != Lexer::TokenType::IDENTIFIER)
        {
            throw Utils::RitaException(
                "Parser",
                (std::stringstream() << "Expected \"IDENTIFIER after 'var' token, got \"" << tokens.Current().GetTokenType() << "\"").str(),
                tokens.Current().GetLine(),
                tokens.Current().GetCharacter()
            );
        }

        std::string varName = this->tokens.GetAndNext().GetLiteral();

        ExpectAndSkip(Lexer::TokenType::EQUAL);
        return std::make_shared<Core::Instructions::VariableDeclarationInstruction>(varName, ParseExpression());
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseIf()
    {
        tokens.Next(); // skip if token

        auto expr = ParseExpression();

        auto ifBody = ParseCodeBlock();

        std::vector<std::shared_ptr<Core::Instructions::Instruction>> elseBody;

        if(this->tokens.Current().GetTokenType() == Lexer::TokenType::ELSE)
        {
            this->tokens.Next();
            elseBody = ParseCodeBlock();
        }

        return std::make_shared<Core::Instructions::IfInstruction>(ifBody, elseBody, expr);
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseWhile()
    {
        // skip while token
        tokens.Next();

        auto expr = ParseExpression();
        auto body = ParseCodeBlock();

        return std::make_shared<Core::Instructions::WhileInstruction>(body, expr);
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseInstruction()
    {
        switch (tokens.Current().GetTokenType())
        {
        case Lexer::TokenType::VAR:
            return ParseVarDecl();
        case Lexer::TokenType::IF:
            return ParseIf();
        case Lexer::TokenType::WHILE:
            return ParseWhile();
        case Lexer::TokenType::RETURN:
            return ParseReturn();
        case Lexer::TokenType::FUN:
            return ParseFunction();
        default:
            auto expr = ParseExpression();
            if(
                (expr->GetType() == Core::Instructions::InstructionType::LEAF 
                || 
                expr->GetType() == Core::Instructions::InstructionType::ATTRIBUTE
                ) && this->tokens.Current().GetTokenType() == Lexer::TokenType::EQUAL
            )
            {
                // assign
                tokens.Next(); // skip EQUAL-token
                return std::make_shared<Core::Instructions::AssignmentInstruction>(expr, ParseExpression());
            }
            return expr;
        }
    }

    std::shared_ptr<Core::Instructions::ReturnInstruction> Parser::ParseReturn()
    {
        // skip return token
        ExpectAndSkip(Lexer::TokenType::RETURN);

        if(tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_LINE  || tokens.Current().GetTokenType() == Lexer::TokenType::END_OF_FILE)
        {
            tokens.Next(); // skip EOL
            return std::make_shared<Core::Instructions::ReturnInstruction>(nullptr);
        }

        return std::make_shared<Core::Instructions::ReturnInstruction>(ParseExpression());
    }

    std::vector<std::shared_ptr<Core::Instructions::Instruction>> Parser::ParseCodeBlock()
    {
        std::vector<std::shared_ptr<Core::Instructions::Instruction>> result;

        ExpectAndSkip(Lexer::TokenType::LEFT_BRACE);

        while(this->tokens.HasNext() && this->tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_BRACE)
        {
            result.push_back(ParseInstruction());
        }

        ExpectAndSkip(Lexer::TokenType::RIGHT_BRACE);
        return result;
    }

    Lexer::Token Parser::ExpectAndSkip(Lexer::TokenType type)
    {
        auto tok = tokens.GetAndNext();

        if(tok.GetTokenType() != type)
        {
            throw Utils::RitaException(
                "Parser", 
                (std::stringstream() << "Expected \"" << type << "\" got \"" << tok.GetTokenType() << "\"").str(),
                tok.GetLine(),
                tok.GetCharacter()
            );
        }

        return tok;
    }

    std::shared_ptr<Core::Instructions::Instruction> Parser::ParseFunction()
    {
        tokens.Next(); // skip function token
        
        // expect identifier for token

        std::string functionName = ExpectAndSkip(Lexer::TokenType::IDENTIFIER).GetLiteral();

        // parse arguments

        std::vector<std::string> args;

        ExpectAndSkip(Lexer::TokenType::LEFT_PAREN);

        while(tokens.HasNext() && tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_PAREN)
        {
            args.push_back(ExpectAndSkip(Lexer::TokenType::IDENTIFIER).GetLiteral());

            if(tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_PAREN)
                ExpectAndSkip(Lexer::TokenType::COMMA);
        }

        ExpectAndSkip(Lexer::TokenType::RIGHT_PAREN);

        auto body = ParseCodeBlock();

        return std::make_shared<Core::Instructions::FunctionDefinitionInstruction>(functionName, args, body);
    }

    bool Parser::SkipIfExist(Lexer::TokenType tok_type)
    {
        if(tokens.Current().GetTokenType() == tok_type)
        {
            tokens.Next();
            return true;
        }

        return false;
    }

    std::shared_ptr<Core::Instructions::ModuleInstruction> Parser::Parse(Lexer::Tokenator& tokens)
    {
        this->tokens = tokens;
        this->tokens.Reset();

        std::vector<std::shared_ptr<Core::Instructions::Instruction>> program;

        while(this->tokens.HasNext())
        {
            program.push_back(ParseInstruction());
        }

        return std::make_shared<Core::Instructions::ModuleInstruction>(program);
    }
}