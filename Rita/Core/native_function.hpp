/**
 * @file native_function.hpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief NativeFunction definition.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include <functional>

#include "object.hpp"
#include "type.hpp"

#ifndef native_function_hpp
#define native_function_hpp

namespace Core
{
    /**
     * @brief NativeFunction stores a (C++) function for calling directly from Rita.
     * 
     */
    class NativeFunction : public RitaObject
    {
    protected:
        std::function<RitaObject* (const std::vector<RitaObject*>&)> nativeCallback;
    public:
        /**
         * @brief Construct a new NativeFunction object
         * 
         * @param f C++ function.
         * @param type Type of object.
         */
        NativeFunction(std::function<RitaObject*(const std::vector<RitaObject*>&)> f, Type* type);

        /**
         * @brief Start the function executing.
         *
         * @return RitaObject* object-result.
         */
        RitaObject* Execute(const std::vector<RitaObject*>& arg);
    };
}

#endif
