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

namespace psopp
{
    template<
        class Domain,
        class ParticleType
    >
    class canonical_pso
    {
    public:
        void UpdateVelocity(ParticleType& particle_)
        {

            //particle_.velocity *= inertia_weight;

        }
    //public:
    //    typedef typename D domain;
    };
}

#endif // PSOPP_CANONICALPSO_HPP