/**
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
#ifndef PSOPP_GNUPLOT_HPP
#define PSOPP_GNUPLOT_HPP

#include <stdio.h>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
#define popen _popen
#define pclose _pclose
#endif

namespace psopp
{
    /**
    * The following code declares class gnuplot,
    */
    class gnuplot
    {
    public:
       /**
        * c'tor
        *
        */
        gnuplot()
        {
            pipe = popen("gnuplot -p > NULL 2>&1", "w");
        }
       /**
        * d'tor
        *
        */
        ~gnuplot()
        {
            command("exit");
            pclose(pipe);
        }
       /**
        *
        */
        bool valid() const { return pipe != 0; }
        /**
        *
        */
        void flush() { std::fflush(pipe); }
       /**
        *
        */
        gnuplot& operator << (const std::string& cmd_)
        {
            command(cmd_);
            return *this;
        }
    private:
       /**
        *
        */
        void command(const std::string& cmd_)
        {
            std::fprintf(pipe, (cmd_ + "\n").c_str());
            std::fflush(pipe);
        }
    private:
        std::FILE* pipe;
    };
}

#endif // PSOPP_GNUPLOT_HPP
