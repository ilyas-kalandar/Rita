#include "ast_printer.hpp"

void _PrintSpaces(size_t spaces)
{
    while(spaces--) std::cout << " ";
}

namespace Utils::AstPrinter
{
    void PrintBinaryOperation(Core::Instructions::BinOpInstruction* instr, size_t level)
    {
        _PrintSpaces(level);
        std::cout << "BinaryOperation(" << std::endl;
        _PrintSpaces(level + 2);
        
        // Print operation type

        switch(instr->GetOperationType())
        {
        case Core::Instructions::OpType::PLUS:
            std::cout << "+" << std::endl;
            break;
        case Core::Instructions::OpType::DIV:
            std::cout << "/" << std::endl;
            break;
        case Core::Instructions::OpType::MUL:
            std::cout << "*" << std::endl;
            break;
        case Core::Instructions::OpType::MINUS:
            std::cout << "-" << std::endl;
            break;
        case Core::Instructions::OpType::GREATER_THAN:
            std::cout << "<" << std::endl;
            break;
        default:
            throw std::runtime_error("Printing unimplemented for this OpType!");
        }

        PrintAstTree(instr->GetFirst().get(), level + 2);
        PrintAstTree(instr->GetSecond().get(), level + 2);

        _PrintSpaces(level);
        std::cout << ")" << std::endl;
    }

    void PrintLeaf(Core::Instructions::Leaf* instr, size_t level)
    {
        _PrintSpaces(level);
        std::cout << "Leaf(" << instr->GetID() << ")" << std::endl;
    }

    void PrintFunctionCall(Core::Instructions::FunctionCallInstruction* instr, size_t level)
    {
        _PrintSpaces(level);
        
        std::cout << "FunctionCall(" << std::endl;
        _PrintSpaces(level + 2);
        std::cout << "Func=(" << std::endl;
        
        PrintAstTree(instr->GetFunction().get(), level + 4);

        _PrintSpaces(level + 2);
        std::cout << ")" << std::endl;

        _PrintSpaces(level + 2);

        std::cout << "Args[count=" << instr->GetFunctionArguments().size() << "]" <<  "(" << std::endl;

        for(const std::shared_ptr<Core::Instructions::Instruction>& arg : instr->GetFunctionArguments())
        {
            PrintAstTree(arg.get(), level + 4);
            _PrintSpaces(level + 4);
            std::cout << "," << std::endl;
        }

        _PrintSpaces(level + 2);

        std::cout << ")" << std::endl;

        _PrintSpaces(level);

        std::cout << ")" << std::endl;

    }

    void PrintAssignment(Core::Instructions::AssignmentInstruction* instr, size_t level){}
    
    void PrintAttribute(Core::Instructions::AttributeInstruction* instr, size_t level)
    {
        _PrintSpaces(level);
        std::cout << "Attribute(" << std::endl;
        _PrintSpaces(level + 2);
        std::cout << "Value=(" << std::endl;
        PrintAstTree(instr->GetValue().get(), level + 4);

        _PrintSpaces(level + 2);
        std::cout << ")" << std::endl;

        _PrintSpaces(level + 2);

        std::cout << "Attr=(" << std::endl;
        
        _PrintSpaces(level + 4);
        std::cout << instr->GetAttr() << std::endl;
        _PrintSpaces(level + 2);
        std::cout << ")" << std::endl;
        _PrintSpaces(level);
        std::cout << ")" << std::endl;
    }

    void PrintUnaryOp(Core::Instructions::UnaryOperatorInstruction* instr, size_t level)
    {
        _PrintSpaces(level);
        std::cout << "UnaryOperation(" << std::endl;
        _PrintSpaces(level + 2);

        switch (instr->GetOperationType())
        {
        case Core::Instructions::OpType::PLUS:
            std::cout << "+" << std::endl;
            break;
        case Core::Instructions::OpType::DIV:
            std::cout << "/" << std::endl;
            break;
        case Core::Instructions::OpType::MUL:
            std::cout << "*" << std::endl;
            break;
        case Core::Instructions::OpType::MINUS:
            std::cout << "-" << std::endl;
            break;
        case Core::Instructions::OpType::GREATER_THAN:
            std::cout << "<" << std::endl;
            break;
        default:
            throw std::runtime_error("Printing unimplemented for this OpType!");
        }

        _PrintSpaces(level + 2);
        std::cout << "Value=(" << std::endl;
        PrintAstTree(instr->GetValue().get(), level + 4);

        _PrintSpaces(level + 2);
        std::cout << ")" << std::endl;

        _PrintSpaces(level  );
        std::cout << ")" << std::endl;
    }

    template<class T>
    void PrintConst(const T& data, size_t level)
    {
        _PrintSpaces(level);
        std::cout << "Constant(" << std::endl;

        _PrintSpaces(level + 2);

        std::cout << data << std::endl;

        _PrintSpaces(level);

        std::cout << ")" << std::endl;
    }

    void PrintConstList(Core::Instructions::ConstantList* list, size_t level)
    {
         _PrintSpaces(level);
        std::cout << "List[" << std::endl;

        for(auto now : list->GetList())
        {
            PrintAstTree(now.get(), level + 2);
            _PrintSpaces(level + 2);
            std::cout << "," << std::endl;
        }

        _PrintSpaces(level);

        std::cout << "]" << std::endl;
    }

    void PrintIndex(Core::Instructions::IndexInstruction* instr, size_t level)
    {
        _PrintSpaces(level);

        std::cout << "GetIndex(" << std::endl;

        _PrintSpaces(level + 2);
        std::cout << "Value=(" << std::endl;

        PrintAstTree(instr->GetValue().get(), level + 4);
        _PrintSpaces(level + 2);

        std::cout << ")" << std::endl;

        _PrintSpaces(level + 2);

        std::cout << "Index=(" << std::endl;

        PrintAstTree(instr->GetIndex().get(), level + 4);
        _PrintSpaces(level + 2);

        std::cout << ")" << std::endl;

        _PrintSpaces(level);

        std::cout << ")" << std::endl;

    }

    void PrintVarDecl(Core::Instructions::VariableDeclarationInstruction* instr, size_t level)
    {
        _PrintSpaces(level);

        std::cout << "VariableDeclaration(" << std::endl;

        _PrintSpaces(level + 2);
        std::cout << "Name=(" << std::endl;
        _PrintSpaces(level + 4);
        std::cout << instr->GetVarName() << std::endl;
        _PrintSpaces(level + 2);

        std::cout << ")" << std::endl;

        _PrintSpaces(level + 2);

        std::cout << "Value=(" << std::endl;

        PrintAstTree(instr->GetExpression().get(), level + 4);
        _PrintSpaces(level + 2);

        std::cout << ")" << std::endl;

        _PrintSpaces(level);

        std::cout << ")" << std::endl;
    }

    void PrintIf(Core::Instructions::IfInstruction* instr, size_t level)
    {
        _PrintSpaces(level);
        std::cout << "IfStatement(" << std::endl;
        _PrintSpaces(level + 2);

        std::cout << "Condition=(" << std::endl;

        PrintAstTree(instr->GetExpr().get(), level + 4);

        _PrintSpaces(level + 2);

        std::cout << ")," << std::endl; 

        _PrintSpaces(level + 2);

        std::cout << "Body=(" << std::endl;

        for(auto now : instr->GetBody())
        {
            PrintAstTree(now.get(), level + 4);
            _PrintSpaces(level + 3);
            std::cout << "," << std::endl;
        }

        _PrintSpaces(level + 2);

        std::cout << ")" << std::endl;

        _PrintSpaces(level);

        std::cout << ")" << std::endl;
    }

    void PrintAstTree(Core::Instructions::Instruction* instr, size_t level)
    {
       // Unpack the instruction.
        switch(instr->GetType())
        {
        case Core::InstructionType::BINOP:
            PrintBinaryOperation(static_cast<Core::Instructions::BinOpInstruction*>(instr), level);
            break;
        case Core::InstructionType::FUNCTION_CALL:
            PrintFunctionCall(static_cast<Core::Instructions::FunctionCallInstruction*>(instr), level);
            break;
        case Core::InstructionType::LEAF:
            PrintLeaf(static_cast<Core::Instructions::Leaf*>(instr), level);
            break;
        case Core::InstructionType::ATTRIBUTE:
            PrintAttribute(static_cast<Core::Instructions::AttributeInstruction*>(instr), level);
            break;
        case Core::InstructionType::UNOP:
            PrintUnaryOp(static_cast<Core::Instructions::UnaryOperatorInstruction*>(instr), level);
            break;
        case Core::InstructionType::CONSTANT_FLOAT:
            PrintConst<long double>((static_cast<Core::Instructions::ConstantFloat*>(instr))->GetData(), level);
            break;
        case Core::InstructionType::CONSTANT_INT:
            PrintConst<int>((static_cast<Core::Instructions::ConstantInt*>(instr))->GetData(), level);
            break;
        case Core::InstructionType::CONSTANT_STRING:
            PrintConst<const std::string&>((static_cast<Core::Instructions::ConstantString*>(instr))->GetData(), level);
            break;
        case Core::InstructionType::CONSTANT_LIST:
            PrintConstList(static_cast<Core::Instructions::ConstantList*>(instr), level);
            break;
        case Core::InstructionType::INDEX:
            PrintIndex(static_cast<Core::Instructions::IndexInstruction*>(instr), level);
            break;
        case Core::InstructionType::VAR_DECL:
            PrintVarDecl(static_cast<Core::Instructions::VariableDeclarationInstruction*>(instr), level);
            break;
        case Core::InstructionType::IF:
            PrintIf(static_cast<Core::Instructions::IfInstruction*>(instr), level);
            break;
        default:
            std::cout << "Instr: " << *instr << std::endl;
            throw std::runtime_error("For this instruction, printing is unavailable! ");
        }
    }

    
}