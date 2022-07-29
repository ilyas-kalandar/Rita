#include <string>
#include <vector>
#include <memory>

#include "Instructions/function_definition.hpp"
#include "object.hpp"
#include "type.hpp"

#ifndef func_obj_hpp
#define func_obj_hpp

namespace Core
{
    class Function : public RitaObject
    {
    protected:
        Type* objectType;
        Instructions::FunctionDefinitionInstruction* funcDef;
    public:
        /**
         * @brief Construct a new Function object
         * 
         * @param fn A function
         * @param type A type of object
         */
        Function(Instructions::FunctionDefinitionInstruction* fn, Type* type);

        /**
         * @brief Get the Function-definition.
         * 
         * @return Instructions::FunctionDefinitionInstruction* 
         */
        Instructions::FunctionDefinitionInstruction* GetFuncDef();
    };
}

#endif