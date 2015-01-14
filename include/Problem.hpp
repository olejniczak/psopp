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
#ifndef PSOPP_PROBLEM_HPP
#define PSOPP_PROBLEM_HPP

namespace psopp
{
    template<
        class TDomain
    >
    class Problem
    {
    public:
        typedef TDomain domain_type;
        typedef typename TDomain::value_type value_type;
        typedef typename TDomain::position_type position_type;
    protected:
        virtual void operator()(typename TDomain::position_type& position_) const = 0;
        virtual value_type Min(std::size_t dim_) const = 0;
        virtual value_type Max(std::size_t dim_) const = 0;
    };
}

#endif // PSOPP_PROBLEM_HPP
