#include "native_function.hpp"
#include <iostream>

namespace Core
{
    NativeFunction::NativeFunction(std::function<RitaObject*(const std::vector<RitaObject*>&)> f, Type* type) : RitaObject(type)
    {
        this->nativeCallback = f;
    }

    RitaObject* NativeFunction::Execute(const std::vector<RitaObject*>& obj)
    {
        this->nativeCallback;
        return this->nativeCallback(obj);
    }
}