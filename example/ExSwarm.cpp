#include <iostream>

#include "Algorithm.hpp"
#include "BaseParameters.hpp"
#include "CanonicalPSO.hpp"
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

typedef Algorithm<Full_20, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_full;

int main()
{
	real_pso_full rpf;
    std::cout << rpf.Start(5000) << std::endl;

	std::cin.get();
	return 0;
}

