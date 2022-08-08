/**
 * @file ast_printer.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief AstPrinter definition.
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "Instructions/module_instruction.hpp"
#include "Instructions/return_instruction.hpp"
#include "Instructions/unop_instruction.hpp"
#include "Instructions/instruction.hpp"
#include "Instructions/binop_instruction.hpp"
#include <Instructions/assignment_instruction.hpp>
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
#include "Instructions/var_decl_instruction.hpp"
#include "Instructions/function_definition.hpp"
#include "Instructions/constant_string.hpp"
#include "Instructions/index_instruction.hpp"

#ifndef utils_ast_printer_hpp
#define utils_ast_printer_hpp

namespace Utils
{
    class AstPrinter
    {
    protected:
        size_t depth;
        size_t indent_level;

        // for indent

        void IncrDepth();
        void DecrDepth();

        // for output some strings

        void SetCursor();
        void PrintValue(const char*, Core::Instructions::Instruction*);
        void PrintValue(const char*, const std::vector<std::shared_ptr<Core::Instructions::Instruction>>&);
        void PrintValue(const char*, const char*);
        void PrintValue(const char* key, const std::vector<std::string>& vec);

        void Print(const char*, bool);
        void Print(const std::string&, bool);

        // for instructions

        void Print(Core::Instructions::Leaf*);
        void Print(Core::Instructions::ConstantInt*);
        void Print(Core::Instructions::ConstantString*);
        void Print(Core::Instructions::ConstantFloat*);
        void Print(Core::Instructions::ConstantList*);
        void Print(Core::Instructions::IfInstruction*);
        void Print(Core::Instructions::VariableDeclarationInstruction*);
        void Print(Core::Instructions::AttributeInstruction*);
        void Print(Core::Instructions::AssignmentInstruction*);
        void Print(Core::Instructions::FunctionCallInstruction*);
        void Print(Core::Instructions::BinOpInstruction*);
        void Print(Core::Instructions::UnaryOperatorInstruction*);
        void Print(Core::Instructions::WhileInstruction*);
        void Print(Core::Instructions::FunctionDefinitionInstruction*);
        void Print(Core::Instructions::ReturnInstruction*);
        void Print(Core::Instructions::ModuleInstruction*);

        //TODO(Ilyas): Add another definitions

    public:
        /**
        * @brief Constructs a new AstPrinter object
        *
        */
        AstPrinter(size_t indent_level);

        void Print(Core::Instructions::Instruction* instr, size_t incr_depth = 1);
    };
}

#endif
