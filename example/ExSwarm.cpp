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
#include "DumpFile.hpp"

using namespace psopp;

typedef Swarm<20, R2, Full> Full_20;
typedef Swarm<10, R2, Full> Full_10;

typedef Algorithm<Full_20, CanonicalPSO, Rosenbrock, StdInit, DumpFile> real_pso_full;
typedef Algorithm<Full_20, ConstrictedPSO, Rosenbrock, StdInit> real_pso_cons;
typedef Algorithm<Full_10, CanonicalPSO, Rosenbrock, StdInit> real_pso_full1;
typedef Algorithm<Full_10, ConstrictedPSO, Rosenbrock, StdInit> real_pso_cons1;

int main()
{
    for (int i = 0; i < 1; ++i)
    {
        real_pso_full rpf;
        rpf.DumpDirectory("D:\\pso");
        std::cout << rpf.Start(200) << "\t";

        real_pso_cons rpc;
        std::cout << rpc.Start(50) << "\t";

        real_pso_full1 rpf1;
        std::cout << rpf1.Start(50) << "\t";

        real_pso_cons1 rpc1;
        std::cout << rpc1.Start(50) << std::endl;
    }

    std::cin.get();
	return 0;
}

