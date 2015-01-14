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
#ifndef PSOPP_PLOT_GEN_HPP
#define PSOPP_PLOT_GEN_HPP

#include <initializer_list>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "gnuplot.hpp"

namespace psopp
{
    /**
    * @class MultiPlot
    */
    struct MultiPlot
    {
        MultiPlot(std::size_t problems_count_, std::size_t params_count_)
            : problems_count(problems_count_), params_count(params_count_)
        {
        }

        void Generate(const std::string& directory_, std::initializer_list<std::string> problems_, std::initializer_list<std::string> params_)
        {
            of.open(directory_ + "\\plot.plt");
            if (problems_.size() != problems_count || params_.size() != params_count) return;
            if (!gplot.valid()) return;
            
            std::string dir = "cd '";
            dir += directory_ + "'";
            put(dir);
            put("set terminal jpeg large font arial size 1200, 1800");
            put("set output \"plot.jpg\"");
            put("set multiplot layout 4, 1");
            put("set lmargin at screen 0.1");
            put("set yrange[] reverse");

            size_t p = problems_count - 1;
            for (auto ip = problems_.begin(); ip != problems_.end(); ++ip)
            {
                std::string title = "set title \"";
                title += *ip + "\"";
                put(title);
                std::stringstream ss;
                ss << "plot ";
                size_t t = params_count + 1;
                for (auto it = params_.begin(); it != params_.end(); ++it)
                {
                    ss << "'" << std::setfill('0') << std::setw(2) << p << ".dat' using 1:" << t-- << " with line title \"" << *it << "\", ";
                }
                --p;
                auto str = ss.str();
                put(str.substr(0, str.length() - 2));
            }
            put("unset multiplot");
        }

        void put(const std::string& cmd_)
        {
            of << cmd_ << std::endl;
            gplot << cmd_;
        }

        gnuplot gplot;
        std::ofstream of;

        std::size_t problems_count;
        std::size_t params_count;
    };

}

#endif // PSOPP_PLOT_GEN_HPP
