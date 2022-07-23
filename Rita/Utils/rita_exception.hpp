/**
 * @file rita_exception.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief RitaException definition.
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <stdexcept>

#ifndef exception_hpp
#define exception_hpp

namespace Utils
{
    /**
     * @brief Class for project's exceptions.
     * 
     */
    class RitaException : public std::runtime_error
    {
    public:
        RitaException(const char* stage, const std::string& error);
        RitaException(const char* stage, const std::string& error, size_t line, size_t ch);
    };
}

#endif