/**
 * @file type.h
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Definition of Rita's type.
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <variant>

#include "object.hpp"

#ifndef type_hpp
#define type_hpp

class Type : public RitaObject
{
protected:
    std::string typeName;
    std::map<std::string, RitaObject*> definedFields;
public:
    /**
     * @brief Construct a new Type object
     * 
     * @param name 
     */
    Type(std::string name);

    /**
     * @brief Add field to type
     * 
     * @param name Field's name
     * @param obj Object of field
     */
    void AddField(std::string& name, RitaObject* obj);
    
    /**
     * @brief Get the Field object
     * 
     * @param name 
     */
    RitaObject* GetField(std::string& name);

    /**
     * @brief Get fields of object
     * 
     * @return const std::map<std::string, RitaObject*>& 
     */
    const std::map<std::string, RitaObject*>& GetFields();
};

#endif