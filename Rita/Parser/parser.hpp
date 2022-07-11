/**
 * @file parser.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>
#include <memory>

#include "Instructions/instruction.hpp"
#include "Instructions/leaf.hpp"
#include "Instructions/if_instruction.hpp"

#include "lexer.hpp"

#ifndef parser_hpp
#define parser_hpp

namespace Parser
{
	class Parser
	{
	private:
		InstructionType currentInstructionType;
		Lexer::Tokenator tok;
		std::vector<std::shared_ptr<Instruction>> instructions;
		std::shared_ptr<Instruction> currentInstruction;

		void HandleIdentifier()
		{
			auto nextToken = tok.Next();
			switch (nextToken.GetTokenType())
			{
			case Lexer::TokenType::EQUAL:
				currentInstruction = new IfInstruction();
			default:
				throw std::runtime_error("Unexpected token \"" + nextToken.GetLiteral() + "\"");
			}
		}
	public:
		std::vector<std::shared_ptr<Instruction>> Parse()
		{
			while (tok.Current().GetTokenType() != Lexer::TokenType::END_OF_FILE)
			{
				switch (tok.Current().GetTokenType())
				{
				case Lexer::TokenType::IDENTIFIER:
					/**
					* If identifier give, instruction may be:
					*	FunctionCall
					*	AssignInstruction
					*	BinaryOperation
					*/

					// handle
					this->HandleIdentifier();
					break;
				case Lexer::TokenType::FUN:
					// It is function-definition, all is ok.
					break;
				case Lexer::TokenType::IF:
					// if, block
					break;
				case Lexer::TokenType::WHILE:
					// absolutely while, it is ok
					break;
				}
			}
			return std::vector<std::shared_ptr<Instruction>>();
		}
	};
}

#endif