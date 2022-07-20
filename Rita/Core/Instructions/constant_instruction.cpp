/**
 * @file constant_instruction.cpp
 * @author Ilyas Awaitable (t.me/awaitable)
 * @brief ConstantInstruction's implementation
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */

#include "instructions_types.hpp"
#include "constant_instruction.hpp"

namespace Core
{
    namespace Instructions
    {
        template<class T>
        ConstantInstruction<T>::ConstantInstruction(T& data) : data(std::move(data))
        {
            this->type = InstructionType::CONSTANT;
        }

        template<class T>
        T ConstantInstruction<T>::GetData()
        {
            return this->data;
        }

        template class ConstantInstruction<int>;
        template class ConstantInstruction<long double>;
    }
}