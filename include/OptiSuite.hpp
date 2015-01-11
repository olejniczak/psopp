/**
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version 0.2.0
* @date <DATE>
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_OPTISUITE_HPP
#define PSOPP_OPTISUITE_HPP

#include "Ackley.hpp"
#include "Algorithm.hpp"
#include "CanonicalPSO.hpp"
#include "ConstrictedPSO.hpp"
#include "DomainR.hpp"
#include "DumpFile.hpp"
#include "Init.hpp"
#include "Rosenbrock.hpp"
#include "Sphere.hpp"
#include "StyblinskiTang.hpp"
#include "Swarm.hpp"
#include "Topology.hpp"

namespace psopp
{
    /**
     * @class SwarmSize
     * @brief Helper numeric class
     * @brief Translates integer number into type
     */
    template <std::size_t N>
    struct SwarmSize
    {
        static const std::size_t Value = N;
    };

    /**
     * Size parametrizable swarms with different topologies
     */
    template <class Size> using SwarmFull = Swarm <Size::Value, R2, Full>;
    template <class Size> using SwarmRing = Swarm <Size::Value, R2, Ring>;
    template <class Size> using SwarmStar = Swarm <Size::Value, R2, Star>;

    /**
     * Two argument algorithm templates for optimization suite (swarm size & optimization problem)
     */
    template <class TSwarmSize, template <class> class TProblem>
    using TASwarmFull = Algorithm<SwarmFull<TSwarmSize>, CanonicalPSO, TProblem, StdInit, DumpFile>;

    template <class TSwarmSize, template <class> class TProblem>
    using TASwarmRing = Algorithm<SwarmRing<TSwarmSize>, CanonicalPSO, TProblem, StdInit, DumpFile>;

    template <class TSwarmSize, template <class> class TProblem>
    using TASwarmStar = Algorithm<SwarmStar<TSwarmSize>, CanonicalPSO, TProblem, StdInit, DumpFile>;

    /**
     * Topology parametrizable swarms with different sizes
     */
    template <class Topo>  using SwarmTopo20 = Swarm <20, R2, Topo>;
    template <class Topo>  using SwarmTopo30 = Swarm <30, R2, Topo>;
    template <class Topo>  using SwarmTopo50 = Swarm <50, R2, Topo>;

    /**
     * Two argument algorithm templates for optimization suite (topology & optimization problem)
     */
    template <class TTopo, template <class> class TProblem>
    using TATopology20 = Algorithm<SwarmTopo20<TTopo>, CanonicalPSO, TProblem, StdInit, DumpFile>;

    template <class TTopo, template <class> class TProblem>
    using TATopology30 = Algorithm<SwarmTopo30<TTopo>, CanonicalPSO, TProblem, StdInit, DumpFile>;

    template <class TTopo, template <class> class TProblem>
    using TATopology50 = Algorithm<SwarmTopo50<TTopo>, CanonicalPSO, TProblem, StdInit, DumpFile>;


    /**
     * Two argument algorithm templates for optimization suite (algorithm variant & optimization problem)
     */
    template <template <class> class TVariant, template <class> class TProblem>
    using TAVariantFull20 = Algorithm<SwarmTopo20<Full>, TVariant, TProblem, StdInit, DumpFile>;


    /**
     * Helper function - number to string
     */
    std::string SubDirectory(size_t num_)
    {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << num_;
        return ss.str();
    }

    /**
     * @class ProblemPack
     */
    template
    <
        template <template <class> class> class G1, 
        template <class> class... Ps
    >
    struct ProblemPack 
    {
        ProblemPack(const std::string&, size_t) {}
    };

    /**
     * @class ProblemPack
     */
    template<template <template <class> class> class G1, template <class> class P, template <class> class... Ps>
    struct ProblemPack<G1, P, Ps...> : ProblemPack<G1, Ps...>{
        ProblemPack(const std::string& name_, size_t steps_)
        : ProblemPack<G1, Ps...>(name_, steps_), sub(name_ + "\\P" + SubDirectory(sizeof...(Ps)), steps_)
        {
        }
    private:
        G1<P> sub;
    };

    /**
     * @class Pack1P
     */
    template 
    <
        template <class, template <class> class> class TA, 
        template <class> class P, 
        class... Ts
    >
    struct Pack1P 
    {
        Pack1P(const std::string&, size_t) {}
    };

    /**
     * @class Pack1P
     */
    template
    <
        template <class, template <class> class> class TA, 
        template <class> class P, class T, class... Ts
    >
    struct Pack1P<TA, P, T, Ts...> : Pack1P<TA, P, Ts...>
    {
        Pack1P(const std::string& name_, size_t steps_)
            : Pack1P<TA, P, Ts...>(name_, steps_)
        {
            inst.DumpDirectory(name_ + "\\T" + SubDirectory(sizeof...(Ts)));
            inst.Start(steps_);
        }
        TA<T, P> inst;
    };


    /**
    * @class Pack2P
    */
    template
    <
        template <template <class> class, template <class> class> class TA,
        template <class> class P, 
        template <class> class... Ts
    >
    struct Pack2P
    {
        Pack2P(const std::string&, size_t) {}
    };

    /**
     * @class Pack2P
     */
    template
    <
        template <template <class> class, template <class> class> class TA,
        template <class> class P, 
        template <class> class T,
        template <class> class... Ts
    >
    struct Pack2P<TA, P, T, Ts...> : Pack2P<TA, P, Ts...>
    {
        Pack2P(const std::string& name_, size_t steps_)
        : Pack2P<TA, P, Ts...>(name_, steps_)
        {
            inst.DumpDirectory(name_ + "\\T" + SubDirectory(sizeof...(Ts)));
            inst.Start(steps_);
        }
        TA<T, P> inst;
    };


    /**
     * @class OptimizationSuiteBase
     */
    struct OptimizationSuiteBase
    {
        OptimizationSuiteBase(const std::string& directory_, std::size_t steps_)
            : directory(directory_), step_count(steps_)
        {}
    protected:
        std::string directory;
        std::size_t step_count;
    };

    /**
     * @class OptimizationSuite1
     */
    template
    <
        template <class, template <class> class> class TAlgorithm,
        class... Ts
    >
    struct OptimizationSuite1 : OptimizationSuiteBase
    {
        OptimizationSuite1(const std::string& directory_, std::size_t steps_)
            : OptimizationSuiteBase(directory_, steps_)
        {}

        template <template <class> class... Ps>
        void Optimize()
        {
            ProblemPack<Pack, Ps...> opti(directory, step_count);
        }
    private:
        template <template <class> class TProblem>
        using Pack = Pack1P < TAlgorithm, TProblem, Ts...>;
    };

    /**
     * @class OptimizationSuite2
     */
    template
    <
        template <template <class> class, template <class> class> class TAlgorithm,
        template <class> class... Ts
    >
    struct OptimizationSuite2 : OptimizationSuiteBase
    {
        OptimizationSuite2(const std::string& directory_, std::size_t steps_)
            : OptimizationSuite(Basedirectory_, steps_)
        {}

        template <template <class> class... Ps>
        void Optimize()
        {
            ProblemPack<Pack, Ps...> opti(directory, step_count);
        }
    private:
        template <template <class> class TProblem>
        using Pack = Pack2P < TAlgorithm, TProblem, Ts...>;
    };
}

#endif //PSOPP_OPTISUITE_HPP