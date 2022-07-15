#include <sstream>

#include "type.hpp"
#include "engine.hpp"
#include "native_function.hpp"
#include "Builtins/types.hpp"
#include "string_obj.hpp"


Engine::Engine()
{
    // Link toString to Object

    std::string toString = "toString";

    Executor::Builtins::Types::ObjectType->AddField(
        toString, 
        new Core::NativeFunction(Executor::Builtins::Functions::ObjectToStringNative, Executor::Builtins::Types::StringType)
    );

}

void Engine::Initialize()
{
}