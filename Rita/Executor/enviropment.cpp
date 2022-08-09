/**
 * @file enviropment.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief Enviropment implementation.
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright Awaitable (Ilyas Qalandarzoda) (c) 2022
 * 
 */

#include <sstream>

#include "rita_exception.hpp"
#include "enviropment.hpp"

namespace Executor
{
    std::vector<std::shared_ptr<Core::Instructions::Instruction>> emptyInstrList;
     
    Enviropment::Enviropment(EnviropmentType type) : instructions(emptyInstrList)
    {
        this->type = type;
    }

    Enviropment::Enviropment(std::vector<std::shared_ptr<Core::Instructions::Instruction>>& instructions, EnviropmentType type)
        : instructions(instructions)
    {
        running = true;
        this->type = type;
        currentInstruction = 0;
    }

    bool Enviropment::CheckVar(const std::string& varName)
    {
        return storage.find(varName) != storage.end();
    }

    Core::RitaObject* Enviropment::GetVar(const std::string& varName)
    {
        if(!CheckVar(varName))
        {
            throw Utils::RitaException(
                "Executor::Enviropment::GetVar", 
                (std::stringstream() << "Variable \"" << varName << "\" does not exist!").str()
            );
        }

        return storage[varName];
    }

    void Enviropment::SetVar(const std::string& varName, Core::RitaObject* obj)
    {
        storage[varName] = obj;
    }

    void Enviropment::SetRunning(bool running)
    {
        this->running = running;
    }

    bool Enviropment::IsRunning()
    {
        return running && currentInstruction < instructions.size();
    }

    std::shared_ptr<Core::Instructions::Instruction> Enviropment::GetCurrentInstruction()
    {
        return instructions[currentInstruction++];
    }
    
    void Enviropment::SetReturnedValue(Core::RitaObject* val)
    {
        returnedValue = val;
    }

    Core::RitaObject* Enviropment::GetReturnedValue()
    {
        return returnedValue;
    }

    EnviropmentType Enviropment::GetEnvType()
    {
        return type;
    }

    void Enviropment::operator=(const Enviropment& other)
    {
        this->currentInstruction = other.currentInstruction;
        this->instructions = other.instructions;
        this->returnedValue = other.returnedValue;
        this->running = other.running;
        this->storage = other.storage;
        this->type = other.type;
    }
}