/**
* The following code declares class Algorithm,
* which is base class for the concrete pso variant.
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
#ifndef PSOPP_MINIMAXI_HPP
#define PSOPP_MINIMAXI_HPP

#include <limits>

namespace psopp
{
    template <class D, class P>
    class Minimize
    {
        bool operator() (const P* const a, const P* const b)
        {
            return a->position.fitness < b->position.fitness;
        }

        typename D::value_type InitialValue() const
        {
            return std::numeric_limits<D::value_type>().max();
        }
    };

    template <class D, class P>
    class Maximize
    {
        bool operator() (const P* const a, const P* const b)
        {
            return a->position.fitness > b->position.fitness;
        }

        typename D::value_type InitialValue() const
        {
            return std::numeric_limits<D::value_type>().min();
        }
    };

}

#endif // PSOPP_MINIMAXI_HPP
