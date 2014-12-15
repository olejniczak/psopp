/**
* The following code declares class Variant,
* which is base class for the concrete pso variant.
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
#ifndef PSOPP_PROBLEM_HPP
#define PSOPP_PROBLEM_HPP

namespace psopp
{
    template<
        class Domain
    >
    class Problem
    {
    public:
        typedef typename Domain domain_type;
        typedef typename Domain::value_type value_type;
        typedef typename Domain::position_type position_type;
    protected:
        virtual void operator()(typename Domain::position_type& position_) const = 0;
        virtual value_type Min(std::size_t dim_) const = 0;
        virtual value_type Max(std::size_t dim_) const = 0;
    };
}

#endif // PSOPP_PROBLEM_HPP
