#include "XmlReader.hpp"
#include <boost/property_tree/xml_parser.hpp>
using namespace psopp;

namespace psopp
{
    XmlReader::XmlReader(const std::string& filename_)
    {
        boost::property_tree::xml_parser::read_xml(filename_, reader);
        reader = reader.get_child("optimization.algorithm.parameters");
    }
}
