/**
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
#ifndef PSOPP_ACKLEY_HPP
#define PSOPP_ACKLEY_HPP

#define _USE_MATH_DEFINES
#include <cmath>

#include "Problem.hpp"


namespace psopp
{
    class AckleyParams
    {
    protected:
        double a() const
        {
            return 20;
        }
        double b() const
        {
            return 0.2;
        }
        double c() const
        {
            return 2 * 3.14159265358979323846;
        }
    };
    /**
     * The following code declares class Ackley,
     * which is the optimization problem
     * N-dimensional Ackley's function
     *
     * \image html ackley.jpg
     */
    template<
        class TDomain,
        class TParams = AckleyParams
    >
    class Ackley : public Problem<TDomain>, public TParams
    {
    public:
        void operator()(typename TDomain::position_type& position_) const
        {
            typename TDomain::value_type sum[2] = {};

            for (std::size_t i = 0; i < TDomain::Size; ++i)
            {
                auto xi = position_.coordinates[i];
                sum[0] += xi * xi;
                sum[1] += std::cos(this->c() * xi);
            }

            double n = TDomain::Size;
            position_.fitness = -this->a() * std::exp(-this->b() * sqrt(sum[0] / n)) - std::exp(sum[1] / n) + this->a() + std::exp(1);
        }

        typename TDomain::value_type Min(std::size_t dim_) const
        {
            return -5;
        }

        typename TDomain::value_type Max(std::size_t dim_) const
        {
            return 5;
        }
    };

    template <class TDomain> using Ackley1 = Ackley <TDomain>;
}

#endif // PSOPP_ROSENBROCK_HPP
