/**
 * @file engine.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Engine's implementation.
 * @version 0.1
 * @date 2022-07-14
 *
 * @copyright Copyright Awaitable (c) 2022
 *
 */

#include <sstream>

#include "user_object.hpp"
#include "rita_exception.hpp"
#include "bool_obj.hpp"
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

        stack.emplace_back(EnviropmentType::OTHER);
        std::string print = "print";

        // add functions to global namespace
        stack[stack.size() - 1].SetVar(print, new Core::NativeFunction(Executor::Builtins::Functions::Print, Executor::Builtins::Types::BuiltinFunctionType));
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::Leaf* instr)
    {
        size_t currentStack = stack.size() - 1;

        while (currentStack >= 0)
        {
            if (stack[currentStack].CheckVar(instr->GetID()))
                return stack[currentStack].GetVar(instr->GetID());
            currentStack--;
        }

        throw Utils::RitaException(
            "Executor",
            "Variable \"" + instr->GetID() + "\" is not declared in this scope."
        );
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::BinOpInstruction* instr)
    {
        std::shared_ptr<Core::Instructions::Instruction> resultFunction;
        std::vector<std::shared_ptr<Core::Instructions::Instruction>> list{ instr->GetFirst(), instr->GetSecond() };

        switch (instr->GetOperationType())
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
            resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(
                instr->GetFirst(),
                "operatorDiv"
            );
            break;
        case Core::Instructions::OpType::EQUAL_EQUAL:
            resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(
                instr->GetFirst(),
                "operatorEqualEqual"
            );
            break;
        default:
            throw Utils::RitaException("Executor", (std::stringstream() << "Runtime error, unexpected operator " << instr->GetOperationType()).str());
        }

        std::shared_ptr<Core::Instructions::Instruction> result = std::make_shared<Core::Instructions::FunctionCallInstruction>(resultFunction, list);

        return ExecuteInstruction(result);
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::ConstantString* instr)
    {
        auto data = instr->GetData();
        return new Core::String(data, Executor::Builtins::Types::StringType);
    }

    Core::RitaObject* Engine::ExecuteInstruction(std::shared_ptr<Core::Instructions::AttributeInstruction> instr)
    {
        Core::RitaObject* val = ExecuteInstruction(instr->GetValue());
        std::string attr = instr->GetAttr();

        if (val->GetType() == Executor::Builtins::Types::UserObject)
        {
            Core::UserObject* userObj = static_cast<Core::UserObject*>(val);

            if (userObj->Contains(attr))
                return instr, userObj->Get(attr);
        }

        Core::Type* type = static_cast<Core::Type*>(val->GetType());
        
        return instr, type->GetField(attr);

    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::FunctionDefinitionInstruction* instr)
    {
        // initialize object
        auto functionObject = new Core::Function(instr, Executor::Builtins::Types::FunctionType);


        //TODO(Ilyas): Add check for existing function

        stack[stack.size() - 1].SetVar(instr->GetName(), functionObject);
        return functionObject;
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::FunctionCallInstruction* instr)
    {
        auto func = ExecuteInstruction(instr->GetFunction());

        auto type = static_cast<Core::Type*>(func->GetType());

        if (type == Executor::Builtins::Types::BuiltinFunctionType)
        {
            auto nativeFunction = static_cast<Core::NativeFunction*>(func);
            std::vector<Core::RitaObject*> functionArguments;

            for (auto arg : instr->GetFunctionArguments())
            {
                functionArguments.push_back(ExecuteInstruction(arg));
            }

            return nativeFunction->Execute(functionArguments);
        }
        else if (type == Executor::Builtins::Types::FunctionType)
        {
            Core::Function* ritaFunction = static_cast<Core::Function*>(func);
            std::vector<Core::RitaObject*> callArgs;


            for (auto arg : instr->GetFunctionArguments())
            {
                callArgs.push_back(ExecuteInstruction(arg));
            }

            if (callArgs.size() != ritaFunction->GetFuncDef()->GetArgs().size())
            {
                throw Utils::RitaException(
                    "Executor::ExecuteRitaFn",
                    (
                        std::stringstream() << "Expected " << ritaFunction->GetFuncDef()->GetArgs().size() << " given " << callArgs.size() << " in function " << ritaFunction->GetFuncDef()->GetName()
                        ).str()
                );
            }

            // Create new stack & Load instructions
            stack.emplace_back(ritaFunction->GetFuncDef()->GetBody(), EnviropmentType::FUNCTION);

            // Load args to stack

            size_t index = 0;
            for (const std::string& argName : ritaFunction->GetFuncDef()->GetArgs())
            {
                stack[stack.size() - 1].SetVar(argName, callArgs[index]);
                index++;
            }

            return RunUntilComplete();
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
        stack[stack.size() - 1].SetVar(instr->GetVarName(), value);

        return nullptr;
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::ModuleInstruction* instr)
    {
        stack.emplace_back(instr->GetInstructions(), EnviropmentType::OTHER);
        return RunUntilComplete();
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::ReturnInstruction* instr)
    {
        size_t it = stack.size() - 1;

        while (it > 0 && stack[it].GetEnvType() != EnviropmentType::FUNCTION)
        {
            it--;
        }

        if (it <= 0)
        {
            throw Utils::RitaException(
                "Executor",
                "Return \"not in function\" - not allowed."
            );
        }

        stack[it].SetRunning(false);

        if (instr->GetExpr().get() != nullptr)
            stack[it].SetReturnedValue(ExecuteInstruction(instr->GetExpr()));

        while (stack.size() != it + 1)
        {
            stack.pop_back();
        }

        return nullptr;
    }

    Core::RitaObject* Engine::RunUntilComplete()
    {
        while (stack[stack.size() - 1].IsRunning())
        {
            ExecuteInstruction(stack[stack.size() - 1].GetCurrentInstruction());
        }

        auto value = stack[stack.size() - 1].GetReturnedValue();
        stack.pop_back();
        return value;
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::IfInstruction* instr)
    {
        Core::RitaObject* computedVal = ExecuteInstruction(instr->GetExpr());
        return nullptr;
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::ConstantBool* instr)
    {
        return new Core::BoolObject(instr->GetData(), Builtins::Types::BoolType);
    }

    Core::RitaObject* Engine::ExecuteInstruction(std::shared_ptr<Core::Instructions::Instruction> instr)
    {
        switch (instr->GetType())
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
            return ExecuteInstruction(std::static_pointer_cast<Core::Instructions::AttributeInstruction>(instr));
        case Core::Instructions::InstructionType::VAR_DECL:
            return ExecuteInstruction(static_cast<Core::Instructions::VariableDeclarationInstruction*>(instr.get()));
        case Core::Instructions::InstructionType::FUNCTION_DEFINITION:
            return ExecuteInstruction(static_cast<Core::Instructions::FunctionDefinitionInstruction*>(instr.get()));
        case Core::Instructions::InstructionType::CONSTANT_STRING:
            return ExecuteInstruction(static_cast<Core::Instructions::ConstantString*>(instr.get()));
        case Core::Instructions::InstructionType::MODULE:
            return ExecuteInstruction(static_cast<Core::Instructions::ModuleInstruction*>(instr.get()));
        case Core::Instructions::InstructionType::RETURN:
            return ExecuteInstruction(static_cast<Core::Instructions::ReturnInstruction*>(instr.get()));
        case Core::Instructions::InstructionType::CONSTANT_BOOL:
            return ExecuteInstruction(static_cast<Core::Instructions::ConstantBool*>(instr.get()));
        default:
            throw Utils::RitaException("Executor", (std::stringstream() << "Unsupported instruction for execute \"" << instr->GetType() << "\"").str());
        }
    }

    void Engine::Initialize()
    {

    }
}