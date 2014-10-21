/**
* The following code defines class ParserEvaluator,
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
        class Domain,
        class ParticleType
    >
    class ParserEvaluator : public Parser
    {
        typedef typename Domain::domain_type T;
        typedef typename ParticleType particle_type;
    public:
        ParserEvaluator() : Parser(Domain::Size) {}

        void SetExpression(const std::string& expression_)
        {
            Parser::SetExpression(expression_);
        }

        T operator ()(const particle_type& particle_) const
        {
            for (size_t i = 0; i < Domain::Size; ++i)
                variables[i] = particle_.position.coordinates[i];
            return Evaluate();
        }
    };
}

#endif // PSOPP_PARSEREVALUATOR_HPP