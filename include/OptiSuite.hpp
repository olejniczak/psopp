/**
*
* See http://przole.github.io/psopp for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version 0.2.0
* @date 2015.01.11
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_OPTISUITE_HPP
#define PSOPP_OPTISUITE_HPP

#include <direct.h>

#include "Ackley.hpp"
#include "Algorithm.hpp"
#include "CanonicalPSO.hpp"
#include "ConstrictedPSO.hpp"
#include "DomainR.hpp"
#include "DumpFile.hpp"
#include "Init.hpp"
#include "ReportGen.hpp"
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



    //std::string SubDirectory(size_t num_)
    //{
    //    std::stringstream ss;
    //    ss << std::setfill('0') << std::setw(2) << num_;
    //    return ss.str();
    //}

    /**
     * Helper function - create directory
     */
    void CreateDirectory(const std::string& dir_)
    {
#if defined(_WIN32) || defined(_WIN64)
        _mkdir(dir_.c_str());
#else 
        mkdir(dir_.c_str(), 0777);
#endif
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
    template
    <
        template <template <class> class> class G1, 
        template <class> class P, 
        template <class> class... Ps
    >
    struct ProblemPack<G1, P, Ps...> : ProblemPack<G1, Ps...>
    {
        ProblemPack(const std::string& name_, size_t steps_)
            : ProblemPack<G1, Ps...>(name_, steps_),
              pack(name_ + "\\P" + SubDirectory(sizeof...(Ps)), steps_)
        {
        }
    private:
        G1<P> pack;
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
            CreateDirectory(name_);
            std::string dir(name_ + "\\T" + SubDirectory(sizeof...(Ts)));
            CreateDirectory(dir);
            instance.DumpDirectory(dir);
            instance.Start(steps_);
        }
        TA<T, P> instance;
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
            CreateDirectory(name_);
            std::string dir(name_ + "\\T" + SubDirectory(sizeof...(Ts)));
            CreateDirectory(dir);
            instance.DumpDirectory(dir);
            instance.Start(steps_);
        }
        TA<T, P> instance;
    };


    /**
     * @class OptimizationSuiteBase
     */
    struct NoReport
    {
        NoReport(std::size_t problems_count_, std::size_t params_count_, std::size_t step_count_) {}
        void Generate(const std::string& directory_, const std::string& report_dir_) {}
    };
    struct OptimizationSuiteBase
    {
        char* const REPORT_DIR = "\\report";

        OptimizationSuiteBase(const std::string& directory_, std::size_t steps_)
            : directory(directory_), step_count(steps_)
        {
            CreateDirectory(directory);
        }

        template <class TGenerator = NoReport>
        void GenerateReport()
        {
            CreateDirectory(directory + REPORT_DIR);
            TGenerator report_gen(ProblemsCount(), ParamsCount(), step_count);
            report_gen.Generate(directory, REPORT_DIR);
        }
    protected:
        virtual std::size_t ProblemsCount() const = 0;
        virtual std::size_t ParamsCount() const = 0;
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
            problems_count = sizeof...(Ps);
            ProblemPack<Pack, Ps...> opti(directory, step_count);
        }
    protected:
        virtual std::size_t ProblemsCount() const { return problems_count; };
        virtual std::size_t ParamsCount() const { return sizeof...(Ts); };
    private:
        template <template <class> class TProblem>
        using Pack = Pack1P < TAlgorithm, TProblem, Ts...>;
        std::size_t problems_count = {};
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
            : OptimizationSuiteBase(directory_, steps_)
        {}

        template <template <class> class... Ps>
        void Optimize()
        {
            problems_count = sizeof...(Ps);
            ProblemPack<Pack, Ps...> opti(directory, step_count);
        }
    protected:
        virtual std::size_t ProblemsCount() const { return problems_count; };
        virtual std::size_t ParamsCount() const { return sizeof...(Ts); };
    private:
        template <template <class> class TProblem>
        using Pack = Pack2P < TAlgorithm, TProblem, Ts...>;
        std::size_t problems_count = {};
    };
}

#endif //PSOPP_OPTISUITE_HPP