/**
*
* See http://przole.github.io/psopp for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version 0.2.0
* @date 2015.01.10
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_DUMP_HPP
#define PSOPP_DUMP_HPP

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace psopp
{
    template
    <
        class TParticle
    >
    struct DumpFile
    {
        void DumpDirectory(const std::string& directory_)
        {
            directory = directory_;
            std::cout << directory << std::endl;
        }
    protected:
        void Next(std::size_t step_) 
        {
            of.close();
            std::stringstream ss;
            ss << directory << "\\" << std::setfill('0') << std::setw(8) << step_ << ".pso";
            of.open(ss.str());
        }

        void Dump(const TParticle& particle)
        {
            for (auto p : particle.position.coordinates) of << p << "\t";
            for (auto v : particle.velocity.components) of << v << "\t";
            of << particle.position.fitness << std::endl;
        }
    private:
        std::ofstream of;
        std::string directory;
    };
}

#endif // PSOPP_SPHERE_HPP
