/**
*
* See http://przole.github.io/psopp for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version 0.2.0
* @date 2014.12.29
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_MAPREADER_HPP
#define PSOPP_MAPREADER_HPP

#include <map>

namespace psopp
{
    class MapReader
    {
        static std::map<std::string, double> create_map()
        {
            std::map<std::string, double> m;
            m["inertia_weight"] = 0.4;
            m["particle_learn"] = 2;
            m["swarm_learn"] = 2;
            return m;
        }
        static const std::map<std::string, double> myMap;
    public:
        template <class T>
        T get(const char* name_) const
        {
            auto d = myMap.find(name_);
            return (T)d->second;
        }
    };

    const std::map<std::string, double> MapReader::myMap = MapReader::create_map();
}

#endif //PSOPP_MAPREADER_HPP