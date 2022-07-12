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

#include "types.hpp"

#ifndef rita_object_hpp
#define rita_object_hpp

/**
 * @brief 
 * 
 */
class RitaObject
{
protected:
    size_t referenceCounter;
    Type type;
public:
    /**
    * @brief Constructs new RitaObject
    */
    RitaObject();

    /*
    * @brief Get Object's type.
    */
    const Type& GetType();

    /**
    * @brief Get total references count
    * 
    */
    const size_t& GetReferenceCount();
};

#endif