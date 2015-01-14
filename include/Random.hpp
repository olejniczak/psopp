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
#ifndef PSOPP_RANDOM_HPP
#define PSOPP_RANDOM_HPP

#include <chrono>
#include <random>

namespace psopp
{
    template
    <
        class TIntType = int,
        class TRealType = double,
        class TEngine = std::default_random_engine,
        template <class> class TIntDistribution = std::uniform_int_distribution,
        template <class> class TRealDistribution = std::uniform_real_distribution
    >
    class Random
    {
    public:
        //typedef typename TEngine::result_type seed_type;
    public:
        Random(TRealType min_ = {}, TRealType max_ = {})
            : engine(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count())),
              int_distribution(static_cast<TIntType>(min_), static_cast<TIntType>(max_)), 
              real_distribution(min_, max_)
        {}

        TIntType GetInt(TIntType min_, TIntType max_)
        {
            return int_distribution(engine, typename TIntDistribution<TIntType>::param_type(min_, max_));
        }

        TRealType GetReal(TRealType min_, TRealType max_)
        {
            return real_distribution(engine, typename TRealDistribution<TRealType>::param_type(min_, max_));
        }

        TIntType GetInt()
        {
            return int_distribution(engine);
        }

        TRealType GetReal()
        {
            return real_distribution(engine);
        }

        TEngine engine;
        TIntDistribution<TIntType> int_distribution;
        TRealDistribution<TRealType> real_distribution;
    };
}

#endif //PSOPP_RANDOM_HPP
