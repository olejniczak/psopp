/**
* The following code defines class ParserEvaluator,
* which is 
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemysław Olejniczak.
* @version 0.2.0
* @date <DATE>
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_PARSEREVALUATOR_HPP
#define PSOPP_PARSEREVALUATOR_HPP

#include <string>
#include <vector>

namespace psopp
{
    class Parser
    {
    private:
        Parser(const Parser&);
        Parser& operator= (const Parser&);
    protected:
        Parser(int domain_size_);
        ~Parser();
        void SetExpression(const std::string& expression_);
        double Evaluate();
    protected:
        std::vector<double> variables;
        struct Implementation* implementation;
    };

    template <
        class Domain
    >
    class ParserEvaluator : public Parser
    {
        typedef typename Domain::value_type T;
        typedef typename Domain::position_type position_type;
    public:
        ParserEvaluator() : Parser(Domain::Size) {}

        void SetExpression(const std::string& expression_)
        {
            Parser::SetExpression(expression_);
        }

        T operator ()(const position_type& position_) const
        {
            for (size_t i = 0; i < Domain::Size; ++i)
                variables[i] = position_.coordinates[i];
            return Evaluate();
        }
    };
}

#endif // PSOPP_PARSEREVALUATOR_HPP