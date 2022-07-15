#include "int_obj.hpp"
#include "native_function.hpp"
#include "string_obj.hpp"

namespace Core
{
	Int::Int(int val, Type* objectType) : RitaObject(objectType)
	{
		this->value = val;
	}

	int Int::GetValue()
	{
		return this->value;
	}
}