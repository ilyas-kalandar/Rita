/**
 * @file functions.hpp
 * @author your name (you@domain.com)
 * @brief Definition of some built-in functions.
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "list_obj.hpp"
#include "constants.hpp"
#include "string_obj.hpp"
#include "int_obj.hpp"
#include "type.hpp"

#ifndef builtins_hpp
#define builtins_hpp

namespace Executor
{
    namespace Builtins
    {
        namespace Functions
        {
            /**
            * @brief Returns a string-representation of Object
            * 
            * @param obj Object
            * @return Core::RitaObject* 
            */
            Core::String* ObjectToStringNative(const std::vector<Core::RitaObject*>& obj);
            
            /**
             * @brief Returns a string-representation of some Integer
             * 
             * @param obj Integer
             * @return Core::String* 
             */
            Core::String* IntToStringNative(const std::vector<Core::RitaObject*>& obj);

            /**
             * @brief Returns a string-representation of some boolean.
             * 
             * @param obj Boolean
             * @return Core::String* 
             */
            Core::String* BoolToStringNative(Core::RitaObject* obj);

            /**
             * @brief Returns a string representation of List-object.
             * 
             * @param obj 
             * @return Core::String* 
             */
            Core::String* ListToStringNative(Core::RitaObject* obj);

            /**
             * @brief 
             * 
             * @param first 
             * @param second 
             * @return Core::RitaObject* 
             */
            Core::RitaObject* IntOperatorPlus(const std::vector<Core::RitaObject*>&);

            /**
             * @brief 
             * 
             * @return Core::RitaObject* 
             */
            Core::RitaObject* Print(const std::vector<Core::RitaObject*>&);

            /**
             * @brief 
             * 
             * @return Core::RitaObject* 
             */
            Core::RitaObject* BoolCtor(const std::vector<Core::RitaObject*>&);

            Core::RitaObject* IntOperatorEqual(const std::vector<Core::RitaObject*>&);

            Core::RitaObject* IntOperatorLessThan(const std::vector<Core::RitaObject*>&);

            Core::RitaObject* SqrtNative(const std::vector<Core::RitaObject*>&);

            Core::RitaObject* InputNative(const std::vector<Core::RitaObject*>&);

            Core::RitaObject* IntCtor(const std::vector<Core::RitaObject*>&);

            Core::RitaObject* IntOperatorMinus(const std::vector<Core::RitaObject*>& list);

            Core::RitaObject* IntOperatorDiv(const std::vector<Core::RitaObject*>& list);

            Core::RitaObject* IntOperatorMul(const std::vector<Core::RitaObject*>& list);
        }
    } 
}

#endif