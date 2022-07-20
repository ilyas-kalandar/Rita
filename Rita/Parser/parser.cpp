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

#include "parser.hpp"

#include "Instructions/unop_instruction.hpp"
#include "Instructions/attribute_instruction.hpp"
#include "Instructions/constant_float.hpp"
#include "Instructions/constant_int.hpp"
#include "Instructions/constant_string.hpp"
#include "Instructions/constant_list.hpp"

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
	case Lexer::TokenType::PLUS:
	case Lexer::TokenType::MINUS:
		return 1;
	case Lexer::TokenType::DIVISION:
	case Lexer::TokenType::MULTIPLY:
		return 2;
	case Lexer::TokenType::DOT:
	case Lexer::TokenType::LEFT_PAREN:
		return 3;
	case Lexer::TokenType::IDENTIFIER:
		return 4;
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
	default:
		throw std::runtime_error("Blyat, unknown token");
	}
}

std::shared_ptr<Core::Instructions::Instruction> Parser::ParseNotExpr()
{
	if (this->tokens.Current().GetTokenType() != Lexer::TokenType::NOT)
	{
		return this->ParseBinop(1);
	}

	this->tokens.Next(); // skip '!'

	return std::make_shared<Core::Instructions::UnaryOperatorInstruction>(ParseNotExpr(), Core::Instructions::OpType::NOT);
}

std::shared_ptr<Core::Instructions::Instruction> Parser::ParseBinop(size_t priority)
{
	std::shared_ptr<Core::Instructions::Instruction> result;

	if (priority < 2)
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

		if (priority < 2)
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
	if (this->tokens.Current().GetTokenType() == Lexer::TokenType::MINUS)
	{
		this->tokens.Next();
		return std::make_shared<Core::Instructions::UnaryOperatorInstruction>(ParseUnaryMinus(), Core::Instructions::OpType::MINUS);
	}
	
	return ParseHighPriorityExpr();
}

std::shared_ptr<Core::Instructions::Instruction> Parser::ParseHighPriorityExpr()
{
	std::shared_ptr<Core::Instructions::Instruction> result;
	auto leaf = ParseLeaf();

	bool resultIsEmpty = true;

	if (leaf.has_value())
	{
		result = leaf.value();
		resultIsEmpty = false;
	}

	while (this->tokens.HasNext() && GetPriority(this->tokens.Current().GetTokenType()) == 3)
	{
		switch (this->tokens.Current().GetTokenType())
		{
		case Lexer::TokenType::DOT:
			this->tokens.Next(); // skip dot
			if (resultIsEmpty)
			{
				throw std::runtime_error("Expected expression before '.'!");
			}
			else
			{
				if (this->tokens.Current().GetTokenType() != Lexer::TokenType::IDENTIFIER)
				{
					throw std::runtime_error("Expected identifier after '.'!");
				}

				result = std::make_shared<Core::Instructions::AttributeInstruction>(result, this->tokens.Current().GetLiteral());
				this->tokens.Next(); // skip id
			}
			break;
		case Lexer::TokenType::LEFT_PAREN:
			if (resultIsEmpty) // not func-call
			{
				this->tokens.Next(); // skip left paren
				result = ParseNotExpr();
				if (this->tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_PAREN)
				{
					throw std::runtime_error("Expected ')'!");
				}
				this->tokens.Next(); // skip right paren
				return result;
			}
			else
			{
				std::vector<std::shared_ptr<Core::Instructions::Instruction>> funcArgs;
				this->tokens.Next(); // skip left paren

				while (this->tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_PAREN)
				{
					funcArgs.push_back(ParseNotExpr());
					if (this->tokens.Current().GetTokenType() == Lexer::TokenType::COMMA)
					{
						this->tokens.Next(); // skip comma
					}
				}
				this->tokens.Next(); // skip right paren

				result = std::make_shared<Core::Instructions::FunctionCallInstruction>(result, funcArgs);
			}
		}
	}

	if (!resultIsEmpty)
		return result;

	throw std::runtime_error("Expected ID or const, given " + this->tokens.Current().GetLiteral() + "\"");
}

std::optional<std::shared_ptr<Core::Instructions::Instruction>> Parser::ParseLeaf()
{
	switch(this->tokens.Current().GetTokenType())
	{
	case Lexer::TokenType::IDENTIFIER:
	{
		const std::string& name = this->tokens.Current().GetLiteral();
		this->tokens.Next();
		return std::make_shared<Core::Instructions::Leaf>(name);
	}
	case Lexer::TokenType::FLOAT:
	{
		// I think will be better if I create my own converter...
		long double value = std::atof(this->tokens.Current().GetLiteral().c_str());
		this->tokens.Next();
		
		return std::make_shared<Core::Instructions::ConstantFloat>(value);
	}
	case Lexer::TokenType::INTEGER:
	{
		// I think will be better if I create my own converter...
		int value = std::stoi(this->tokens.Current().GetLiteral());
		this->tokens.Next();
		return std::make_shared<Core::Instructions::ConstantInt>(value);
	}
	case Lexer::TokenType::STRING:
	{
		// I think will be better if I create my own converter...
		auto val = this->tokens.Current().GetLiteral();
		this->tokens.Next();
		return std::make_shared<Core::Instructions::ConstantString>(val);
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

			if(this->tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_BRACKET)
				this->tokens.Next();
		}

		if(this->tokens.Current().GetTokenType() != Lexer::TokenType::RIGHT_BRACKET)
		{
			throw std::runtime_error("Expected ']'!");
		}

		this->tokens.Next(); // skip right bracket

		return std::make_shared<Core::Instructions::ConstantList>(list);
	}
	}

	return std::nullopt;
}

std::shared_ptr<Core::Instructions::Instruction> Parser::ParseExpression()
{
	return this->ParseNotExpr();
}

std::vector<std::shared_ptr<Core::Instructions::Instruction>> Parser::Parse(Lexer::Tokenator& tokens)
{
	this->tokens = tokens;
	this->tokens.Reset();

	std::vector<std::shared_ptr<Core::Instructions::Instruction>> program;

	program.push_back(ParseExpression());

	return program;
}
