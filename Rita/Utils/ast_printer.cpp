#include "ast_printer.hpp"
#include "rita_exception.hpp"

namespace Utils
{
    AstPrinter::AstPrinter(size_t indent_level)
    {
	this->indent_level = indent_level;

	// By default depth equals to -indent
	// because after calling 'Print' method depth will be incremented.
	this->depth = -indent_level;
    }

    void AstPrinter::Print(Core::Instructions::Instruction* instr)
    {
		switch(instr->GetType())
		{
		case Core::Instructions::InstructionType::CONSTANT_FLOAT:
			// handle this type;
			break;
		case Core::Instructions::InstructionType::VAR_DECL:
			// handle this type;
			break;
		default:
			throw RitaException(
				"AstPrinter",
				"Printing for \"" + (std::string)(*instr) + "\" is unimplemented!"
			);
		}
    }
}

