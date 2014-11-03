// pbPSO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Algorithm.hpp"
#include "CanonicalPSO.hpp"
#include "DomainR.hpp"
#include "XmlReader.hpp"
#include "IOReader.hpp"
#include "Rosenbrock.hpp"
#include "Topology.hpp"
#include "Random.hpp"
#include "Init.hpp"

#include "pso.h"

using namespace psopp;
typedef Algorithm<R2, Full, BaseParameters, IOReader, CanonicalPSO, StdInit, Rosenbrock, Random<> > real_pso;

int _tmain(int argc, _TCHAR* argv[])
{
    Random<> r;
    for (int i = 0; i < 10; ++i) std::cout << r.GetInt(0,2*i) << std::endl;


    real_pso rpso;//"parameters.xml"
    for (int i = 0; i < 1000; ++i)
        rpso.Step();
	return 0;
}

