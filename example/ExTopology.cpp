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
#include "Topology.hpp"

using namespace psopp;
typedef Algorithm<R2, Full, BaseParameters, MapReader, CanonicalPSO, StdInit, Rosenbrock, Random<> > real_pso_full;
typedef Algorithm<R2, Star, BaseParameters, MapReader, CanonicalPSO, StdInit, Rosenbrock, Random<> > real_pso_star;
typedef Algorithm<R2, Multi<2>, BaseParameters, MapReader, CanonicalPSO, StdInit, Rosenbrock, Random<> > real_pso_2;
typedef Algorithm<R2, Multi<3>, BaseParameters, MapReader, CanonicalPSO, StdInit, Rosenbrock, Random<> > real_pso_3;
typedef Algorithm<R2, Multi<4>, BaseParameters, MapReader, CanonicalPSO, StdInit, Rosenbrock, Random<> > real_pso_4;

int main()
{
    //real_pso rpso;//"parameters.xml"
    //std::cout << rpso.Start(100000);

    //real_pso_full rpf;
    real_pso_star rps;
    real_pso_2 r2;
    real_pso_3 r3;
    real_pso_4 r4;

    //std::cout << rpf.Start(10000) << std::endl;
    std::cout << rps.Start(50) << std::endl;
    std::cout << r2.Start(50) << std::endl;
    std::cout << r3.Start(50) << std::endl;
    std::cout << r4.Start(50) << std::endl;

    std::cin.get();
	return 0;
}

