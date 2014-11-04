// pbPSO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Algorithm.hpp"
#include "CanonicalPSO.hpp"
#include "DomainR.hpp"
#include "XmlReader.hpp"
#include "IOReader.hpp"
#include "Rosenbrock.hpp"
#include "Himmelblau.hpp"
#include "Topology.hpp"
#include "Random.hpp"
#include "Init.hpp"

#include "pso.h"

using namespace psopp;
typedef Algorithm<R<30>, Full, BaseParameters, IOReader, CanonicalPSO, StdInit, Rosenbrock, Random<> > real_pso;

int _tmain(int argc, _TCHAR* argv[])
{
    real_pso rpso;//"parameters.xml"
    std::cout << rpso.Start(100000);
    std::cin.get();
	return 0;
}

