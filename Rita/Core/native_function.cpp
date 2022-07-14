#include "native_function.hpp"

namespace Core
{
    NativeFunction::NativeFunction(std::function<RitaObject*(RitaObject*)> f, Type* type)
    {
        this->nativeCallback = f;
        this->objectType = type;
    }

    RitaObject* NativeFunction::Execute(RitaObject* obj)
    {
        return this->nativeCallback(obj);
    }
}