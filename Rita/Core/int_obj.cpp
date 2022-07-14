#include "int_obj.hpp"
#include "native_function.hpp"
#include "string_obj.hpp"

namespace Core
{
	Int::Int(int val, Type* objectType)
	{
		this->value = val;
		this->objectType = objectType;
	}

	int Int::GetValue()
	{
		return this->value;
	}
}