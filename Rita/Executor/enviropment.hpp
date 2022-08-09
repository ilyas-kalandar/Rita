#include <vector>
#include <string>
#include <memory>
#include <map>

#include "Instructions/instruction.hpp"
#include "enviropment_type.hpp"
#include "object.hpp"

#ifndef enviropment_hpp
#define enviropment_hpp

namespace Executor
{
    class Enviropment
    {
    protected:
        EnviropmentType type;
        std::map<std::string, Core::RitaObject*> storage;
        std::vector<std::shared_ptr<Core::Instructions::Instruction>>& instructions;
        size_t currentInstruction;
        Core::RitaObject* returnedValue = nullptr;
        bool running;

    public:
        /**
         * @brief Construct a new Enviropment object
         * 
         * @param instructions Instructions for enviropment.
         */
        Enviropment(std::vector<std::shared_ptr<Core::Instructions::Instruction>>& instructions, EnviropmentType type);

        /**
         * @brief Construct a new Enviropment object
         * 
         * @param type 
         */
        Enviropment(EnviropmentType type);
        
        /**
         * @brief Get Variable (throws exception if storage don't contain variable)
         * @param varName A variable's name.
         * 
         * @return Core::RitaObject* 
         */
        Core::RitaObject* GetVar(const std::string& varName);

        /**
         * @brief Saves a variable to storage
         * 
         * @param varName A variable's name
         * @param obj An object for storing.
         */
        void SetVar(const std::string& varName, Core::RitaObject* obj);
        
        /**
         * @brief Checks variable for existing
         * 
         * @param str A variable's name.
         * @return true If variable exist
         * @return false If variable doesen't exist.
         */
        bool CheckVar(const std::string& varName);

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool IsRunning();
        
        /**
         * @brief Set the Running object
         * 
         */
        void SetRunning(bool running);
        
        /**
         * @brief Get the Current Instruction
         * 
         * @return std::shared_ptr<Core::Instructions::Instruction> 
         */
        std::shared_ptr<Core::Instructions::Instruction> GetCurrentInstruction();

        /**
         * @brief Set the Returned Value object
         * 
         * @param returnedValue 
         */
        void SetReturnedValue(Core::RitaObject* returnedValue);

        /**
         * @brief Get the Returned Value object
         * 
         * @return Core::RitaObject* 
         */
        Core::RitaObject* GetReturnedValue();

        /**
         * @brief Get the EnviropmentType object
         * 
         * @return EnviropmentType 
         */
        EnviropmentType GetEnvType();

        void operator=(const Enviropment& other);
    };
}


#endif