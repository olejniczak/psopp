#include <iostream>

#include "Algorithm.hpp"
#include "BaseParameters.hpp"
#include "CanonicalPSO.hpp"
#include "ConstrictedPSO.hpp"
#include "DomainR.hpp"
#include "Himmelblau.hpp"
#include "Init.hpp"
#include "MapReader.hpp"
#include "Random.hpp"
#include "Rosenbrock.hpp"
#include "Swarm.hpp"
#include "Topology.hpp"


using namespace psopp;

typedef Swarm<20, R2, Full> Full_20;
typedef Swarm<10, R2, Full> Full_10;

typedef Algorithm<Full_20, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_full;
typedef Algorithm<Full_20, ConstrictedPSO, Rosenbrock, StdInit, Random<> > real_pso_cons;
typedef Algorithm<Full_10, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_full1;
typedef Algorithm<Full_10, ConstrictedPSO, Rosenbrock, StdInit, Random<> > real_pso_cons1;

int main()
{
    for (int i = 0; i < 20; ++i)
    {
        real_pso_full rpf;
        std::cout << rpf.Start(5000) << "\t";

        real_pso_cons rpc;
        std::cout << rpc.Start(5000) << "\t";

        real_pso_full1 rpf1;
        std::cout << rpf1.Start(5000) << "\t";

        real_pso_cons1 rpc1;
        std::cout << rpc1.Start(5000) << std::endl;
    }

    std::cin.get();
	return 0;
}

