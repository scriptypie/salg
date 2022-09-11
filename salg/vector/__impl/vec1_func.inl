#include "../vec1/vec1_func.h"

namespace salg
{

bool operator==(const vec1& a, const vec1& b)
{
    return 
    (
        a.storage.data[0] == b.storage.data[0]
    );
}

bool operator!=(const vec1& a, const vec1& b)
{
    return 
    (
        a.storage.data[0] != b.storage.data[0]
    );
}

bool operator>=(const vec1& a, const vec1& b)
{
    return 
    (
        a.storage.data[0] >= b.storage.data[0]
    );
}

bool operator<=(const vec1& a, const vec1& b)
{
    return 
    (
        a.storage.data[0] <= b.storage.data[0]
    );
}

bool operator<(const vec1& a, const vec1& b)
{
    return 
    (
        a.storage.data[0] < b.storage.data[0]
    );
}

bool operator>(const vec1& a, const vec1& b)
{
    return 
    (
        a.storage.data[0] > b.storage.data[0]
    );
}


}
