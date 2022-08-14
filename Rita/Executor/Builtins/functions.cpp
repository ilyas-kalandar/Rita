#include <cmath>
#include <sstream>

#include "rita_exception.hpp"
#include "functions.hpp"
#include "bool_obj.hpp"
#include "string_obj.hpp"
#include "types.hpp"

namespace Executor
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

    namespace Builtins
    {
        namespace Functions
        {
            Core::String* ObjectToStringNative(const std::vector<Core::RitaObject*>& args)
            {
                auto obj = args[0];

                // Any object in Rita have type, lets get type
                // Yes, obj->GetType() returns RitaObject*, but believe me, you can safely cast it to Core::Type*
                Core::Type* objectType = static_cast<Core::Type*>(obj->GetType());

                std::stringstream ss;

                // Put information about object

                // Firstly add info about type

                ss << "Object<" << objectType->GetTypeName() << "> ";

                // Also add info about address

                ss << "at [" << obj << "]";

                // But, we must return a RitaObject*, yes?
                // Let's build string

                std::string resultString = ss.str();

                return new Core::String(resultString, Types::StringType);
            }

            Core::String* IntToStringNative(const std::vector<Core::RitaObject*>& args)
            {
                auto obj = static_cast<Core::Int*>(args[0]);
                auto res = std::to_string(obj->GetValue());
                return new Core::String(res, Types::StringType);
            }

            Core::RitaObject* IntOperatorPlus(const std::vector<Core::RitaObject*>& list)
            {
                auto self = static_cast<Core::Int*>(list[0]);
                auto second = list[1];

                auto secType = static_cast<Core::Type*>(second->GetType());

                if(secType->GetTypeName() == Types::IntType->GetTypeName())
                {
                    return new Core::Int(self->GetValue() + static_cast<Core::Int*>(second)->GetValue(), Types::IntType);
                }

                throw Utils::RitaException(
                    "Executor", 
                    "Runtime error, expected 'int' or 'float' type, got '" + secType->GetTypeName() + "'"
                );
            }

            Core::RitaObject* Print(const std::vector<Core::RitaObject*>& args)
            {
                for(auto obj : args)
                {
                    if(static_cast<Core::Type*>(obj->GetType())->GetTypeName() != "String")
                    {
                        throw Utils::RitaException(
                            "Print", 
                            "Expected string, got \"" + static_cast<Core::Type*>(obj->GetType())->GetTypeName() + "\""
                        );
                    }
                    std::cout << static_cast<Core::String*>(obj)->GetValue() << " ";
                }

                std::cout << std::endl;

                return nullptr;
            }

            Core::RitaObject* BoolCtor(const std::vector<Core::RitaObject*>& vec)
            {
                auto arg = vec[0];

                auto type = arg->GetType();

                if(type == Builtins::Types::BoolType)
                {
                    Core::BoolObject* tmpBool = static_cast<Core::BoolObject*>(arg);
                    return new Core::BoolObject(tmpBool->GetValue(), Builtins::Types::BoolType);
                }
                else 
                {
                    throw Utils::RitaException(
                        "Bool::Constructor",
                        "Expected int, float or bool, given \"" + static_cast<Core::Type*>(arg->GetType())->GetTypeName() + "\""
                    );
                }
            }

            Core::RitaObject* BoolToStringNative(const std::vector<Core::RitaObject*>& vec)
            {
                auto arg = vec[0];
                std::string _tr = "true";
                std::string _fl = "false";

                Core::BoolObject* tmpBool = static_cast<Core::BoolObject*>(arg);

                if(tmpBool->GetValue())
                {
                    return new Core::String(_tr, Types::StringType);
                }

                return new Core::String(_fl, Types::StringType);
            }

            Core::RitaObject* IntOperatorEqual(const std::vector<Core::RitaObject*>& list)
            {
                auto self = static_cast<Core::Int*>(list[0]);
                auto second = list[1];

                auto secType = static_cast<Core::Type*>(second->GetType());

                if(secType->GetTypeName() == Types::IntType->GetTypeName())
                {
                    return new Core::BoolObject(self->GetValue() == static_cast<Core::Int*>(second)->GetValue(), Types::BoolType);
                }

                throw Utils::RitaException(
                    "Executor", 
                    "Runtime error, expected 'int' or 'float' type, got '" + secType->GetTypeName() + "'"
                );
            }

            Core::RitaObject* IntOperatorLessThan(const std::vector<Core::RitaObject*>& list)
            {
                auto self = static_cast<Core::Int*>(list[0]);
                auto second = list[1];

                auto secType = static_cast<Core::Type*>(second->GetType());

                if(secType->GetTypeName() == Types::IntType->GetTypeName())
                {
                    return new Core::BoolObject(self->GetValue() < static_cast<Core::Int*>(second)->GetValue(), Types::BoolType);
                }

                throw Utils::RitaException(
                    "Executor", 
                    "Runtime error, expected 'int' or 'float' type, got '" + secType->GetTypeName() + "'"
                );
            }

            Core::RitaObject* SqrtNative(const std::vector<Core::RitaObject*>& list)
            {
                auto obj = list[0];
                
                if(static_cast<Core::Type*>(obj->GetType())->GetTypeName() != "Int")
                {
                    throw Utils::RitaException(
                        "Print", 
                        "Expected string, got \"" + static_cast<Core::Type*>(obj->GetType())->GetTypeName() + "\""
                    );
                }
                return new Core::Int(std::sqrt(static_cast<Core::Int*>(obj)->GetValue()), Types::IntType);
            
            }

            Core::RitaObject* InputNative(const std::vector<Core::RitaObject*>& list)
            {
                std::string buff;

                std::getline(std::cin, buff);

                return new Core::String(buff, Types::StringType);
            }

            Core::RitaObject* IntCtor(const std::vector<Core::RitaObject*>& vec)
            {
                auto arg = vec[0];

                auto type = arg->GetType();

                if(type == Builtins::Types::StringType)
                {
                    Core::String* tmpStr = static_cast<Core::String*>(arg);
                    std::cout << "IntCtor, tmpStr value " << tmpStr->GetValue() << std::endl;
                    return new Core::Int(std::stoi(tmpStr->GetValue()), Builtins::Types::IntType);
                }
                else 
                {
                    throw Utils::RitaException(
                        "Int::Constructor",
                        "Expected int, string, float or bool, given \"" + static_cast<Core::Type*>(arg->GetType())->GetTypeName() + "\""
                    );
                }
            }

            Core::RitaObject* IntOperatorDiv(const std::vector<Core::RitaObject*>& list)
            {
                auto self = static_cast<Core::Int*>(list[0]);
                auto second = list[1];

                auto secType = static_cast<Core::Type*>(second->GetType());

                if(secType->GetTypeName() == Types::IntType->GetTypeName())
                {
                    return new Core::Int(self->GetValue() / static_cast<Core::Int*>(second)->GetValue(), Types::IntType);
                }

                throw Utils::RitaException(
                    "Executor", 
                    "Runtime error, expected 'int' or 'float' type, got '" + secType->GetTypeName() + "'"
                );
            }

            Core::RitaObject* IntOperatorMul(const std::vector<Core::RitaObject*>& list)
            {
                auto self = static_cast<Core::Int*>(list[0]);
                auto second = list[1];

                auto secType = static_cast<Core::Type*>(second->GetType());

                if(secType->GetTypeName() == Types::IntType->GetTypeName())
                {
                    return new Core::Int(self->GetValue() * static_cast<Core::Int*>(second)->GetValue(), Types::IntType);
                }

                throw Utils::RitaException(
                    "Executor", 
                    "Runtime error, expected 'int' or 'float' type, got '" + secType->GetTypeName() + "'"
                );
            }

            Core::RitaObject* IntOperatorMinus(const std::vector<Core::RitaObject*>& list)
            {
                auto self = static_cast<Core::Int*>(list[0]);
                auto second = list[1];

                auto secType = static_cast<Core::Type*>(second->GetType());

                if(secType->GetTypeName() == Types::IntType->GetTypeName())
                {
                    return new Core::Int(self->GetValue() - static_cast<Core::Int*>(second)->GetValue(), Types::IntType);
                }

                throw Utils::RitaException(
                    "Executor", 
                    "Runtime error, expected 'int' or 'float' type, got '" + secType->GetTypeName() + "'"
                );
            }
        }
    }
}