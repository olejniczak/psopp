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
#ifndef PSOPP_REPORT_GEN_HPP
#define PSOPP_REPORT_GEN_HPP

#include <fstream>
#include <vector>

namespace psopp
{
    /**
    * Helper function - number to string
    */
    std::string SubDirectory(std::size_t num_, std::size_t width_ = 2)
    {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(width_) << num_;
        return ss.str();
    }

    /**
    * @class ConvergencePlot
    */
    struct ConvergencePlot
    {
        ConvergencePlot(std::size_t problems_count_, std::size_t params_count_, std::size_t step_count_)
            : problems_count(problems_count_), params_count(params_count_), step_count(step_count_)
        {
            data.resize(problems_count, std::vector<std::vector<double>>(params_count_, std::vector<double>(step_count_)));
        }

        void Generate(const std::string& directory_, const std::string& report_dir_)
        {
            for (std::size_t p = 0; p < problems_count; ++p)
            {
                for (std::size_t t = 0; t < params_count; ++t)
                {
                    for (std::size_t s = 1; s <= step_count; ++s)
                    {
                        std::string file_path = directory_ + "\\P" + SubDirectory(p) 
                                                           + "\\T" + SubDirectory(t)
                                                           + "\\" + SubDirectory(s, 8) + ".pso";
                        std::ifstream swarm_file(file_path);
                        std::string line;
                        std::getline(swarm_file, line);
                        unsigned found = line.find_last_of('\t');
                        if (found != std::string::npos)
                        {
                            data[p][t][s - 1] = std::atof(line.substr(found).c_str());
                        }
                    }
                }
            }


            for (std::size_t p = 0; p < problems_count; ++p)
            {
                std::string file_path = directory_ + "\\" + report_dir_ + "\\" + SubDirectory(p) + ".dat";
                std::ofstream output_file(file_path);
                
                for (std::size_t s = 1; s <= step_count; ++s)
                {
                    std::stringstream ss;
                    ss << s << "\t";
                    for (std::size_t t = 0; t < params_count; ++t)
                    {
                        ss << data[p][t][s - 1] << "\t";
                    }
                    output_file << ss.str() << std::endl;
                }
            }
        }

        std::vector<std::vector<std::vector<double>>> data;
        std::size_t problems_count;
        std::size_t params_count;
        std::size_t step_count;
    };

}

#endif // PSOPP_REPORT_GEN_HPP
