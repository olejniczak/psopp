/**
* The following code declares class Swarm,
* which is a collection of particles
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemysław Olejniczak.
* @version 0.2.0
* @date <DATE>
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_SWARM_HPP
#define PSOPP_SWARM_HPP

#include <memory>
#include <algorithm>

#include "SwarmStructure.hpp"
//#include "MiniMaxi.hpp"

namespace psopp
{
    template <
		size_t Size,
		class Domain,
        class Topo//,
        //class Pred = Minimize<Domain, typename SwarmStructure<Domain, Topo>::particle_type>
    >
	class Swarm : public SwarmStructure<Domain, Topo>
    {
        typedef SwarmStructure<Domain, Topo> Structure;
    public:
        typedef Domain domain_type;
        typedef typename Structure::particle_type particle_type;
        typedef typename Structure::Neighborhood neighborhood_type;
        typedef typename std::unique_ptr<particle_type> particle_ptr_type;
        typedef typename std::array<particle_ptr_type, Size> container_type;

        static bool Minimize(const particle_ptr_type& a, const particle_ptr_type& b)
        {
            return a->position.fitness < b->position.fitness;
        }
    public:
        explicit Swarm()
			: Structure(Size), scored(false)
        {
			for (size_t i = 0; i < Size; ++i)
				swarm[i] = particle_ptr_type(new particle_type());

            for (size_t i = 0; i < this->neighborhoods.Count(); ++i)
            {
                this->nhoods.push_back(std::unique_ptr<neighborhood_type>(new neighborhood_type()));
                auto nh = this->neighborhoods[i];
                for (size_t j = 0; j < nh.Count(); ++j)
                {
                    auto id = nh[j];
                    this->nhoods.back()->Add(*swarm[id]);
                }
            }
        }
        size_t size() const { return swarm.size(); }
        const particle_type& front() const { return *swarm.front(); }
        const particle_type& back() const { return *swarm.back(); }
        const particle_type& best() { minmax(); return front(); }
        const particle_type& worst() { minmax(); return back(); }
        const particle_type& best() const { return front(); }
        const particle_type& worst() const {  return back(); }
        typename container_type::iterator begin() { return swarm.begin(); } // ?
        typename container_type::iterator end() { return swarm.end(); } // ?

        const particle_type& operator[] (size_t index_) const
        {
            return *swarm[index_];
        }

        particle_type& operator[] (size_t index_)
        {
            return *swarm[index_];
        }

        void minmax()
        {
            if (scored) return;
            scored = true;
            auto minmax = std::minmax_element(swarm.begin(), swarm.end(), Minimize);
            std::iter_swap(swarm.begin(), minmax.first);
            std::iter_swap(--swarm.end(), minmax.second);
        }
        bool scored;
    private:
        container_type swarm;
        //Pred predicate;
    };
}

#endif // PSOPP_SWARM_HPP
