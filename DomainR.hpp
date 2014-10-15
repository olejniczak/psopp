/**
* The following code defines class R,
* which is R domain
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
#ifndef PSOPP_DOMAINR_HPP
#define PSOPP_DOMAINR_HPP

namespace psopp
{
    template <
        typename T = double, 
        int N = 3
    >
    class R
    {
    public:
        class Position
        {
        public:
            Position& operator+=(const typename R::Velocity& velocity_)
            {
                for (size_t i = 0; i < N; ++i)
                    coordinates[i] += velocity_.coordinates[i];
                return *this;
            }
        private:
            std::array<T, N> coordinates{};
        };

        class Velocity
        {
            friend class R::Position;
        public:
            Velocity() {}
            Velocity(const Position& posa_, const Position& posb_)
            {
                for (size_t i = 0; i < N; ++i)
                    components[i] = posa_.coordinates[i] - posb_.coordinates[i];
            }

            Velocity& operator*=(T factor_)
            {
                for (size_t i = 0; i < N; ++i)
                    components[i] *= factor_;
                return *this;
            }

            Velocity& operator+=(const Velocity& velocity_)
            {
                for (size_t i = 0; i < N; ++i)
                    components[i] += velocity_.components[i];
                return *this;
            }
        private:
            std::array<T, N> components{};
        };
    public:
        typedef Position position_type;
        typedef Velocity velocity_type;
        typedef T domain_type;
    };

    template <class Domain>
    typename Domain::velocity_type operator- (const typename Domain::position_type& posa_, const typename Domain::position_type& posb_)
    {
        return Domain::velocity_type(posa_, posb_);
    }

    typedef R<> R3;
}

#endif // PSOPP_DOMAINR_HPP