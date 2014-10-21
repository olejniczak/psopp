#include <array>

namespace psopp
{
    template <class Reader>
    class BaseParameters : public Reader
    {
    public:
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

    template <class D>
    class Minimize
    {
        typedef typename D::domain_type T;
    public:
        bool operator () (T arga, T argb) const
        {
            return arga < argb;
        }
    };

    template <class D>
    class Maximize
    {
        typedef typename D::domain_type T;
    public:
        bool operator () (T arga, T argb) const
        {
            return arga > argb;
        }
    };

    template <class D>
    class Initializer
    {
        typedef typename D::domain_type T;
        typedef typename D::position_type position_type;
        typedef typename D::velocity_type velocity_type;
        typedef typename D::particle_type particle_type;
    public:
        
    };


}