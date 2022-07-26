#include "object.hpp"
#include "type.hpp"

#ifndef user_object_hpp
#define user_object_hpp

namespace Core
{
    /**
     * @brief Container for storing Rita's user's object.
     * 
     * Contains fields of some object.
     * 
     */
    class UserObject : public RitaObject
    {
    protected:
        std::map<std::string, RitaObject*> fields;
    public:
        /**
         * @brief Construct a new User Object object
         * 
         * @param type 
         */
        UserObject(Type* type);

        /**
         * @brief Get some field of UserObject
         * 
         * @param field Field's name
         * @return RitaObject* 
         */
        RitaObject* Get(std::string& field);

        /**
         * @brief 
         * 
         * @param field 
         * @return true 
         * @return false 
         */
        bool Contains(std::string& field);


        /**
         * @brief Binds object to field
         * 
         * @param field Field's name
         * @param obj Object for binding
         */
        void Set(std::string& field, RitaObject* obj);
    };
}

#endif