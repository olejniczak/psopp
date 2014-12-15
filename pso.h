#include <array>

namespace psopp
{
    template <class Reader>
    class BaseParameters : public Reader
    {
    public:
        BaseParameters() : Reader() {}
        BaseParameters(const std::string& parameters_) : Reader(parameters_) {}
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
