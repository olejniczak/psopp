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
#include <iostream>
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
    public:
        class Neighborhood;
    protected:
        class Particle
        {
            friend class Neighborhood;
        public:
            typename Domain::position_type position;
            typename Domain::velocity_type velocity;
            typename Domain::position_type best_position;
            const typename Domain::position_type& gbest_position() const;
        private:
            Neighborhood* neighborhood {};
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
            Neighborhood()
            {
                best.position.fitness = 1e100;
            }

            void Add(particle_type& particle_)
            {
                if (!particle_.neighborhood) particle_.neighborhood = this;
                elements.push_back(&particle_);                
            }

            void update_best()
            {
                const particle_type* const m = *std::min_element(elements.begin(), elements.end(), Minimize);
                const particle_type* const b = &best;
                best = *std::min(m, b, Minimize);

                //std::cout << best.position.fitness << std::endl;
            }
            particle_type best;

            void minmax()
            {
                auto minmax = std::minmax_element(elements.begin(), elements.end(), Minimize);
                std::iter_swap(swarm.begin(), minmax.first);
                std::iter_swap(--swarm.end(), minmax.second);
            }
        private:
            std::vector<const particle_type*> elements;
        };
    public:
        SwarmStructure(size_t size_)
            : Topo(size_)
        {
        }
    protected:
        void update_neighborhoods()
        {
            for (auto& n : nhoods)
            {
                n->update_best();
            }
        }
        std::vector<std::unique_ptr<Neighborhood>> nhoods;
    };

    template<class Domain, class Topo> const typename Domain::position_type& SwarmStructure<Domain, Topo>::Particle::gbest_position() const
    {
        return neighborhood->best.position;
    }
}

#endif // PSOPP_SWARMSTRUCTURE_HPP
