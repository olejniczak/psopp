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
        class Structure,
        class Initializer,
        class Evaluator
    >
    class Swarm 
        : public Structure
    {
    public:
        typedef typename Structure::particle_type particle_type;
        typedef typename std::unique_ptr<particle_type> particle_ptr_type;
        typedef typename std::vector<particle_ptr_type> container_type;

        static bool Minimize(const particle_ptr_type& a, const particle_ptr_type& b)
        {
            return a->position.fitness < b->position.fitness;
        }
    public:
        explicit Swarm(size_t size_)
            : Structure(size_), scored(false)
        {
            for (size_t i = 0; i < size_; ++i)
                swarm.push_back(std::unique_ptr<particle_type>(new particle_type()));            
            
            initialize();

            for (size_t i = 0; i < neighborhoods.Count(); ++i)
            {
                nhoods.push_back(std::unique_ptr<Neighborhood>(new Neighborhood()));
                auto nh = neighborhoods[i];
                for (size_t j = 0; j < nh.Count(); ++j)
                {
                    auto id = nh[j];
                    nhoods.back()->Add(*swarm[id]);
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

        void evaluate()
        {
            for (auto& p : swarm)
            {
                evaluator(p->position);
                //p->best_position = std::min(p->position, p->best_position, Minimize);
                if (p->position.fitness < p->best_position.fitness)
                {
                    p->best_position = p->position;
                }
            }
            scored = false;
            minmax();
        }

    private:
        void initialize()
        {
            for (auto& p : swarm)
            {
                initializer.InitPosition(p->position);
                p->best_position = p->position;
                evaluator(p->best_position);
                initializer.InitVelocity(p->velocity, p->position);
            }
            evaluate();
        }

        void minmax()
        {
            if (scored) return;
            scored = true;
            auto minmax = std::minmax_element(swarm.begin(), swarm.end(), Minimize);
            std::iter_swap(swarm.begin(), minmax.first);
            std::iter_swap(--swarm.end(), minmax.second);
        }
    private:
        Initializer initializer;
        Evaluator evaluator;

        bool scored;
        container_type swarm;
    };
}

#endif // PSOPP_SWARM_HPP