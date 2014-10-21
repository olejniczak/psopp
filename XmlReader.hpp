/**
*
* See <WEBSITE> for documentation.
*
* @author Copyright &copy 2011 Przemys³aw Olejniczak.
* @version <VERSION>
* @date <DATE>
*
* Distributed under the Boost Software License, Version 1.0.
* (See accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
*/
#ifndef PSOPP_XMLREADER_HPP
#define PSOPP_XMLREADER_HPP

#include <boost\property_tree\ptree.hpp>

namespace psopp
{
    class XmlReader
    {
    public:
        XmlReader(const std::string& filename_);
        template <class T>
        T get(const char* name_) const
        {
            return reader.get<T>(name_);
        }
    private:
        boost::property_tree::ptree reader;
    };
}

#endif //PSOPP_XMLREADER_HPP