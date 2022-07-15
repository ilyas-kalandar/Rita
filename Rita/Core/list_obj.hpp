/**
 * @file list_obj.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief List-object definition.
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <vector>

#include "object.hpp"
#include "type.hpp"

#ifndef list_obj_hpp
#define list_obj_hpp

namespace Core
{
    /**
     * @brief Class-container for std::vector<RitaObject*> for using directly from Rita
     * 
     */
    class List : RitaObject
    {
    protected:
        std::vector<RitaObject*> vec;
    public:
        /**
         * @brief Construct a new List object
         * 
         * @param type Type of object
         */
        List(Type* type);
        
        /**
         * @brief Adds object to end of list
         * 
         * @param obj Object for adding
         */
        void Push(RitaObject* obj);

        /**
         * @brief Adds an object to begining of list
         * @param obj Object for adding
         */
        void PushFront(RitaObject* obj);

        /**
         * @brief Inserts an object before ``index``
         * 
         * @param index Index
         * @param obj Object for adding
         */
        void Insert(size_t index, RitaObject* obj);
        
        /**
         * @brief Removes last object of list
         * 
         */
        void Pop();

        /**
         * @brief Removes first object of list
         * 
         */
        void PopFront();
    };
}

#endif