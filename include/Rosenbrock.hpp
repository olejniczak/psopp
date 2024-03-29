/**
 * The following code declares class Variant,
 * which is base class for the concrete pso variant.
 *
 * See http://przole.github.io/psopp for documentation.
 *
 * @author Copyright &copy 2011 Przemysław Olejniczak.
 * @version 0.2.0
 * @date 2014.12.29
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 */
#ifndef PSOPP_ROSENBROCK_HPP
#define PSOPP_ROSENBROCK_HPP

#include "Problem.hpp"

namespace psopp
{
    /**
     * The following code declares class Rosenbrock,
     * which is the optimization problem
     * N-dimensional Rosenbrock's function
     *
     * \image html rosenbrock.jpg
     */
    template<
        class Domain
    >
    class Rosenbrock : public Problem<Domain>
    {
    public:
        void operator()(typename Domain::position_type& position_) const
        {
            position_.fitness = {};
            for (size_t i = 0; i < Domain::Size - 1; ++i)
            {
                auto xi = position_.coordinates[i];
                auto xii = position_.coordinates[i + 1];
                position_.fitness += (1 - xi) * (1 - xi) + 100 * (xii - xi * xi) * (xii - xi * xi);
            }
        }

        typename Domain::value_type Min(size_t dim_) const
        {
            return -25;
        }

        typename Domain::value_type Max(size_t dim_) const
        {
            return 25;
        }
    };
}

#endif // PSOPP_ROSENBROCK_HPP
