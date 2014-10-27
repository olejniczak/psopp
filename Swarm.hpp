/**
* The following code declares class Swarm,
* which is a collection of particles
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
#ifndef PSOPP_SWARM_HPP
#define PSOPP_SWARM_HPP

#include <vector>
#include <memory>

namespace psopp
{
    template <
        class Domain,
        class Structure,
        template <class> class Comparator,
        template <class, class> class Evaluator
    >
    class Swarm : public Structure
    {
        //typedef typename Structure::container_type container_type;
    public:
        typedef typename Structure::particle_type particle_type;
        typedef typename std::vector<std::unique_ptr<particle_type>> container_type;
    public:
        explicit Swarm(size_t size_)
            : Structure(size_)
        {
            for (size_t i = 0; i < size_; ++i)
                swarm.push_back(std::unique_ptr<particle_type>(new particle_type()));            
            
            for (size_t i = 0; i < size(); ++i)
            {
                nhoods.push_back(std::unique_ptr<Neighborhood>(new Neighborhood()));
                for (size_t j = 0; j < neighborhoods[i].Count(); ++j)
                    nhoods.back()->Add(*swarm[j]);
            }
        }
        size_t size() const { return swarm.size(); }
        const particle_type& front() const { return *swarm.front(); }
        const particle_type& back() const { return *swarm.back(); }
        const particle_type& best(size_t i) const { sort(); return front(); }
        const particle_type& worst() const { sort(); return back(); }
        const particle_type& best() { return front(); }
        const particle_type& worst() { return back(); }

        typename container_type::iterator begin() { return swarm.begin(); }
        typename container_type::iterator end() { return swarm.end(); }

        const particle_type& operator[] (size_t index_) const
        {
            return *swarm[index_];
        }

        particle_type& operator[] (size_t index_)
        {
            return *swarm[index_];
        }

        void sort()
        {
            std::sort(swarm.begin(), swarm.end(), Comparator<Domain>());
        }

        void evaluate()
        {
            for (auto p : swarm) evaluator(p);
        }
    private:
        container_type swarm;
        Evaluator<Domain, particle_type> evaluator;
    };
}

#endif // PSOPP_SWARM_HPP