/**
* The following code declares class Algorithm,
* which is base class for the concrete pso variant.
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version 0.2.0
* @date <DATE>
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_BASEPARAMETERS_HPP
#define PSOPP_BASEPARAMETERS_HPP

#include <array>

namespace psopp
{
    template <class TReader>
    class BaseParameters : public TReader
    {
    public:
        BaseParameters() : TReader() {}
        BaseParameters(const std::string& parameters_) : TReader(parameters_) {}
        void Read()
        {
            inertia_weight = this->template get<double>("inertia_weight");
            particle_learn = this->template get<double>("particle_learn");
            swarm_learn = this->template get<double>("swarm_learn");
        }
    public:
        double inertia_weight;
        double particle_learn;
        double swarm_learn;
    };
}

#endif // PSOPP_BASEPARAMETERS_HPP