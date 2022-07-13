/**
 * @file object.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief RitaObject's definition.
 * @version 0.2
 * @date 2022-07-12
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */


#include <variant>
#include <string>
#include <vector>
#include <map>

#ifndef rita_object_hpp
#define rita_object_hpp

class RitaObject
{
protected:
    size_t refCounter;
    RitaObject* objectType;
public:
    /**
     * @brief Get count of references
     * 
     * @return size_t 
     */
    size_t GetRefCount();


    /**
     * @brief Get the Type object
     * 
     * @return RitaObject* 
     */
    RitaObject* GetType();
};

#endif