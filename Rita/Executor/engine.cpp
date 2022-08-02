#include <sstream>

#include "user_object.hpp"
#include "rita_exception.hpp"
#include "Instructions/constant_list.hpp"
#include "Instructions/constant_string.hpp"
#include "type.hpp"
#include "engine.hpp"
#include "func_obj.hpp"
#include "native_function.hpp"
#include "string_obj.hpp"


namespace Executor
{
    namespace Builtins
    {
        namespace Types
        {
            extern Core::Type* BoolType;
            extern Core::Type* IntType;
            extern Core::Type* BuiltinFunctionType;
            extern Core::Type* UserObject;
            extern Core::Type* StringType;
            extern Core::Type* ObjectType;
            extern Core::Type* FunctionType;
        }
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

    // add functions to global namespace
    nameSpace[0]["print"] = new Core::NativeFunction(Executor::Builtins::Functions::Print, Executor::Builtins::Types::BuiltinFunctionType);
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::Leaf* instr)
{
    auto curNamespace = nameSpace.size() - 1;
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
    case Core::Instructions::OpType::DIV:
        resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(instr->GetFirst(),
        "operatorDiv"
        );
        break;
    default:
        throw Utils::RitaException("Executor", (std::stringstream() << "Runtime error, unexpected operator " << instr->GetOperationType()).str());
    }

    std::shared_ptr<Core::Instructions::Instruction> result = std::make_shared<Core::Instructions::FunctionCallInstruction>(resultFunction, list);

    return ExecuteInstruction(result);    
}

Core::RitaObject* LinkSelf(Core::RitaObject* value, Core::RitaObject* functionObj)
{

    throw Utils::RitaException("Executor", "Unimplemented!!!");

    // std::shared_ptr<Core::Instructions::FunctionCallInstruction> call = std::make_shared<Core::Instructions::FunctionCallInstruction>(

    // );

    // std::vector<std::shared_ptr<Core::Instructions::Instruction>> fnBody{
        
    // };
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::ConstantString* instr)
{
    auto data = instr->GetData();
    return new Core::String(data, Executor::Builtins::Types::StringType);
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::AttributeInstruction* instr)
{
    //TODO(Ilyas):
    // Here we must check
    // if attr from instr->GetValue() is method, make function like f(args) => method(instr.GetValue(), args) from it


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

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::FunctionDefinitionInstruction* instr)
{
    // initialize object
    auto functionObject = new Core::Function(instr, Executor::Builtins::Types::FunctionType);

    this->nameSpace[this->currentNamespaceIndex][instr->GetName()] = functionObject;

    return functionObject;
}

Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::FunctionCallInstruction* instr)
{
    auto func = ExecuteInstruction(instr->GetFunction());

    auto type = static_cast<Core::Type*>(func->GetType());

    if(type == Executor::Builtins::Types::BuiltinFunctionType)
    {
        auto nativeFunction = static_cast<Core::NativeFunction*>(func);
        std::vector<Core::RitaObject*> functionArguments;

        for(auto arg : instr->GetFunctionArguments())
        {
            functionArguments.push_back(ExecuteInstruction(arg));
        }

        return nativeFunction->Execute(functionArguments);
    }
    else if(type == Executor::Builtins::Types::FunctionType)
    {
        Core::Function* ritaFunction = static_cast<Core::Function*>(func);
        std::vector<Core::RitaObject*> callArgs;


        for(auto arg : instr->GetFunctionArguments())
        {
            callArgs.push_back(ExecuteInstruction(arg));
        }
        if(callArgs.size() != ritaFunction->GetFuncDef()->GetArgs().size())
        {
            throw Utils::RitaException(
                "Executor::ExecuteRitaFn",
                (
                    std::stringstream() << "Expected " << ritaFunction->GetFuncDef()->GetArgs().size() << " given " << callArgs.size() << " in function " << ritaFunction->GetFuncDef()->GetName()
                ).str()
            );
        }

        this->nameSpace.emplace_back();

        for(int i = 0; i < callArgs.size(); ++i)
        {
            nameSpace[nameSpace.size() - 1][ritaFunction->GetFuncDef()->GetArgs()[i]] = callArgs[i];
        }


        for(auto body_instr : ritaFunction->GetFuncDef()->GetBody())
        {
            ExecuteInstruction(body_instr);
        }

        nameSpace.pop_back();        
        return nullptr;
    }

    throw Utils::RitaException("Executor", "Object \"" + type->GetTypeName() + "\" is not callable.");
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
    case Core::Instructions::InstructionType::FUNCTION_DEFINITION:
        return ExecuteInstruction(static_cast<Core::Instructions::FunctionDefinitionInstruction*>(instr.get()));
    case Core::Instructions::InstructionType::CONSTANT_STRING:
        return ExecuteInstruction(static_cast<Core::Instructions::ConstantString*>(instr.get()));
    default:
        throw Utils::RitaException("Executor", (std::stringstream() << "Unsupported instruction for execute \"" << instr->GetType() << "\"").str());
    }
}


void Engine::Initialize()
{
}