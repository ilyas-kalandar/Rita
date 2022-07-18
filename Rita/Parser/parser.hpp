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
#include <optional>

#include "Instructions/binop_instruction.hpp"
#include "Instructions/function_call_instruction.hpp"
#include "Instructions/op_type.hpp"
#include "Instructions/leaf.hpp"
#include "Instructions/binop_instruction.hpp"

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
    std::optional<std::shared_ptr<Core::Instructions::Instruction>> ParseLeaf();
    std::shared_ptr<Core::Instructions::Instruction> ParseHighPriorityExpr();
    std::shared_ptr<Core::Instructions::Instruction> ParseUnaryMinus();
    std::shared_ptr<Core::Instructions::Instruction> ParseBinop(size_t priority);
    std::shared_ptr<Core::Instructions::Instruction> ParseNotExpr();
    std::shared_ptr<Core::Instructions::Instruction> ParseExpression();
    std::vector<std::shared_ptr<Core::Instructions::Instruction>> Parse(Lexer::Tokenator& tokens);
};