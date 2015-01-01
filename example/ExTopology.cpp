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

template <class Topo>
using SwarmTopo = Swarm < 20, R2, Topo > ;
template <size_t Size> using SwarmRing = Swarm <Size, R2, Ring>;

typedef Algorithm<SwarmTopo<Full>, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_full;
typedef Algorithm<SwarmTopo<Star>, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_star;
typedef Algorithm<SwarmRing<33>, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_ring_33;
typedef Algorithm<SwarmTopo<Multi<2>>, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_2;
typedef Algorithm<SwarmTopo<Multi<3>>, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_3;
typedef Algorithm<SwarmTopo<Multi<4>>, CanonicalPSO, Rosenbrock, StdInit, Random<> > real_pso_4;

int main()
{
    //real_pso rpso;//"parameters.xml"
    //std::cout << rpso.Start(100000);

    //real_pso_full rpf;
    real_pso_star rps;
    real_pso_2 r2;
    real_pso_3 r3;
    real_pso_4 r4;
    real_pso_ring_33 r33;

    //std::cout << rpf.Start(10000) << std::endl;
    std::cout << rps.Start(50) << std::endl;
    std::cout << r2.Start(50) << std::endl;
    std::cout << r3.Start(50) << std::endl;
    std::cout << r4.Start(50) << std::endl;

    std::cin.get();
	return 0;
}

