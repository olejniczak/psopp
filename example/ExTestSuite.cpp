#include "OptiSuite.hpp"

using namespace psopp;

int main()
{
#if 0
    OptimizationSuite1
    <
        TASwarmFull,
        SwarmSize<10>, SwarmSize<20>, SwarmSize<50>, SwarmSize<100>
    >
    opti_sizes("d:\\psopp\\sizes", 50);
    opti_sizes.Optimize<Rosenbrock, Sphere, StyblinskiTang, Ackley1>();
    opti_sizes.GenerateReport<ConvergencePlot>();
#elif 0
    OptimizationSuite1
    <
        TATopology50,
        Full, Ring, Star
    >
    opti_topos("d:\\psopp\\topos", 50);
    opti_topos.Optimize<Rosenbrock, Sphere, StyblinskiTang, Ackley1>();
    opti_topos.GenerateReport<ConvergencePlot>();
#else
    OptimizationSuite2
    <
        TAVariantFull20,
        CanonicalPSO, ConstrictedPSO
    >
    opti_variants("d:\\psopp\\variants", 50);
    opti_variants.Optimize<Rosenbrock, Sphere, StyblinskiTang, Ackley1>();
    opti_variants.GenerateReport<ConvergencePlot>();
#endif
    return 0;
}

