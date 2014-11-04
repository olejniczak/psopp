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

#include "AlgorithmBase.hpp"

namespace psopp
{
    template <
        class Domain,
        class Topology,
        template <class> class Parameters,
        class Reader,
        template <class> class Type,
        template <class> class Initializer,
        template <class> class Evaluator,
        class RandomNumberGenerator
    >
    class Algorithm
        : public Type<AlgorithmBase<Domain, Topology, Initializer, Evaluator, Parameters<Reader>, RandomNumberGenerator>>
    {
        typedef typename AlgorithmBase<Domain, Topology, Initializer, Evaluator, Parameters<Reader>, RandomNumberGenerator>::particle_type particle_type;
    public:
        Algorithm()
            : Type<AlgorithmBase<Domain, Topology, Initializer, Evaluator, Parameters<Reader>, RandomNumberGenerator>>()
        {
            //for (auto particle : swarm) I::Initialize(particle); parameters_
            Read();
        }

        void ReadParams()
        {
            // TODO: read policy
        }

        int Start(int terminate_)
        {
            int step = 0;
            while (step++ < terminate_)
            {
                Step();
                if (std::fabs(swarm.worst().position.fitness - swarm.best().position.fitness) < 0.001) return step;
            }
            return step;
        }

        void Step()
        {
            for (size_t i = 0; i < swarm.size(); ++i)
                UpdateVelocity(swarm[i]);
            //swarm.check_velo();
            for (size_t i = 0; i < swarm.size(); ++i)
                UpdatePosition(swarm[i]);
            swarm.evaluate();
        }

        void UpdatePosition(particle_type& particle_)
        {
            particle_.position += particle_.velocity;
        }
    };
}
#endif // PSOPP_ALGORITHM_HPP