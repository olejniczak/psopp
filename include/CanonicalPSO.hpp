/**
* The following code declares class Algorithm,
* which is base class for the concrete pso variant.
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemys�aw Olejniczak.
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

namespace psopp
{
    template<class Base>
    class CanonicalPSO : public Base
    {
    public:
        void UpdateVelocity(typename Base::particle_type& particle_)
        {
            auto local_diff = particle_.best_position - particle_.position;
            auto global_diff = particle_.gbest_position() - particle_.position;

            local_diff *= this->particle_learn;
            local_diff *= this->random.GetReal(0, 1);

            global_diff *= this->swarm_learn;
            global_diff *= this->random.GetReal(0, 1);

            particle_.velocity *= this->inertia_weight;
            particle_.velocity += local_diff;
            particle_.velocity += global_diff;
        }
    };
}

#endif // PSOPP_CANONICALPSO_HPP
