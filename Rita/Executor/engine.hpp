/**
 * @file engine.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Engine's definition.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <list>
#include <vector>
#include <map>
#include <deque>

#include "object.hpp"

#include "Instructions/constant_bool.hpp"
#include "Instructions/if_instruction.hpp"
#include "Instructions/return_instruction.hpp"
#include "Instructions/constant_string.hpp"
#include "Instructions/instruction.hpp"
#include "Instructions/binop_instruction.hpp"
#include "Instructions/function_call_instruction.hpp"
#include "Instructions/if_instruction.hpp"
#include "Instructions/function_definition.hpp"
#include "Instructions/while_instruction.hpp"
#include "Instructions/constant_float.hpp"
#include "Instructions/constant_int.hpp"
#include "Instructions/leaf.hpp"
#include "Instructions/attribute_instruction.hpp"
#include "Instructions/assignment_instruction.hpp"
#include "Instructions/var_decl_instruction.hpp"
#include "Instructions/module_instruction.hpp"
#include "Builtins/functions.hpp"
#include "enviropment.hpp"


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
        }
    }

    class Engine
    {
    protected:
        std::vector<Enviropment> stack;
        size_t currentNamespaceIndex = 0;

        Core::RitaObject* LinkSelf(std::shared_ptr<Core::Instructions::AttributeInstruction> instr, Core::RitaObject* obj);
        
        Core::RitaObject* ExecuteInstruction(Core::Instructions::BinOpInstruction* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::ConstantInt* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::ConstantFloat* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::VariableDeclarationInstruction* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::FunctionCallInstruction* instr);
        Core::RitaObject* ExecuteInstruction(std::shared_ptr<Core::Instructions::AttributeInstruction> instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::Leaf* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::FunctionDefinitionInstruction* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::ConstantString* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::ModuleInstruction* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::ReturnInstruction* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::IfInstruction* instr);
        Core::RitaObject* ExecuteInstruction(Core::Instructions::ConstantBool* instr);
        //Core::RitaObject* ExecuteInstruction(Core::Instructions::ConstantList* instr);

        Core::RitaObject* RunUntilComplete();

    public:
        /**
         * @brief Construct a new Engine object
         * 
         */
        Engine();
        
        void Initialize();  

        /**
         * @brief 
         * 
         * @return Core::RitaObject* 
         */
        Core::RitaObject* ExecuteInstruction(std::shared_ptr<Core::Instructions::Instruction>);
    };
}