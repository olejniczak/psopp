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
            inertia_weight = get<double>("inertia_weight");
            particle_learn = get<double>("particle_learn");
            swarm_learn = get<double>("swarm_learn");
        }
    public:
        double inertia_weight;
        double particle_learn;
        double swarm_learn;
    };
}