/**
 * The following code defines class Topology, and some derived classes
 * which represents topologies of the neighborhood of the particles in swarm
 *
 * See <WEBSITE> for documentation.
 *
 * @author Copyright &copy 2014 Przemys³aw Olejniczak.
 * @version <VERSION>
 * @date <DATE>
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 */
#ifndef PSOPP_TOPOLOGY_HPP
#define PSOPP_TOPOLOGY_HPP

#include <vector>

namespace psopp
{
    class Topology
    {
        struct Neighborhoods
        {
            struct Neighborhood
            {
                const size_t Count() const;
                void Add(size_t index_);
                void Set(size_t index_);
                size_t operator[] (size_t index_) const;
            private:
                std::vector<size_t> indexes;
            };

            Neighborhoods(size_t count_);
            const size_t Count() const;
            const Neighborhood& operator[](size_t index_) const;
            Neighborhood& operator[](size_t index_);
        private:
            std::vector<Neighborhood> neighborhoods;
        };
    protected:
        explicit Topology(size_t count_);
        Neighborhoods neighborhoods;
    };

    class Full : public Topology
    {
    protected:
        explicit Full(size_t size_) : Topology(1)
        {
            for (size_t i = 0; i < size_; ++i)
                neighborhoods[0].Add(i);
        }
    };

    template <int N>
    class Multi : public Topology
    {
    protected:
        explicit Multi(size_t size_) : Topology(N)
        {
            for (size_t i = 0; i < size_; ++i)
                neighborhoods[i % N].Add(i);
        }
    };

    class Ring : public Topology
    {
    protected:
        explicit Ring(size_t size_) : Topology(size_)
        {
            neighborhoods[0].Add(0);
            neighborhoods[0].Add(1);
            neighborhoods[0].Add(size_ - 1);
            for (size_t i = 1; i < size_ - 1; ++i)
            {
                neighborhoods[i].Add(i);
                neighborhoods[i].Add(i + 1);
                neighborhoods[i].Add(i - 1);
            }
            neighborhoods[size_ - 1].Add(size_ - 1);
            neighborhoods[size_ - 1].Add(0);
            neighborhoods[size_ - 1].Add(size_ - 2);
        }
    };

    class Star : public Topology
    {
    protected:
        explicit Star(size_t size_) : Topology(size_)
        {
            size_t central = size_ / 3;
            for (size_t i = 0; i < size_; ++i)
            {
                neighborhoods[i].Add(i);
                if (i != central)
                {
                    neighborhoods[i].Add(central);
                    neighborhoods[central].Add(i);
                }               
            }
            neighborhoods[central].Set(central);
        }
    };
}

#endif // PSOPP_TOPOLOGY_HPP