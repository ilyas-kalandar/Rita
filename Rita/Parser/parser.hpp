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
#include "lexer.hpp"

#ifndef parser_hpp
#define parser_hpp

namespace Parser
{
	class Parser
	{
	private:
		Lexer::Tokenator tok;
	public:
		std::vector<std::shared_ptr<Instruction>> Parse()
		{
			std::vector < std::shared_ptr<Instruction>> vec;
			vec.emplace_back(new Leaf(new RitaObject(3)));
			
			return vec;
		}
	};
}

#endif