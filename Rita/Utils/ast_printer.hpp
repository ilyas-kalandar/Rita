#include "Instructions/unop_instruction.hpp"
#include "Instructions/instruction.hpp"
#include "Instructions/binop_instruction.hpp"
#include "Instructions/if_instruction.hpp"
#include "Instructions/assignment_instruction.hpp"
#include "Instructions/leaf.hpp"
#include "Instructions/op_type.hpp"
#include "Instructions/while_instruction.hpp"
#include "Instructions/attribute_instruction.hpp"
#include "Instructions/function_call_instruction.hpp"
#include "Instructions/constant_float.hpp"
#include "Instructions/constant_int.hpp"
#include "Instructions/constant_list.hpp"
#include "Instructions/constant_string.hpp"
#include "Instructions/index_instruction.hpp"

#ifndef utils_ast_printer_hpp
#define utils_ast_printer_hpp

namespace Utils::AstPrinter
{
    /**
    * @brief Prints binary operation
    * 
    *
    */
    void PrintBinaryOperation(Core::Instructions::BinOpInstruction* instr, size_t level);
    void PrintIf(Core::Instructions::IfInstruction* instr, size_t level);
    void PrintFunctionCall(Core::Instructions::FunctionCallInstruction* instr, size_t level);
    void PrintLeaf(Core::Instructions::Leaf* instr, size_t level);
    void PrintAssignment(Core::Instructions::AssignmentInstruction* instr, size_t level);
    void PrintAttribute(Core::Instructions::AttributeInstruction* instr, size_t level);
    void PrintUnaryOp(Core::Instructions::UnaryOperatorInstruction* insr, size_t level);
    void PrintAstTree(Core::Instructions::Instruction* instr, size_t level);
}

#endif