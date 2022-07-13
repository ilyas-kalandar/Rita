#include "user_object.hpp"

UserObject::UserObject(Type* type)
{
    this->objectType = type;
}

RitaObject* UserObject::Get(std::string& field)
{
    if(this->fields.find(field) != this->fields.end())
    {
        return this->fields[field];
    }
    
    Type* objType = static_cast<Type*>(this->objectType);

    if(objType->GetFields().find(field) == objType->GetFields().end())
    {
        throw std::runtime_error("Blyat, field not found!");
    }

    return objType->GetField(field);
}