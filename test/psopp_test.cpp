/**
* The following code implements the unit test,
* pso++ programming library for optimization.
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

#define BOOST_TEST_MODULE psopp
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(psopp_test_suite)

BOOST_AUTO_TEST_CASE(test_sum_position_velocity)
{
    BOOST_ERROR( "Error: position + velocity" );
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE( test_case_on_file_scope )
{
    BOOST_CHECK( true );
}

BOOST_AUTO_TEST_SUITE(psopp_test_suite)

BOOST_AUTO_TEST_CASE( test_case2 )
{
    BOOST_ERROR( "some error 2" );
}

BOOST_AUTO_TEST_SUITE_END()