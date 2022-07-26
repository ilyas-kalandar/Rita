#include <sstream>

#include "user_object.hpp"
#include "rita_exception.hpp"
#include "Instructions/constant_list.hpp"
#include "type.hpp"
#include "engine.hpp"
#include "native_function.hpp"
#include "string_obj.hpp"


namespace Executor
{
    namespace Builtins{
        namespace Types{
extern Core::Type* BoolType;
extern Core::Type* IntType;
extern Core::Type* BuiltinFunctionType;
extern Core::Type* UserObject;
extern Core::Type* StringType;
extern Core::Type* ObjectType;}
    }
}

Engine::Engine()
{
    // Link toString to Object

    std::string toString = "toString";

    Executor::Builtins::Types::ObjectType->AddField(
        toString, 
        new Core::NativeFunction(Executor::Builtins::Functions::ObjectToStringNative, Executor::Builtins::Types::BuiltinFunctionType)
    );

    // link operatorPlus to Int
    
    std::string operatorPlus = "operatorPlus";

    Executor::Builtins::Types::IntType->AddField(
        operatorPlus,
        new Core::NativeFunction(Executor::Builtins::Functions::IntOperatorPlus, Executor::Builtins::Types::BuiltinFunctionType)
    );
    

    // Link Integer's toString to Int

    Executor::Builtins::Types::IntType->AddField(
        toString,
        new Core::NativeFunction(Executor::Builtins::Functions::IntToStringNative, Executor::Builtins::Types::BuiltinFunctionType)
    );

    nameSpace.emplace_back();
    nameSpace[0]["print"] = new Core::NativeFunction(Executor::Builtins::Functions::Print, Executor::Builtins::Types::BuiltinFunctionType);
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::Leaf* instr)
{
    auto curNamespace = this->currentNamespaceIndex;
    while(curNamespace != -1)
    {
        if(nameSpace[curNamespace].find(instr->GetID()) != nameSpace[curNamespace].end())
            return nameSpace[curNamespace][instr->GetID()];
        curNamespace--;
    }

    throw Utils::RitaException(
        "Executor",
        "Variable \"" + instr->GetID() + "\" is not declared in this scope."
    );
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::BinOpInstruction* instr)
{
    std::shared_ptr<Core::Instructions::Instruction> resultFunction;
    std::vector<std::shared_ptr<Core::Instructions::Instruction>> list{instr->GetFirst(), instr->GetSecond()};

    switch(instr->GetOperationType())
    {
    case Core::Instructions::OpType::PLUS:
        resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(
            instr->GetFirst(),
            "operatorPlus"
        );
        break;
    case Core::Instructions::OpType::MINUS:
        resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(
            instr->GetFirst(),
            "operatorMinus"
        );
        break;
    default:
        throw std::runtime_error("ExecuteInstruction: Unexpected operator!!!!");
    }

    std::shared_ptr<Core::Instructions::Instruction> result = std::make_shared<Core::Instructions::FunctionCallInstruction>(resultFunction, list);

    return ExecuteInstruction(result);    
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::AttributeInstruction* instr)
{
    Core::RitaObject* val = ExecuteInstruction(instr->GetValue());
    std::string attr = instr->GetAttr();

    if(val->GetType() == Executor::Builtins::Types::UserObject)
    {
        Core::UserObject* userObj = static_cast<Core::UserObject*>(val);

        if(userObj->Contains(attr))
            return userObj->Get(attr);
    }

    Core::Type* type = static_cast<Core::Type*>(val->GetType());

    return type->GetField(attr);
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::FunctionCallInstruction* instr)
{
    auto func = ExecuteInstruction(instr->GetFunction());

    auto type = static_cast<Core::Type*>(func->GetType());

    if(type != Executor::Builtins::Types::BuiltinFunctionType)
    {
        throw Utils::RitaException("Executor", "Object \"" + type->GetTypeName() + "\" is not callable.");
    }

    auto nativeFunction = static_cast<Core::NativeFunction*>(func);

    std::vector<Core::RitaObject*> functionArguments;

    for(auto arg : instr->GetFunctionArguments())
    {
        functionArguments.push_back(ExecuteInstruction(arg));
    }

    return nativeFunction->Execute(functionArguments);
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::ConstantInt* instr)
{
    return new Core::Int(instr->GetData(), Executor::Builtins::Types::IntType);
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::VariableDeclarationInstruction* instr)
{
    auto value = ExecuteInstruction(instr->GetExpression());

    //TODO(Ilyas): Add checks
    this->nameSpace[this->currentNamespaceIndex][instr->GetVarName()] = value;
}

Core::RitaObject* Engine::ExecuteInstruction(std::shared_ptr<Core::Instructions::Instruction> instr)
{
    //std::cout << "Executing " << instr->GetType() << std::endl;
    switch(instr->GetType())
    {
    case Core::Instructions::InstructionType::LEAF:
        return ExecuteInstruction(static_cast<Core::Instructions::Leaf*>(instr.get()));
    case Core::Instructions::InstructionType::BINOP:
        return ExecuteInstruction(static_cast<Core::Instructions::BinOpInstruction*>(instr.get()));
    case Core::Instructions::InstructionType::CONSTANT_INT:
        return ExecuteInstruction(static_cast<Core::Instructions::ConstantInt*>(instr.get()));
    case Core::Instructions::InstructionType::FUNCTION_CALL:
        return ExecuteInstruction(static_cast<Core::Instructions::FunctionCallInstruction*>(instr.get()));
    case Core::Instructions::InstructionType::ATTRIBUTE:
        return ExecuteInstruction(static_cast<Core::Instructions::AttributeInstruction*>(instr.get()));
    case Core::Instructions::InstructionType::VAR_DECL:
        return ExecuteInstruction(static_cast<Core::Instructions::VariableDeclarationInstruction*>(instr.get()));
    default:
        throw Utils::RitaException("Executor", (std::stringstream() << "Unsupported instruction for execute \"" << instr->GetType() << "\"").str());
    }
}


void Engine::Initialize()
{
}