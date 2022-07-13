#include "list_obj.hpp"

List::List(Type* type)
{
    this->objectType = type;
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