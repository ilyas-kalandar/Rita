/**
 * @file parser.hpp
 *
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Parser definition.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <vector>
#include <optional>

#include "tokenator.hpp"

#include "Instructions/binop_instruction.hpp"
#include "Instructions/function_call_instruction.hpp"
#include "Instructions/op_type.hpp"
#include "Instructions/leaf.hpp"
#include "Instructions/binop_instruction.hpp"
#include "Instructions/instruction.hpp"


/**
 * @brief Just Parser class for building AST from tokens.
 * 
 */
class Parser
{
protected:
    Lexer::Tokenator tokens;
    /**
     * @brief Parses a leaf (identifiers, constants, etc...)
     * 
     * @return std::optional<std::shared_ptr<Core::Instructions::Instruction>> 
     */
    std::optional<std::shared_ptr<Core::Instructions::Instruction>> ParseLeaf();
    /**
     * @brief Parses an expression with very high priority (calls, etc...)
     * 
     * @return std::shared_ptr<Core::Instructions::Instruction> 
     */
    std::shared_ptr<Core::Instructions::Instruction> ParseHighPriorityExpr();
    /**
     * @brief Parses an expression wih higher priority (4)
     * 
     * @return std::shared_ptr<Core::Instructions::Instruction> 
     */
    std::shared_ptr<Core::Instructions::Instruction> ParseUnaryMinus();
    /**
     * @brief Parses an expression with low-medium (2-3) priority
     * 
     * @param priority Priority (must be in range(2, 3))
     * @return std::shared_ptr<Core::Instructions::Instruction> 
     */
    std::shared_ptr<Core::Instructions::Instruction> ParseBinop(size_t priority);
    /**
     * @brief Parses an expression with lowest priority (unary !)
     * 
     * @return std::shared_ptr<Core::Instructions::Instruction> 
     */
    std::shared_ptr<Core::Instructions::Instruction> ParseNotExpr();
    /**
     * @brief Parses an expression
     * 
     * @return std::shared_ptr<Core::Instructions::Instruction> 
     */

    void ExpectAndSkip(Lexer::TokenType);
    std::shared_ptr<Core::Instructions::Instruction> ParseExpression();
    std::shared_ptr<Core::Instructions::Instruction> ParseAssignInstruction();
    std::shared_ptr<Core::Instructions::Instruction> ParseInstruction();
    std::vector<std::shared_ptr<Core::Instructions::Instruction>> ParseCodeBlock();
public:
    /**
     * @brief Parses tokens into instructions
     * 
     * @param tokens Tokenator object.
     * @return std::vector<std::shared_ptr<Core::Instructions::Instruction>> 
     */
    std::vector<std::shared_ptr<Core::Instructions::Instruction>> Parse(Lexer::Tokenator& tokens);
};