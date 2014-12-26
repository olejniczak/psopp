/**
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
#ifndef PSOPP_RANDOM_HPP
#define PSOPP_RANDOM_HPP

#include <random>

namespace psopp
{
    template
    <
        class IntType = int,
        class RealType = double,
        class Engine = std::default_random_engine,
        template <class> class IntDistribution = std::uniform_int_distribution,
        template <class> class RealDistribution = std::uniform_real_distribution
    >
    class Random
    {
    public:
        Random(RealType min_ = {}, RealType max_ = {})
            : e(2354), id(static_cast<IntType>(min_), static_cast<IntType>(max_)), rd(min_, max_)
        {}

        IntType GetInt(IntType min_, IntType max_)
        {
            return id(e, typename IntDistribution<IntType>::param_type(min_, max_));
        }

        RealType GetReal(RealType min_, RealType max_)
        {
            return rd(e, typename RealDistribution<RealType>::param_type(min_, max_));
        }

        IntType GetInt()
        {
            return id(e);
        }

        RealType GetReal()
        {
            return rd(e);
        }

        Engine e;
        IntDistribution<IntType> id;
        RealDistribution<RealType> rd;
    };
}

#endif //PSOPP_RANDOM_HPP
