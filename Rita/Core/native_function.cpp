#include "native_function.hpp"

namespace Core
{
    NativeFunction::NativeFunction(std::function<RitaObject*(RitaObject*)> f, Type* type) : RitaObject(type)
    {
        this->nativeCallback = f;
    }

    RitaObject* NativeFunction::Execute(RitaObject* obj)
    {
        return this->nativeCallback(obj);
    }
}