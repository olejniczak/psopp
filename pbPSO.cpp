// pbPSO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Algorithm.hpp"
#include "CanonicalPSO.hpp"
#include "DomainR.hpp"

#include "pso.h"
using namespace psopp;
typedef algorithm<R3, parameters, canonical_pso, 10, Minimize, Evaluator> real_pso;

int _tmain(int argc, _TCHAR* argv[])
{
    real_pso rpso;
    rpso.Step();
	return 0;
}

