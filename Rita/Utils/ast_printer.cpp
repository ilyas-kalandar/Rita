#include <sstream>

#include "ast_printer.hpp"
#include "rita_exception.hpp"

namespace Utils
{	
	void AstPrinter::IncrDepth()
	{
		depth += indent_level;
	}

	void AstPrinter::DecrDepth()
	{
		depth -= indent_level;
	}

	void AstPrinter::SetCursor()
	{
		//TODO(Ilyas): Can you make it better?

		auto it = this->depth;

		while(it--)
		{
			std::cout << " ";
		}
	}

	void AstPrinter::Print(const char* str, bool end = true)
	{
		IncrDepth();
		SetCursor();

		std::cout << str;

		if(end)
			std::cout << std::endl;

		DecrDepth();
	}

	void AstPrinter::PrintValue(const char* key, const char* value)
	{
		IncrDepth();
		SetCursor();
		std::cout << key << "=(" << std::endl;
		IncrDepth();
		SetCursor();
		std::cout << value << std::endl;
		DecrDepth();
		SetCursor();
		std::cout << ")" << std::endl;
		DecrDepth();
	}

	void AstPrinter::PrintValue(const char* key, Core::Instructions::Instruction* instr)
	{
		IncrDepth();
		SetCursor();
		std::cout << key << "=(" << std::endl;
		Print(instr);
		SetCursor();
		std::cout << ")" << std::endl;
		DecrDepth();
	}

	void AstPrinter::PrintValue(const char* key, const std::vector<std::shared_ptr<Core::Instructions::Instruction>>& vec)
	{
		IncrDepth();
		SetCursor();
		std::cout << key << "=(" << std::endl;

		for(auto instr : vec)
		{
			Print(instr.get());
			SetCursor();
			std::cout << "," << std::endl;			
		}

		SetCursor();
		std::cout << ")" << std::endl;
		DecrDepth();
	}

	void AstPrinter::Print(const std::string& ref, bool end = true)
	{
		Print(ref.c_str(), end);
	}

    AstPrinter::AstPrinter(size_t indent_level)
    {
		this->indent_level = indent_level;

		// By default depth equals to -indent
		// because after calling 'Print' method depth will be incremented.
		this->depth = -indent_level;
    }

	void AstPrinter::Print(Core::Instructions::VariableDeclarationInstruction* instr)
	{
		PrintValue("VarName", instr->GetVarName().c_str());
		PrintValue("Expression", instr->GetExpression().get());
	}

	void AstPrinter::Print(Core::Instructions::BinOpInstruction* instr)
	{
		std::stringstream ss;
		ss << instr->GetOperationType();
		PrintValue("Operation Type", ss.str().c_str());
		PrintValue("First operand", instr->GetFirst().get());
		PrintValue("Second operand", instr->GetSecond().get());
	}

	void AstPrinter::Print(Core::Instructions::ConstantInt* instr)
	{
		PrintValue("Value", std::to_string(instr->GetData()).c_str());
	}

	void AstPrinter::Print(Core::Instructions::Leaf* leaf)
	{
		Print(leaf->GetID());
	}

	void AstPrinter::Print(Core::Instructions::ConstantFloat* instr)
	{
		PrintValue("Value", std::to_string(instr->GetData()).c_str());
	}

    void AstPrinter::Print(Core::Instructions::Instruction* instr, size_t depth_incr)
    {
		for(auto it = 0; it < depth_incr; ++it)
			IncrDepth();

		SetCursor();

		std::cout << instr->GetType() << "(" << std::endl;

		switch(instr->GetType())
		{
		case Core::Instructions::InstructionType::CONSTANT_FLOAT:
			Print(static_cast<Core::Instructions::ConstantFloat*>(instr));
			break;
		case Core::Instructions::InstructionType::VAR_DECL:
			Print(static_cast<Core::Instructions::VariableDeclarationInstruction*>(instr));
			break;
		case Core::Instructions::InstructionType::CONSTANT_INT:
			Print(static_cast<Core::Instructions::ConstantInt*>(instr));
			break;
		case Core::Instructions::InstructionType::BINOP:
			Print(static_cast<Core::Instructions::BinOpInstruction*>(instr));
			break;
		case Core::Instructions::InstructionType::LEAF:
			Print(static_cast<Core::Instructions::Leaf*>(instr));
			break;
		default:
			throw RitaException(
				"AstPrinter",
				"Printing for \"" + (std::string)(*instr) + "\" is unimplemented!"
			);
		}

		SetCursor();
		std::cout << ")" << std::endl;

		for(auto it = 0; it < depth_incr; ++it)
			DecrDepth();
    }
}

