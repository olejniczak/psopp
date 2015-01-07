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
#include "DomainNovelTSP.hpp"
#include "NovelTSP.hpp"
#include "InitNovelTSP.hpp"

using namespace psopp;

typedef Swarm<10, DomainNovelTSP, Full> Full_10;

typedef Algorithm<Full_10, CanonicalPSO, NovelTSP, InitNovelTSP, Random<> > tsp_pso_full;

int main()
{
    tsp_pso_full tpf;
    tpf.Start(100);

    return 0;
}