/**
 * @file object.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
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
    std::variant<int, double, std::string, bool> data;
    size_t referenceCounter = 0;
    Type type = RITA_NONE;
    std::map<std::string, RitaObject> fields;
    std::vector<RitaObject> arr;
public:
    RitaObject();
    RitaObject(bool data);
    RitaObject(int data);
    RitaObject(double data);
    RitaObject(const std::string& data);
    RitaObject(const std::vector<RitaObject> vec);
    RitaObject(const std::map<std::string, RitaObject>& flds);
    void PushBack(RitaObject& obj);
    RitaObject* Plus(RitaObject& another);
    RitaObject* Minus(RitaObject& another);
    RitaObject* Multiply(RitaObject& another);
    RitaObject* Divide(RitaObject& another);
    RitaObject* Greater(RitaObject& another);
    // RitaObject* Smaller(RitaObject& another);
    // RitaObject* GreaterOrEqual(RitaObject& another);
    // RitaObject* SmallerOrEqual(RitaObject& another);
    // RitaObject* Equals(RitaObject& another);
    std::string ToString();
};

#endif