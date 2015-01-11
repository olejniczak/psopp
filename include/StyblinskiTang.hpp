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
#ifndef PSOPP_STYBLINSKITANG_HPP
#define PSOPP_STYBLINSKITANG_HPP

#include "Problem.hpp"

namespace psopp
{
    template<
        class Domain
    >
    class StyblinskiTang : public Problem<Domain>
    {
    public:
        void operator()(typename Domain::position_type& position_) const
        {
            position_.fitness = {};
            for (size_t i = 0; i < Domain::Size - 1; ++i)
            {
                auto xi = position_.coordinates[i];
                position_.fitness += xi *xi *xi *xi - 16 * xi *xi + 5 * xi;
            }
            position_.fitness /= 2.0;
        }

        typename Domain::value_type Min(size_t dim_) const
        {
            return -5;
        }

        typename Domain::value_type Max(size_t dim_) const
        {
            return 5;
        }
    };
}

#endif // PSOPP_STYBLINSKITANG_HPP
