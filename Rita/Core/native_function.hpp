#pragma once

#include <functional>

#include "object.hpp"
#include "type.hpp"

#ifndef native_function_hpp
#define native_function_hpp

class NativeFunction : public RitaObject
{
protected:
	std::function<RitaObject* (RitaObject*)> nativeCallback;
public:
	NativeFunction(std::function<RitaObject* (RitaObject*)> f, Type* type);

    /**
     * @brief Start the function executing.
     *
     * @return RitaObject* object-result.
     */
	RitaObject* Execute(RitaObject* arg);
};

#endif
