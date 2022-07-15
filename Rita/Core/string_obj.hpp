/**
 * @file string_obj.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Definition of String object.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <string>

#include "object.hpp"
#include "type.hpp"

#ifndef string_obj_hpp
#define string_obj_hpp

namespace Core
{
	/**
	 * @brief String-class provides a storage for string and contains useful methods for working with contained string
	 * 
	 */
	class String : public RitaObject
	{
	protected:
		std::string value;
	public:
		/**
		 * @brief Construct a new String object
		 * 
		 * @param val Value for string
		 * @param type Type of object.
		 */
		String(std::string& val, Type* type);

		/**
		 * @brief Get the Value object
		 * 
		 * @return const std::string& 
		 */
		const std::string& GetValue();
	};
}
#endif
