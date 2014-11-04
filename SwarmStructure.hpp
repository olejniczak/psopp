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
#ifndef PSOPP_SWARMSTRUCTURE_HPP
#define PSOPP_SWARMSTRUCTURE_HPP

#include <algorithm>
#include <memory>
#include <vector>

namespace psopp
{
    template <
        class Domain,
        class Topo
    >
    class SwarmStructure : public Topo
    {
    protected:
        class Neighborhood;
        class Particle
        {
            friend class Neighborhood;
        public:
            typename Domain::position_type position;
            typename Domain::velocity_type velocity;
            typename Domain::position_type best_position;
            typename const Domain::position_type& gbest_position() const;
        private:
            Neighborhood* neighborhood;
        };
    public:
        typedef Particle particle_type;

        class Neighborhood
        {
            static bool Minimize(const particle_type* const a, const particle_type* const b)
            {
                return a->position.fitness < b->position.fitness;
            }
        public:
            void Add(particle_type& particle_)
            {
                elements.push_back(&particle_);
                particle_.neighborhood = this;
            }

            const particle_type& best() const
            {
                auto blah = *std::min_element(elements.begin(), elements.end(), Minimize);
                return *blah;
            }
        private:
            std::vector<const particle_type* const> elements;
        };
    public:
        SwarmStructure(size_t size_)
            : Topo(size_)
        {
        }
    protected:
        std::vector<std::unique_ptr<Neighborhood>> nhoods;
    };

    template<class Domain, class Topo> typename const Domain::position_type& SwarmStructure<Domain, Topo>::Particle::gbest_position() const
    {
        return neighborhood->best().position;
    }
}

#endif // PSOPP_SWARMSTRUCTURE_HPP