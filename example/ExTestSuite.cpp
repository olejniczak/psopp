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
    opti_sizes.GeneratePlot<MultiPlot>({ "Rosenbrock", "Sphere", "StyblinskiTang", "Ackley" }, 
                                       { "10 particles", "20 particles", "50 particles", "100 particles" });
#elif 1
    OptimizationSuite1
    <
        TATopology50,
        Full, Ring, Star
    >
    opti_topos("d:\\psopp\\topoz", 50);
    opti_topos.Optimize<Rosenbrock, Sphere, StyblinskiTang, Ackley1>();
    opti_topos.GenerateReport<ConvergencePlot>();
    opti_topos.GeneratePlot<MultiPlot>({ "Rosenbrock", "Sphere", "StyblinskiTang", "Ackley" }, 
                                       { "Full", "Ring", "Star" });
#else
    OptimizationSuite2
    <
        TAVariantFull20,
        CanonicalPSO, ConstrictedPSO
    >
    opti_variants("d:\\psopp\\variants", 50);
    opti_variants.Optimize<Rosenbrock, Sphere, StyblinskiTang, Ackley1>();
    opti_variants.GenerateReport<ConvergencePlot>();
    opti_variants.GeneratePlot<MultiPlot>({ "Rosenbrock", "Sphere", "StyblinskiTang", "Ackley" }, 
                                          { "Canonical", "Constricted" });
#endif
    return 0;
}

