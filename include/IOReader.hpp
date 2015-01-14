/**
 *
 * See http://przole.github.io/psopp for documentation.
 *
 * @author Copyright &copy 2011 Przemys³aw Olejniczak.
 * @version 0.2.0
 * @date 2014.12.29
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 */
#ifndef PSOPP_IOREADER_HPP
#define PSOPP_IOREADER_HPP

#include <iostream>

namespace psopp
{
    class IOReader
    {
    public:
        template <class T>
        T get(const char* name_) const
        {
            std::cout << name_ << " <- ";
            T value;
            std::cin >> value;
            return value;
        }
    };
}

#endif //PSOPP_IOREADER_HPP