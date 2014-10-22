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
#ifndef PSOPP_SWARMPOLICY_HPP
#define PSOPP_SWARMPOLICY_HPP

#include <memory>
#include <vector>

namespace psopp
{
    template <
        class Topology,
        class Particle
    >
    class SwarmPolicy
    {
    public:
        typedef Particle particle_type;
        typedef typename Topology::template particle_pointer<typename Particle> particle_pointer_type;
        typedef typename Topology::template container_type<typename SwarmPolicy::particle_pointer_type> container_type;
        //typedef typename std::unique_ptr<typename Particle> particle_pointer_type;
        //typedef typename std::vector<typename SwarmPolicy::particle_pointer_type> container_type;
    };
}

#endif // PSOPP_SWARMPOLICY_HPP