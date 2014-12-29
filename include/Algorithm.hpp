/**
* @mainpage
* @par O PSO++:
* Biblioteka programistyczna do optymalizacji za pomoc� algorytm�w PSO (particle swarm optimization).
* @par Praca dyplomowa magisterska
* @par POLITECHNIKA WARSZAWSKA
* @par Wydzia� Elektroniki i Technik Informacyjnych
* @par Instytut Automatyki
* @par Temat: �rodowisko programistyczne do optymalizacji przy wykorzystaniu algorytm�w inteligencji masowej.
* Praca wykonana pod kierunkiem
* Dr in�. Paw�a Wnuka
* @author Przemy�aw Olejniczak
* @date 2014.12.27
* @version 0.2.0
*/


/**
* The following code declares class Algorithm,
* which is base class for the concrete pso variant.
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemys�aw Olejniczak.
* @version 0.2.0
* @date <DATE>
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_ALGORITHM_HPP
#define PSOPP_ALGORITHM_HPP

#include <cmath>
#include <string>

namespace psopp
{
    /**
     *
     */
	template <class TSwarm, class TRandom>
    class SwarmHolder
    {
	protected:
        typedef typename TSwarm::particle_type particle_type;
        TSwarm swarm;
        TRandom random;
    };

    /**
     *
     */
    template <
        class TSwarm,
        template <class> class TVariant,
        template <class> class TEvaluator,
        template <class, class> class TInitializer,
        class TRandom
    >
    class Algorithm : public TVariant<SwarmHolder<TSwarm, TRandom>>
    {
        //typedef typename TRandom::seed_type seed_type;
        typedef typename TSwarm::particle_type particle_type;
        typedef typename TSwarm::domain_type domain_type;
    public:
       /**
        *
        */
        Algorithm()
        {
            initialize();
            this->Read();
        }

       /**
        *
        */
        int Start(std::size_t terminate_)
        {
            std::size_t step = 0;
            while (step++ < terminate_)
            {
                Step();
                if (std::fabs(this->swarm.worst().position.fitness - this->swarm.best().position.fitness) < 0.001) return step;
            }
            return step;
        }

       /**
        *
        */
        void Step()
        {
            for (std::size_t i = 0; i < this->swarm.size(); ++i)
                this->UpdateVelocity(this->swarm[i]);
            //swarm.check_velo();
            for (std::size_t i = 0; i < this->swarm.size(); ++i)
                UpdatePosition(this->swarm[i]);

            evaluate();
        }

       /**
        *
        */
        void UpdatePosition(particle_type& particle_)
        {
            particle_.position += particle_.velocity;
        }

    private:
        /**
        *
        */
        void evaluate()
        {
            for (auto& p : this->swarm)
            {
                evaluator(p->position);

                if (p->position.fitness < p->best_position.fitness)
                {
                    p->best_position = p->position;
                }
            }

            this->swarm.scored = false; // TODO: access
            this->swarm.minmax();
            this->swarm.update_neighborhoods();
        }

        /**
        *
        */
        void initialize()
        {
            for (auto& p : this->swarm)
            {
                initializer.InitPosition(p->position);
                p->best_position = p->position;
                evaluator(p->best_position);
                initializer.InitVelocity(p->velocity, p->position);
            }
            evaluate();
        }
	private:
        TRandom random;
        TEvaluator<domain_type> evaluator;
        TInitializer<TEvaluator<domain_type>, TRandom> initializer;
    };
}
#endif // PSOPP_ALGORITHM_HPP
