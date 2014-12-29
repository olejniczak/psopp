/**
* The following code defines ,
* which is
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
#ifndef PSOPP_INIT_HPP
#define PSOPP_INIT_HPP

#include "Random.hpp"

namespace psopp
{
    template <class TEvaluator, class TRandom>
    struct InitBase
    {
    protected:
        typedef typename TEvaluator::domain_type domain_type;
        typedef typename domain_type::position_type position_type;
        typedef typename domain_type::velocity_type velocity_type;
        typedef typename domain_type::value_type value_type;
    protected:
        value_type Min(size_t dim_) const { return evaluator.Min(dim_); }
        value_type Max(size_t dim_) const { return evaluator.Max(dim_); }
    protected:
        TRandom random;
    private:
        TEvaluator evaluator;
    };

    template <class TEvaluator, class TRandom>
    struct InitPosition : virtual InitBase<TEvaluator, TRandom>
    {};

    template <class TEvaluator, class TRandom>
    struct InitVelocity : virtual InitBase<TEvaluator, TRandom>
    {};

    template <class TEvaluator, class TRandom>
    struct NullPosition : InitPosition<TEvaluator, TRandom>
    {
        void InitPosition(typename InitPosition<TEvaluator, TRandom>::position_type& position_)
        {
            for (size_t i = 0; i < TEvaluator::domain_type::Size; ++i)
                position_.coordinates[i] = 0;
        }
    };

    template <class TEvaluator, class TRandom>
    struct NullVelocity : InitVelocity<TEvaluator, TRandom>
    {
        void InitVelocity(typename InitVelocity<TEvaluator, TRandom>::velocity_type& velocity_, const typename InitVelocity<TEvaluator, TRandom>::position_type& position_)
        {
            for (size_t i = 0; i < TEvaluator::domain_type::Size; ++i)
                velocity_.components[i] = 0;
        }
    };

    template <class TEvaluator, class TRandom>
    struct RandomPosition : InitPosition<TEvaluator, TRandom>
    {
        void InitPosition(typename InitPosition<TEvaluator, TRandom>::position_type& position_)
        {
            for (size_t i = 0; i < TEvaluator::domain_type::Size; ++i)
                position_.coordinates[i] = this->random.GetReal(this->Min(i), this->Max(i));
        }
    };

    template <class TEvaluator, class TRandom>
    struct RandomVelocity : InitVelocity<TEvaluator, TRandom>
    {
        void InitVelocity(typename InitVelocity<TEvaluator, TRandom>::velocity_type& velocity_, const typename InitVelocity<TEvaluator, TRandom>::position_type& position_)
        {
            for (size_t i = 0; i < TEvaluator::domain_type::Size; ++i)
                velocity_.components[i] = this->random.GetReal(this->Min(i), this->Max(i)) - position_.coordinates[i];
        }
    };

    template <
        class TEvaluator,
        class TRandom,
        template <class, class> class TInitPosition,
        template <class, class> class TInitVelocity
    >
    class Initializer
        : public TInitPosition<TEvaluator, TRandom>,
          public TInitVelocity<TEvaluator, TRandom>
    {

    };

    template <class TEvaluator, class TRandom> using StdInit = Initializer<TEvaluator, TRandom, RandomPosition, RandomVelocity>;
}

#endif // PSOPP_INIT_HPP
