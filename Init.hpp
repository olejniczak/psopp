/**
* The following code defines ,
* which is
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version <VERSION>
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
    template <class P>
    struct InitBase
    {
    protected:
        typedef typename P::domain_type domain_type;
        typedef typename domain_type::position_type position_type;
        typedef typename domain_type::velocity_type velocity_type;
        typedef typename domain_type::value_type value_type;
    protected:
        value_type Min(size_t dim_) const { return problem.Min(dim_); }
        value_type Max(size_t dim_) const { return problem.Max(dim_); }
        Random<> random;
    private:
        P problem;
    };

    template <class P>
    struct InitPosition : virtual InitBase<P>
    {};

    template <class P>
    struct InitVelocity : virtual InitBase<P>
    {};

    template <class P>
    struct NullPosition : InitPosition<P>
    {
        void InitPosition(position_type& position_)
        {
            for (size_t i = 0; i < P::domain_type::Size; ++i)
                position_.coordinates[i] = 0;
        }
    };

    template <class P>
    struct NullVelocity : InitVelocity<P>
    {
        void InitVelocity(velocity_type& velocity_, const position_type& position_)
        {
            for (size_t i = 0; i < P::domain_type::Size; ++i)
                velocity_.components[i] = 0;
        }
    };

    template <class P>
    struct RandomPosition : InitPosition<P>
    {
        void InitPosition(position_type& position_)
        {
            for (size_t i = 0; i < P::domain_type::Size; ++i)
                position_.coordinates[i] = random.GetReal(Min(i), Max(i));
        }
    };

    template <class P>
    struct RandomVelocity : InitVelocity<P>
    {
        void InitVelocity(velocity_type& velocity_, const position_type& position_)
        {
            for (size_t i = 0; i < P::domain_type::Size; ++i)
                velocity_.components[i] = random.GetReal(Min(i), Max(i)) - position_.coordinates[i];
        }
    };

    template <
        class Problem,
        template <class> class PInit,
        template <class> class VInit
    >
    class Initializer
        : public PInit<Problem>,
          public VInit<Problem>
    {
    };

    template <class P> using StdInit = Initializer<P, RandomPosition, RandomVelocity>;
}

#endif // PSOPP_INIT_HPP