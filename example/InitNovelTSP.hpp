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
#ifndef PSOPP_INITTSP_HPP
#define PSOPP_INITTSP_HPP

#include "Random.hpp"

namespace psopp
{
    template <class TEvaluator, class TRandom>
    struct InitNovelTSP
    {
    protected:
        typedef typename TEvaluator::domain_type domain_type;
        typedef typename domain_type::position_type position_type;
        typedef typename domain_type::velocity_type velocity_type;
        typedef typename domain_type::value_type value_type;
    public:
        void InitVelocity(velocity_type& velocity_, const position_type& position_)
        {
            //velocity_.
        }

        void InitPosition(position_type& position_)
        {

        }
    protected:
        TRandom random;
    private:
        TEvaluator evaluator;
    };
    // template <class TEvaluator, class TRandom> using StdInit = Initializer<TEvaluator, TRandom, RandomPosition, RandomVelocity>;
}

#endif // PSOPP_INITTSP_HPP
