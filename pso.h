#include <array>

namespace psopp
{


    

    template <class D/*, class R*/>
    class parameters
    {
        typedef typename D::domain_type T;
    public:
        void Read()
        {
            inertia_weight = reader.get<T>("inertia_weight");
            particle_learn = reader.get<T>("particle_learn");
            swam_learn = reader.get<T>("swam_learn");
        }
    public:
        T inertia_weight;
        T particle_learn;
        T swam_learn;
    private:
        //R reader;
    };

    template <
        class D,
        class P
    >
    class Evaluator
    {
        typedef typename D::domain_type T;
        typedef typename P particle_type;
    public:
        T operator ()(const particle_type& particle_) const
        {

            return 0;
        }
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