/**
* The following code declares class Variant,
* which is base class for the concrete pso variant.
*
* See http://przole.github.io/psopp for documentation.
*
* @author Copyright &copy 2011 Przemysław Olejniczak.
* @version 0.2.0
* @date 2014.12.29
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_SIMPLETSP_HPP
#define PSOPP_SIMPLETSP_HPP

#include "Problem.hpp"

namespace psopp
{
    template<
        class TDomain
    >
    class NovelTSP : public Problem<TDomain>
    {
    public:
        void operator()(typename TDomain::position_type& position_) const
        {
            position_.fitness = {};

        }

        value_type Min(std::size_t dim_) const {}
        value_type Max(std::size_t dim_) const {}
    };
}

#endif // PSOPP_ROSENBROCK_HPP
