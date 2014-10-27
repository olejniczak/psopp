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

#include <string>

#include "AlgorithmType.hpp"

namespace psopp
{
    template <
        class Domain,
        class Topology,
        template <class> class Parameters,
        class Reader,
        template <class, class> class Type,
        template <class> class Comparator,
        template <class, class> class Evaluator
    >
    class Algorithm
        : public Type<AlgorithmType<Domain, Topology, Comparator, Evaluator>, Parameters<Reader>>
    {
    public:
        Algorithm(const std::string& parameters_)
            : Type<AlgorithmType<Domain, Topology, Comparator, Evaluator>, Parameters<Reader>>(parameters_)
        {
            //for (auto particle : swarm) I::Initialize(particle);
            Read();
        }
        void Step()
        {
            for (size_t i = 0; i < swarm.size(); ++i) 
                UpdateVelocity(swarm[i]);
        }
    };
}
#endif // PSOPP_ALGORITHM_HPP