#include <string>

#include "object.hpp"
#include "type.hpp"

#ifndef string_obj_hpp
#define string_obj_hpp

class String : public RitaObject
{
protected:
	std::string value;
public:
	/**
	 * @brief Construct a new String object
	 * 
	 * @param val 
	 * @param type 
	 */
	String(std::string val, Type* type);

	const std::string& GetValue();
};

#endif
