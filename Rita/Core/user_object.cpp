#include "user_object.hpp"
#include "rita_exception.hpp"

namespace Core
{
    UserObject::UserObject(Type* type) : RitaObject(type)
    {
    }

    RitaObject* UserObject::Get(std::string& field)
    {
        if(Contains(field))
            return fields[field];

        throw Utils::RitaException(
            "Type.Get",
            "Field \"" + field + "\" not found."
        );
    }

    bool UserObject::Contains(std::string& f)
    {
        return !(fields.find(f) == fields.end());
    }
}