#include "object.hpp"
#include "type.hpp"

#ifndef user_object_hpp
#define user_object_hpp

/**
 * @brief 
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
     * @brief 
     * 
     * @param field 
     * @return RitaObject* 
     */
    RitaObject* Get(std::string& field);


    /**
     * @brief 
     * 
     * @param field 
     * @param obj 
     */
    void Set(std::string& field, RitaObject* obj);
};

#endif