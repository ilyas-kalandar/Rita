#include <sstream>

#include "functions.hpp"
#include "string_obj.hpp"
#include "types.hpp"

namespace Executor
{
    namespace Builtins
    {
        namespace Functions
        {
            Core::String* ObjectToStringNative(Core::RitaObject* obj)
            {
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
        }
    }
}