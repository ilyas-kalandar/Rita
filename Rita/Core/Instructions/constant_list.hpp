/**
 * @file constant_list.hpp
 * @author your name (you@domain.com)
 * @brief ConstantList definition.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright Awaitable (c) 2022
 * 
 */


#include <vector>
#include <memory>

#include "instruction.hpp"

#ifndef constant_list_hpp
#define constant_list_hpp

namespace Core
{
    namespace Instructions
    {
        /**
         * @brief Class for storing list into instruction
         * 
         * For example:
         *  a = [1, 2, 3] <= this will be stored here 
         * 
         */
        class ConstantList : Instruction
        {
        protected:
            std::vector<std::shared_ptr<Instruction>> list;
        public:
            /**
             * @brief Construct a new Constant List object
             * 
             * @param list 
             */
            ConstantList(const std::vector<std::shared_ptr<Instruction>>& list);

            /**
             * @brief Get the List object
             * 
             * @return const std::vector<std::shared_ptr<Instruction>>& 
             */
            const std::vector<std::shared_ptr<Instruction>>& GetList();
        };
    }
}

#endif