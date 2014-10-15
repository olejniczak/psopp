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

#include <array>

namespace psopp
{
    template <
        class Domain,
        int Size,
        template <class> class Comparator,
        template <class,  class> class Evaluator
    >
    class Swarm
    {
        class Particle
        {
        public:
            typename Domain::position_type position;
            typename Domain::velocity_type velocity;
            typename Domain::position_type best_position;
        };
        typedef std::array<Particle, Size> array_type;
    public:
        typedef Particle particle_type;
    public:
        size_t size() const { return Size; }
        const Particle& front() const { return swarm.front(); }
        const Particle& back() const { return swarm.back(); }
        const Particle& best() const { sort(); return front(); }
        const Particle& worst() const { sort(); return back(); }

        typename array_type::iterator begin() { return swarm.begin(); }
        typename array_type::iterator end() { return swarm.end(); }
        void sort()
        {
            std::sort(swarm.begin(), swarm.end(), C<D>());
        }
        void evaluate()
        {
            for (auto p : swarm) evaluator(p);
        }
    private:
        array_type swarm;
        Evaluator<Domain, Particle> evaluator;
    };
}

#endif // PSOPP_SWARM_HPP