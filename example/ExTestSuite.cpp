#include "OptiSuite.hpp"

using namespace psopp;

int main()
{
    OptimizationSuite1<TASwarmFull, SwarmSize<10>, SwarmSize<20>, SwarmSize<50>, SwarmSize<100>> opti_suite("d:\\pso2", 200);
    opti_suite.Optimize<Rosenbrock, Sphere, StyblinskiTang, Ackley1>();

    return 0;
}

