/**
 * The following code implements the unit test,
 * pso++ programming library for optimization.
 *
 * See http://przole.github.io/psopp for documentation.
 *
 * @author Copyright &copy 2011 Przemys³aw Olejniczak.
 * @version 0.2.0
 * @date 2015.01.14
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 */

#define BOOST_TEST_MODULE psopp
#include <boost/test/included/unit_test.hpp>

#include "OptiSuite.hpp"

namespace psopp {

    namespace test {
        
        const double EPS = 0.001;

        bool EQ(double a, double b, double eps = EPS) { return std::fabs(a - b) < eps; }

        /**
         * Test suite for the R domain class
         * test cases for operations between position and velocity
         */
        BOOST_AUTO_TEST_SUITE(psopp_domain_R)

            BOOST_AUTO_TEST_CASE(test_sum_position_velocity)
            {
                R2::position_type pos;
                R2::velocity_type vel;

                pos.coordinates[0] = 1.0;
                pos.coordinates[1] = 1.0;

                vel.components[0] = 5.0;
                vel.components[1] = 5.0;

                pos += vel;
                BOOST_CHECK(EQ(pos.coordinates[0], 6.0) && EQ(pos.coordinates[1], 6.0));
            }

            BOOST_AUTO_TEST_CASE(test_sum_velocity_velocity)
            {
                R2::velocity_type vel1;
                R2::velocity_type vel2;
                vel1.components[0] = 5.0;
                vel1.components[1] = 5.0;

                vel2.components[0] = 5.0;
                vel2.components[1] = 5.0;

                vel1 += vel2;
                BOOST_CHECK(EQ(vel1.components[0], 10.0) && EQ(vel1.components[1], 10.0));
            }

            BOOST_AUTO_TEST_CASE(test_mul_velocity)
            {
                R2::velocity_type vel;
                vel.components[0] = 5.0;
                vel.components[1] = 5.0;

                vel *= 5.0;
                BOOST_CHECK(EQ(vel.components[0], 25.0) && EQ(vel.components[1], 25.0));
            }

            BOOST_AUTO_TEST_CASE(test_pos_minus_pos)
            {
                R2::position_type pos1;
                R2::position_type pos2;

                pos1.coordinates[0] = 5.0;
                pos1.coordinates[1] = 5.0;

                pos2.coordinates[0] = 10.0;
                pos2.coordinates[1] = 10.0;

                R2::velocity_type vel = pos1 - pos2;
                BOOST_CHECK(EQ(vel.components[0], -5.0) && EQ(vel.components[1], -5.0));
            }
        
        BOOST_AUTO_TEST_SUITE_END() // psopp_domain_R
        
        /**
         * Test suite for the problem policies
         */
        BOOST_AUTO_TEST_SUITE(psopp_test_problems)

            const std::size_t dim = 7;

            typedef psopp::R<dim> RN;

            RN::position_type position;
            /**
             * Test case sphere function
             */
            BOOST_AUTO_TEST_CASE(test_problem_sphere)
            {
                Sphere<RN> sphere;

                for (std::size_t i = 0; i < RN::Size; ++i)
                    position.coordinates[i] = 0;
            
                sphere(position);
            
                BOOST_CHECK(EQ(position.fitness, 0.0));
            }

            BOOST_AUTO_TEST_CASE(test_problem_rosenbrock)
            {
                Rosenbrock<RN> rosenbrock;

                for (std::size_t i = 0; i < RN::Size; ++i)
                    position.coordinates[i] = 1;

                rosenbrock(position);

                BOOST_CHECK(EQ(position.fitness, 0.0));
            }

            BOOST_AUTO_TEST_CASE(test_problem_ackley)
            {
                Ackley1<RN> ackley1;

                for (std::size_t i = 0; i < RN::Size; ++i)
                    position.coordinates[i] = 0;

                ackley1(position);

                BOOST_CHECK(EQ(position.fitness, 0.0));
            }

            BOOST_AUTO_TEST_CASE(test_problem_styblinski_tang)
            {
                StyblinskiTang<RN> st;

                for (std::size_t i = 0; i < RN::Size; ++i)
                    position.coordinates[i] = -2.903534;

                st(position);

                BOOST_CHECK(EQ(position.fitness, -39.16599 * RN::Size, 0.01));
            }

        BOOST_AUTO_TEST_SUITE_END() // psopp_test_problems

    } // namespace test

} // namespace psopp