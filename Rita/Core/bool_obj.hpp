/**
 * @file bool_obj.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief 
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright Awaitable (Ilyas Qalandarzoda) (c) 2022
 * 
 */

#include "object.hpp"
#include "type.hpp"

#ifndef bool_obj_hpp
#define bool_obj_hpp

namespace Core
{
    class BoolObject : public RitaObject
    {  
    protected:
        bool val;
    public:
        /**
         * @brief Construct a new Bool Object object
         * 
         * @param val 
         * @param type
         */
        BoolObject(bool val, Type* type);

        /**
         * @brief Get the Value object
         * 
         * @return true 
         * @return false 
         */
        bool GetValue();

        /**
         * @brief Set the Value object
         * 
         * @param val 
         */
        void SetValue(bool val);
    };
}

#endif