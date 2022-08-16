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
            new Core::NativeFunction(Executor::Builtins::Functions::IntOperatorPlus, Builtins::Types::BuiltinFunctionType)
        );

        // link operatorEqual to Int

        std::string operatorEqual = "operatorEqualEqual";

        Executor::Builtins::Types::IntType->AddField(
            operatorEqual,
            new Core::NativeFunction(Executor::Builtins::Functions::IntOperatorEqual, Builtins::Types::BuiltinFunctionType)
        );

        // link operatorMinus

        std::string operatorMin = "operatorMinus";

        Executor::Builtins::Types::IntType->AddField(
            operatorMin,
            new Core::NativeFunction(Executor::Builtins::Functions::IntOperatorMinus, Builtins::Types::BuiltinFunctionType)
        );

        // link operatorMul

        std::string operatorMul = "operatorMultiply";

        Executor::Builtins::Types::IntType->AddField(
            operatorMul,
            new Core::NativeFunction(Executor::Builtins::Functions::IntOperatorMul, Builtins::Types::BuiltinFunctionType)
        );

        std::string operatorDiv = "operatorDivide";

        Executor::Builtins::Types::IntType->AddField(
            operatorDiv,
            new Core::NativeFunction(Executor::Builtins::Functions::IntOperatorDiv, Builtins::Types::BuiltinFunctionType)
        );

        

        // link operatorLessThan to Int

        std::string lessThan = "operatorLessThan";

        Executor::Builtins::Types::IntType->AddField(
            lessThan,
            new Core::NativeFunction(Executor::Builtins::Functions::IntOperatorLessThan, Builtins::Types::BuiltinFunctionType)
        );

        // link unaryMinus to Int

        std::string unaryMinus = "unaryMinus";

        Executor::Builtins::Types::IntType->AddField(
            unaryMinus,
            new Core::NativeFunction(Executor::Builtins::Functions::IntOperatorUnaryMinus, Builtins::Types::BuiltinFunctionType)
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
    
        std::string sqr = "sqr";

        stack[stack.size() - 1].SetVar(sqr, new Core::NativeFunction(Executor::Builtins::Functions::SqrtNative, Executor::Builtins::Types::BuiltinFunctionType));
    
        std::string inp = "input";

        stack[stack.size() - 1].SetVar(inp, new Core::NativeFunction(Executor::Builtins::Functions::InputNative, Executor::Builtins::Types::BuiltinFunctionType));
    
        std::string intCtor = "Int";

        stack[stack.size() - 1].SetVar(intCtor, new Core::NativeFunction(Executor::Builtins::Functions::IntCtor, Executor::Builtins::Types::BuiltinFunctionType));

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
        case Core::Instructions::OpType::MUL:
            resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(
                instr->GetFirst(),
                "operatorMultiply"
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
                "operatorDivide"
            );
            break;
        case Core::Instructions::OpType::LESS_THAN:
            resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(
                instr->GetFirst(),
                "operatorLessThan"
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

    Core::RitaObject* Engine::BindThis(std::shared_ptr<Core::Instructions::AttributeInstruction> instr, Core::RitaObject* func)
    {
        // Check for func is callable

        return func;

        // Let's start bind.

        // Here, we must create a function from given instruction
        
        std::vector<std::string> buildedFunctionArguments;
        std::vector<std::shared_ptr<Core::Instructions::Instruction>> buildedFunctionBody;
        std::string buildedFunctionName = "!get";

        // Make a CallInstruction

        std::vector<std::shared_ptr<Core::Instructions::Instruction>> callArgs;

        // Push ``this`` to arguments.
        callArgs.push_back(instr->GetValue());

        // For CallInstruction, I must provide an instruction for getting-function, let's create it

        auto attrInstruction = std::make_shared<Core::Instructions::AttributeInstruction>(instr->GetValue(), instr->GetAttr(), false);

        std::shared_ptr<Core::Instructions::FunctionCallInstruction> callInstruction = std::make_shared<Core::Instructions::FunctionCallInstruction>(
            attrInstruction,
            callArgs
        );

        buildedFunctionBody.push_back(std::make_shared<Core::Instructions::ReturnInstruction>(callInstruction));

        return ExecuteInstruction(std::make_shared<Core::Instructions::FunctionDefinitionInstruction>(buildedFunctionName, buildedFunctionArguments, buildedFunctionBody));
    }

    Core::RitaObject* Engine::ExecuteInstruction(std::shared_ptr<Core::Instructions::AttributeInstruction> instr)
    {

        // Here, we get value and execute it for getting RitaObject*

        Core::RitaObject* val = ExecuteInstruction(instr->GetValue());
        
        // After this, get attriute
        std::string attr = instr->GetAttr();


        // Lookup
        if (val->GetType() == Executor::Builtins::Types::UserObject)
        {
            Core::UserObject* userObj = static_cast<Core::UserObject*>(val);

            if (userObj->Contains(attr))
            {
                if(instr->IsBindAllowed())
                    return BindThis(instr, userObj->Get(attr));
                return userObj->Get(attr);
            }
        }

        Core::Type* type = static_cast<Core::Type*>(val->GetType());
        
        if(instr->IsBindAllowed())
            return BindThis(instr, type->GetField(attr));

        return type->GetField(attr);
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

        std::vector<Core::RitaObject*> args{ExecuteInstruction(instr->GetExpr())};
        Core::BoolObject* computedVal = static_cast<Core::BoolObject*>(Builtins::Functions::BoolCtor(args));
        
        if(computedVal->GetValue())
        {
            // if ok

            stack.emplace_back(instr->GetBody(), EnviropmentType::OTHER);
        }
        else
        {
            // if not ok
            stack.emplace_back(instr->GetElseBody(), EnviropmentType::OTHER);
        }

        RunUntilComplete();

        return nullptr;
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::AssignmentInstruction* instr)
    {
        switch(instr->GetObject()->GetType())
        {
        case Core::Instructions::InstructionType::LEAF:
        {
            auto leaf = std::static_pointer_cast<Core::Instructions::Leaf>(instr->GetObject());
            
            size_t currentStack = stack.size() - 1;

            while (currentStack >= 0)
            {
                if (stack[currentStack].CheckVar(leaf->GetID())){
                    stack[currentStack].SetVar(leaf->GetID(), ExecuteInstruction(instr->GetRightInstr()));
                    return nullptr;
                }
                currentStack--;
            }

            throw Utils::RitaException(
                "Executor",
                "Variable \"" + leaf->GetID() + "\" is not declared in this scope."
            );
        }
        case Core::Instructions::InstructionType::ATTRIBUTE:
            throw Utils::RitaException("Executor::Assignment", "Currently assignment to attribute is not supported.");
            break;
        }

        return nullptr;
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::ConstantBool* instr)
    {
        return new Core::BoolObject(instr->GetData(), Builtins::Types::BoolType);
    }

    Core::RitaObject* Engine::ExecuteInstruction(Core::Instructions::UnaryOperatorInstruction* instr)
    {
        std::shared_ptr<Core::Instructions::Instruction> resultFunction;
        std::vector<std::shared_ptr<Core::Instructions::Instruction>> list{ instr->GetValue() };

        switch (instr->GetOperationType())
        {
        case Core::Instructions::OpType::PLUS:
            resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(
                instr->GetValue(),
                "unaryPlus"
            );
            break;

        case Core::Instructions::OpType::MINUS:
            resultFunction = std::make_shared<Core::Instructions::AttributeInstruction>(
                instr->GetValue(),
                "unaryMinus"
            );
            break;

        default:
            throw Utils::RitaException("Executor", (std::stringstream() << "Runtime error, unexpected operator " << instr->GetOperationType()).str());
        }

        std::shared_ptr<Core::Instructions::Instruction> result = std::make_shared<Core::Instructions::FunctionCallInstruction>(resultFunction, list);

        return ExecuteInstruction(result);
    }

    Core::RitaObject* Engine::ExecuteInstruction(std::shared_ptr<Core::Instructions::Instruction> instr)
    {
        switch (instr->GetType())
        {
        case Core::Instructions::InstructionType::IF:
            return ExecuteInstruction(static_cast<Core::Instructions::IfInstruction*>(instr.get()));
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
        case Core::Instructions::InstructionType::UNOP:
            return ExecuteInstruction(static_cast<Core::Instructions::UnaryOperatorInstruction*>(instr.get()));
        case Core::Instructions::InstructionType::ASSIGNMENT:
            return ExecuteInstruction(static_cast<Core::Instructions::AssignmentInstruction*>(instr.get()));
        default:
            throw Utils::RitaException("Executor", (std::stringstream() << "Unsupported instruction for execute \"" << instr->GetType() << "\"").str());
        }
    }

    void Engine::Initialize()
    {

    }
}