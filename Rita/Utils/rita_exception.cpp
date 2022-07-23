/**
 * @file rita_exception.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief RitaException implementation.
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <sstream>

#include "rita_exception.hpp"

namespace Utils
{
    RitaException::RitaException(const char* stage, const std::string& error)
        :
        std::runtime_error(
                ((std::stringstream())
                << "Error ["
                << stage 
                << "] "
                << "Message: "
                << error
            ).str().c_str())
    {

    }
    RitaException::RitaException(const char* stage, const std::string& error, size_t line, size_t ch)
        :
        std::runtime_error(
                ((std::stringstream())
                << "Error at ["
                << stage 
                << "], "
                << "message: "
                << error
                << " at ("
                << line 
                << ", "
                << ch 
                << ")"
            ).str().c_str())
    {

    }

}