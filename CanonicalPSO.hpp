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
#ifndef PSOPP_CANONICALPSO_HPP
#define PSOPP_CANONICALPSO_HPP

#include <string>
#include "AlgorithmType.hpp"

namespace psopp
{
    template<
        class Domain,
        class Topology,
        class Parameters,
        template <class> class Comparator,
        template <class, class> class Evaluator
    >
    class CanonicalPSO
        : public AlgorithmType<Domain, Topology, Comparator, Evaluator>,
          public Parameters
    {
    public:
        CanonicalPSO(const std::string& parameters_)
            : /*AlgorithmType<Domain, Topology, Comparator, Evaluator>(parameters_), */Parameters(parameters_)
        {}
        void UpdateVelocity(particle_type& particle_)
        {
            auto local_diff = particle_.best_position - particle_.position;
            auto global_diff = swarm.best().position - particle_.position;

            local_diff *= particle_learn;
            local_diff *= 0.33;

            global_diff *= swarm_learn;
            global_diff *= 0.66;

            particle_.velocity *= inertia_weight;
            particle_.velocity += local_diff;
            particle_.velocity += global_diff;

            particle_.position += particle_.velocity;
        }
    };
}

#endif // PSOPP_CANONICALPSO_HPP