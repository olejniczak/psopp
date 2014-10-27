#include "Topology.hpp"

#include <vector>

using namespace std;
using namespace psopp;

Topology::Neighborhoods::Neighborhoods(size_t count_)
    : neighborhoods(count_)
{
}

const size_t Topology::Neighborhoods::Count() const
{
    return neighborhoods.size();
}

const Topology::Neighborhoods::Neighborhood& Topology::Neighborhoods::operator[](size_t index_) const
{
    return neighborhoods[index_];
}

Topology::Neighborhoods::Neighborhood& Topology::Neighborhoods::operator[](size_t index_)
{
    return neighborhoods[index_];
}

const size_t Topology::Neighborhoods::Neighborhood::Count() const
{
    return indexes.size();
}

void Topology::Neighborhoods::Neighborhood::Add(size_t index_)
{
    indexes.push_back(index_);
}

void Topology::Neighborhoods::Neighborhood::Set(size_t index_)
{
    swap(indexes[0], indexes[index_]);
}

size_t Topology::Neighborhoods::Neighborhood::operator[] (size_t index_) const
{
    return indexes[index_];
}


Topology::Topology(size_t count_)
    : neighborhoods(count_)
{
}
