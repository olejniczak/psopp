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
                const std::size_t Count() const;
                void Add(std::size_t index_);
                void Set(std::size_t index_);
                std::size_t operator[] (std::size_t index_) const;
            private:
                std::vector<std::size_t> indexes;
            };

            Neighborhoods(std::size_t count_);
            const std::size_t Count() const;
            const Neighborhood& operator[](std::size_t index_) const;
            Neighborhood& operator[](std::size_t index_);
        private:
            std::vector<Neighborhood> neighborhoods;
        };
    protected:
        explicit Topology(std::size_t count_);
        Neighborhoods neighborhoods;
    };

    class Full : public Topology
    {
    protected:
        explicit Full(std::size_t size_) : Topology(1)
        {
            for (std::size_t i = 0; i < size_; ++i)
                neighborhoods[0].Add(i);
        }
    };

    class Ring : public Topology
    {
    protected:
        explicit Ring(std::size_t size_) : Topology(size_)
        {
            neighborhoods[0].Add(0);
            neighborhoods[0].Add(1);
            neighborhoods[0].Add(size_ - 1);
            for (std::size_t i = 1; i < size_ - 1; ++i)
            {
                neighborhoods[i].Add(i);
                neighborhoods[i].Add(i + 1);
                neighborhoods[i].Add(i - 1);
            }
        }
    };

    class Star : public Topology
    {
    protected:
        explicit Star(std::size_t size_) : Topology(size_)
        {
            std::size_t central = size_ / 3;
            for (std::size_t i = 0; i < size_; ++i)
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