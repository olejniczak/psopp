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
        class Topo,
        class Particle
    >
    class SwarmStructure : public Topo
    {
    public:
        typedef Particle particle_type;

        class Neighborhood
        {
        public:
            void Add(const particle_type& particle_)
            {
                elements.push_back(&particle_);
            }

            const particle_type& best() const
            {
                return std::min_element(elements.begin(), elements.end(), Comparator<Domain>());
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
        std::vector<std::unique_ptr<Neighborhood>> nhoods;
    };
}

#endif // PSOPP_SWARMSTRUCTURE_HPP