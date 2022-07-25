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
#include "Instructions/var_decl_instruction.hpp"
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

	void Print(Core::Instructions::ConstantInt*);
	void Print(Core::Instructions::ConstantString*);
	void Print(Core::Instructions::ConstantFloat*);
	void Print(Core::Instructions::ConstantList*);
	void Print(Core::Instructions::WhileInstruction*);
	void Print(Core::Instructions::IfInstruction*);
	void Print(Core::Instructions::AssignmentInstruction*);

	//TODO(Ilyas): Add another definitions

    public:
		/**
		* @brief Constructs a new AstPrinter object
		*
		*/
        AstPrinter(size_t indent_level);

        void Print(Core::Instructions::Instruction*);
    };
}

#endif
