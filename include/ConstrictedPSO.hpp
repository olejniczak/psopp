/**
* The following code declares class Algorithm,
* which is base class for the concrete pso variant.
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
#ifndef PSOPP_CONSTRICTEDPSO_HPP
#define PSOPP_CONSTRICTEDPSO_HPP

#include "BaseParameters.hpp"
#include "MapReader.hpp"

namespace psopp
{
    template<class Base>
    class ConstrictedPSO : public Base, public BaseParameters<MapReader>
    {
    public:
        void UpdateVelocity(typename Base::particle_type& particle_)
        {
            auto local_diff = particle_.best_position - particle_.position;
            auto global_diff = particle_.gbest_position() - particle_.position;

            //local_diff *= this->particle_learn;
            local_diff *= this->random.GetReal(0, 2.05);

            //global_diff *= this->swarm_learn;
            global_diff *= this->random.GetReal(0, 2.05);

            particle_.velocity += local_diff;
            particle_.velocity += global_diff;

            particle_.velocity *= 0.7289;
        }
    };
}

#endif // PSOPP_CONSTRICTEDPSO_HPP
