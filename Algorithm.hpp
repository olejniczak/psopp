/**
* The following code declares class Algorithm,
* which is base class for the concrete pso variant.
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
#ifndef PSOPP_ALGORITHM_HPP
#define PSOPP_ALGORITHM_HPP

#include "Swarm.hpp"

namespace psopp
{
    template <
        class Domain,
        template <class> class P,
        template <class, class> class Variant,
        int Size,
        template <class> class ComparatorType,
        template <class, class> class EvaluatorType
    >
    class algorithm : public Variant<Domain, typename Swarm<Domain, Size, ComparatorType, EvaluatorType>::particle_type>
    {
        typedef Swarm<Domain, Size, ComparatorType, EvaluatorType> swarm_type;
    public:
        algorithm()
        {
            //for (auto particle : swarm) I::Initialize(particle);
        }
        void Step()
        {
            for (auto p : swarm) UpdateVelocity(p);
        }
    private:
        swarm_type swarm;
        //typename  variant;
    };
}
#endif // PSOPP_ALGORITHM_HPP