/**
 * @file list_obj.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief List-object implementation.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "list_obj.hpp"

namespace Core
{
    List::List(Type* type) : RitaObject(type)
    {
    }

    RitaObject* List::Get(size_t index)
    {
        return vec[index];
    }

    void List::Insert(size_t index, RitaObject* obj)
    {
        this->vec.insert(vec.begin() + index, obj);
    }

    void List::Pop()
    {
        this->vec.pop_back();
    }

    void List::Push(RitaObject* obj)
    {
        this->vec.push_back(obj);
    }

    void List::PushFront(RitaObject* obj)
    {
        this->vec.insert(vec.begin(), obj);
    }
}