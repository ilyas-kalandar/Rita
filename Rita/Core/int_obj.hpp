#include "object.hpp"
#include "type.hpp"

#include "string_obj.hpp"
#include "native_function.hpp"

#ifndef int_obj_hpp
#define int_obj_hpp

namespace Core
{
	class Int : public RitaObject
	{
	protected:
		int value;
	public:
		/**
		* @brief Constructs new int object
		*
		* @param val A value for storing
		* @param objectType An object's type.
		*/
		Int(int val, Type* objectType);

		/**
		* @brief Get value of object
		*
		* @return Value of obj
		*
		*/
		int GetValue();
	};
}
#endif
