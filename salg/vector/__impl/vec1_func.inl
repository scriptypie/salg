#include "../vec1/vec1_func.h"

namespace salg
{

bool operator==(const vec1& a, const vec1& b)
{
    return 
    (
        comparator::equal(a.data[0], b.data[0])
    );
}

bool operator!=(const vec1& a, const vec1& b)
{
    return 
    (
        !comparator::equal(a.data[0], b.data[0])
    );
}

bool operator>=(const vec1& a, const vec1& b)
{
    return 
    (
        a.data[0] >= b.data[0]
    );
}

bool operator<=(const vec1& a, const vec1& b)
{
    return 
    (
        a.data[0] <= b.data[0]
    );
}

bool operator<(const vec1& a, const vec1& b)
{
    return 
    (
        comparator::less(a.data[0], b.data[0])
    );
}

bool operator>(const vec1& a, const vec1& b)
{
    return 
    (
        comparator::greater(a.data[0], b.data[0])
    );
}

std::ostream& operator<<(std::ostream& os, const salg::vec1& v)
{
    return
    os << "("
    << v.data[0]
    << ")";
}

}
