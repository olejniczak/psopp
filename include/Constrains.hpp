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
#ifndef PSOPP_CONSTRAINS_HPP
#define PSOPP_CONSTRAINS_HPP

namespace psopp
{
    class NoConstrains
    {
    public:
        bool Satisfied() const { return true; }
    };

    class ExpressionConstrains
    {
    public:
        bool Satisfied() const { return true; }
    };
}

#endif // PSOPP_CONSTRAINS_HPP