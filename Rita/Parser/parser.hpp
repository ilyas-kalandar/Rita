/**
 * @file parser.hpp
 *
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>

#include "tokenator.hpp"
#include "Instructions/instruction.hpp"

/**
 * @brief 
 * 
 */
class Parser
{
protected:
    Lexer::Tokenator tokens;
public:
    std::vector<std::shared_ptr<Core::Instructions::Instruction>> Parse(Lexer::Tokenator& tokens);
    std::shared_ptr<Core::Instructions::Instruction> ParseByPriority(size_t);
    std::shared_ptr<Core::Instructions::Instruction> ParseExpression(Lexer::Tokenator& tok);
};