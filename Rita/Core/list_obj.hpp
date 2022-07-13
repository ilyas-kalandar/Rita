/**
 * @file list_obj.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "object.hpp"
#include "type.hpp"

#ifndef list_obj_hpp
#define list_obj_hpp

class List : RitaObject
{
protected:
    std::vector<RitaObject*> vec;
public:
    List(Type* type);
    
    void Push(RitaObject*);
    void PushFront(RitaObject*);
    void Insert(size_t index, RitaObject*);
    void Pop();
    void PopFront();
};

#endif