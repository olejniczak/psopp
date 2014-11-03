/**
* The following code declares class Variant,
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
#ifndef PSOPP_VARIANT_HPP
#define PSOPP_VARIANT_HPP

#include "Swarm.hpp"
#include "SwarmStructure.hpp"

namespace psopp
{
    template<
        class Domain,
        class Topology,
        template <class> class Initializer,
        template <class> class Evaluator,
        class Parameters,
        class RandomNumberGenerator
    >
    class AlgorithmBase
        : public Parameters
    {
        class Particle
        {
        public:
            typename Domain::position_type position;
            typename Domain::velocity_type velocity;
            //typename Domain::value_type    fitness;
            typename Domain::position_type best_position;
            //typename Domain::position_type best_fitness;
        };
    public:
        AlgorithmBase()
            : swarm(20) {}
    protected:
        typedef Particle particle_type;
        Swarm<Domain, SwarmStructure<Topology, Particle>, Initializer, Evaluator> swarm;
        RandomNumberGenerator random;
    };
} 

#endif // PSOPP_VARIANT_HPP
