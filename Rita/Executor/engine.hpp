/**
 * @file engine.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <list>
#include <vector>
#include <map>
#include <deque>

#include "object.hpp"

#include "Instructions/instruction.hpp"
#include "Instructions/binop_instruction.hpp"
#include "Instructions/function_call_instruction.hpp"
#include "Instructions/if_instruction.hpp"
#include "Instructions/while_instruction.hpp"
#include "Instructions/constant_float.hpp"
#include "Instructions/constant_int.hpp"
#include "Instructions/leaf.hpp"
#include "Instructions/attribute_instruction.hpp"
#include "Instructions/assignment_instruction.hpp"
#include "Instructions/var_decl_instruction.hpp"
#include "Builtins/functions.hpp"

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

class Engine
{
protected:
    std::list<Core::RitaObject*> objects;
    std::vector<std::map<std::string, Core::RitaObject*>> nameSpace;
    size_t currentNamespaceIndex = 0;
    
    Core::RitaObject* ExecuteInstruction(Core::Instructions::BinOpInstruction* instr);
    Core::RitaObject* ExecuteInstruction(Core::Instructions::ConstantInt* instr);
    Core::RitaObject* ExecuteInstruction(Core::Instructions::ConstantFloat* instr);
    Core::RitaObject* ExecuteInstruction(Core::Instructions::VariableDeclarationInstruction* instr);
    Core::RitaObject* ExecuteInstruction(Core::Instructions::FunctionCallInstruction* instr);
    Core::RitaObject* ExecuteInstruction(Core::Instructions::AttributeInstruction* instr);
    Core::RitaObject* ExecuteInstruction(Core::Instructions::Leaf* instr);
    //Core::RitaObject* ExecuteInstruction(Core::Instructions::ConstantList* instr);

public:
    Engine();
    Core::RitaObject* LookupName(std::string& name);
    void Initialize();  
    Core::RitaObject* ExecuteInstruction(std::shared_ptr<Core::Instructions::Instruction>);
    void CollectGarbage();
};
