/**
* The following code defines class R,
* which is R domain
*
* See http://przole.github.io/psopp for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version 0.2.0
* @date 2014.12.29
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_DOMAINTSP_HPP
#define PSOPP_DOMAINTSP_HPP

#include <memory>
#include <vector>

namespace psopp
{
    /**
    *
    */
    class DomainNovelTSP
    {
        struct coordinate
        {
            coordinate(const coordinate&) = delete;

            coordinate(int a_, int b_) : a(a_), b(b_) {}

            bool operator == (const coordinate& other_) const
            {
                return (a == other_.a && b == other_.b) 
                    || (a == other_.b && b == other_.a);
            }

            int a, b;
        };

        struct component
        {
            component(const component&) = delete;
            component(int a_, int b_, double p_ = 1.0)
                : c(a_, b_), p(p_) {}

            coordinate c;
            double p;
        };

        typedef std::unique_ptr<coordinate> pcoordinate;
        typedef std::unique_ptr<component> pcomponent;
    public:
        explicit DomainNovelTSP(size_t size_)
            : Size(size_)
        {
        }
        /**
        *
        */
        class Position;
        class Velocity
        {
            friend class DomainNovelTSP::Position;
        public:
            Velocity() {}
            Velocity(const DomainNovelTSP::Position& posa_, const DomainNovelTSP::Position& posb_)
            {
                for (auto& ca : posa_.coordinates)
                {
                    bool next = false;
                    for (auto& cb : posb_.coordinates)
                    {
                        if (*ca == *cb)
                        {
                            next = true;
                            continue;
                        }
                    }
                    if (next) continue;
                    components.push_back(pcomponent(new component(ca->a, ca->b)));
                }
            }

            void Initialize(size_t size_)
            {
                components.resize(size_, pcomponent(new component(0,0)));
            }

            Velocity& operator*=(double factor_)
            {
                for (size_t i = 0; i < components.size(); ++i)
                    components[i]->p *= factor_;
                return *this;
            }

            Velocity& operator+=(const Velocity& velocity_)
            {
                for (size_t i = 0; i < velocity_.components.size(); ++i)
                    components.push_back(pcomponent(
                                           new component(velocity_.components[i]->c.a,
                                                         velocity_.components[i]->c.b,
                                                         velocity_.components[i]->p
                                           )
                                        )
                                    );
                return *this;
            }
        public:
            std::vector<pcomponent> components;
        };

        /**
        *
        */
        class Position
        {
            friend class Velocity;
        public:
            Position& operator+=(const Velocity& velocity_)
            {
                // update position

                return *this;
            }

            Velocity operator- (const Position& other_) const
            {
                return Velocity(*this, other_);
            }
        public:
            std::vector<pcoordinate> coordinates;
            double fitness;
        };
    public:
        typedef Position position_type;
        typedef Velocity velocity_type;
        typedef double value_type;

        const int Size;
    };
}

#endif // PSOPP_DOMAINTSP_HPP
