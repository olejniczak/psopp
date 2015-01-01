/**
* The following code declares class Variant,
* which is base class for the concrete pso variant.
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version 0.2.0
* @date <DATE>
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_SPHERE_HPP
#define PSOPP_SPHERE_HPP

#include "Problem.hpp"

namespace psopp
{
    template<
        class TDomain
    >
    class Sphere : public Problem<Domain>
    {
    public:
        void operator()(typename Domain::position_type& position_) const
        {
            position_.fitness = {};
            for (size_t i = 0; i < Domain::Size - 1; ++i)
            {
                position_.fitness += position_.coordinates[i] * 
                                     position_.coordinates[i];
            }
        }

        typename Domain::value_type Min(size_t dim_) const
        {
            return -5.12;
        }

        typename Domain::value_type Max(size_t dim_) const
        {
            return 5.12;
        }
    };
}

#endif // PSOPP_SPHERE_HPP
