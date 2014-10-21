// pbPSO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Algorithm.hpp"
#include "CanonicalPSO.hpp"
#include "DomainR.hpp"
#include "XmlReader.hpp"
#include "ParserEvaluator.hpp"
#include "Topology.hpp"

#include "pso.h"


using namespace psopp;
typedef Algorithm<R3, FullyInformed, BaseParameters, XmlReader, CanonicalPSO, Minimize, ParserEvaluator> real_pso;

int _tmain(int argc, _TCHAR* argv[])
{
    real_pso rpso("parameters.xml");
    rpso.Step();
	return 0;
}

