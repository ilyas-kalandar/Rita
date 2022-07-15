/**
 * @file engine.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <list>
#include <vector>
#include <map>
#include <deque>

#include "object.hpp"
#include "Builtins/functions.hpp"
#include "Instructions/instruction.hpp"

class Engine
{
protected:
    std::list<Core::RitaObject*> objects;
    std::vector<std::map<std::string, Core::RitaObject*>> nameSpace;
    size_t currentNamespaceIndex;
public:
    Engine();
    Core::RitaObject* LookupName(std::string& name);
    void Initialize();
    void CollectGarbage();
};