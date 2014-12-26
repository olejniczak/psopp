/**
* @mainpage
* @par O PSO++:
* Biblioteka programistyczna do optymalizacji za pomoc¹ algorytmów PSO (particle swarm optimization).
* @par Praca dyplomowa magisterska
* @par POLITECHNIKA WARSZAWSKA
* @par Wydzia³ Elektroniki i Technik Informacyjnych
* @par Instytut Automatyki
* @par Temat: Œrodowisko programistyczne do optymalizacji przy wykorzystaniu algorytmów inteligencji masowej.
* Praca wykonana pod kierunkiem
* Dr in¿. Paw³a Wnuka
* @author Przemy³aw Olejniczak
* @date 2014.12.27
* @version 0.2.0
*/


/**
* The following code declares class Algorithm,
* which is base class for the concrete pso variant.
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
#ifndef PSOPP_ALGORITHM_HPP
#define PSOPP_ALGORITHM_HPP

#include <string>

namespace psopp
{
    /**
     *
     */
	template <class SWARM, class RNG>
    class SwarmHolder
    {
	protected:
        typedef typename SWARM::particle_type particle_type;
        SWARM swarm;
        RNG random;
    };

    /**
     *
     */
    template <
        class SWARM,
        template <class> class Type,
        template <class> class Evaluator,
        template <class> class Initializer,
        class RandomNumberGenerator
    >
    class Algorithm : public Type<SwarmHolder<SWARM, RandomNumberGenerator>>
    {
        typedef typename SWARM::particle_type particle_type;
        typedef typename SWARM::domain_type domain_type;
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
        int Start(int terminate_)
        {
            int step = 0;
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
            for (auto& p : swarm)
            {
                evaluator(p->position);

                if (p->position.fitness < p->best_position.fitness)
                {
                    p->best_position = p->position;
                }
            }

            swarm.scored = false; // TODO: access
            swarm.minmax();
            swarm.update_neighborhoods();
        }

        /**
        *
        */
        void initialize()
        {
            for (auto& p : swarm)
            {
                initializer.InitPosition(p->position);
                p->best_position = p->position;
                evaluator(p->best_position);
                initializer.InitVelocity(p->velocity, p->position);
            }
            evaluate();
        }
	private:
		RandomNumberGenerator random;
        Evaluator<domain_type> evaluator;
        Initializer<Evaluator<domain_type>> initializer;
    };
}
#endif // PSOPP_ALGORITHM_HPP
