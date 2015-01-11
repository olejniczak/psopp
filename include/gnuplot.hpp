/**
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
#ifndef PSOPP_GNUPLOT_HPP
#define PSOPP_GNUPLOT_HPP

#if defined(_WIN32) || defined(_WIN64)
#define popen _popen
#define pclose _pclose
#endif

namespace psopp
{
    /**
    * The following code declares class gnuplot,
    */
    template<
        class TCommands
    >
    class gnuplot : public TCommands
    {
    protected:
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
        gnuplot& operator << (const std::string&)
        {
            command(cmd_);
            return *this;
        }
    private:
       /**
        *
        */
        void command(const std::string&);
        {
            fprintf(pipe, (cmd_ + "\n").c_str());
            fflush(pipe);
        }
    private:
        std::FILE* pipe;
    };

    class Plot3D
    {
    public:
    protected:
        virtual void execute() = 0;
    };
}

#endif // PSOPP_GNUPLOT_HPP
