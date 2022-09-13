#include "../vec2_func.h"

#include <cmath>

namespace salg
{

bool operator==(vec2 a, vec2 b)
{
    return 
    (
        comparator::equal(a.data[0], b.data[0]) &&
        comparator::equal(a.data[1], b.data[1])
    );
}

bool operator!=(vec2 a, vec2 b)
{
    return 
    (
        !comparator::equal(a.data[0], b.data[0]) &&
        !comparator::equal(a.data[1], b.data[1])
    );
}

bool operator>=(vec2 a, vec2 b)
{
    return 
    (
        a.data[0] >= b.data[0] &&
        a.data[1] >= b.data[1]
    );
}

bool operator<=(vec2 a, vec2 b)
{
    return 
    (
        a.data[0] <= b.data[0] &&
        a.data[1] <= b.data[1]
    );
}

bool operator<(vec2 a, vec2 b)
{
    return 
    (
        comparator::less(a.data[0], b.data[0]) &&
        comparator::less(a.data[1], b.data[1])
    );
}

bool operator>(vec2 a, vec2 b)
{
    return 
    (
        comparator::greater(a.data[0], b.data[0]) &&
        comparator::greater(a.data[1], b.data[1])
    );
}

vec2 max(vec2 a, vec2 b)
{
    return (a > b) ? a : b;
}

vec2 min(vec2 a, vec2 b)
{
    return (a < b) ? a : b;
}


scalar dot(vec2 a, vec2 b)
{
    return 
    (
        a.x * b.x + a.y * b.y
    );
}

scalar cross(vec2 a, vec2 b)
{
    return 
    (
        a.x * b.y - a.y * b.x
    );
}

scalar skew(vec2 a, vec2 b)
{
    return cross(a, b);
}

scalar length(vec2 a)
{
    return
    (
#ifdef SALG_HIGH_PRECISION
    std::sqrt(
        a.data[0] * a.data[0] +
        a.data[1] * a.data[1]
        )
#else
    std::sqrtf(
        a.data[0] * a.data[0] +
        a.data[1] * a.data[1]
        )
#endif
    );
}

scalar length2(vec2 a)
{
    return length(a) * length(a);
}

scalar distance(vec2 from, vec2 to)
{
    return length(
        {
            to.data[0] - from.data[0],
            to.data[1] - from.data[1]
        }
    );
}

vec2 normalize(vec2 a)
{
    scalar len = length(a);
    if (!len) return a;
    vec2 b(a);
    b *= (static_cast<scalar>(1) / len);
    return b;
}

scalar magnitude(vec2 a)
{
    return
    (
#ifdef SALG_HIGH_PRECISION
    std::sqrt(dot(a, a))
#else
    std::sqrtf(dot(a, a))
#endif
    );
}

scalar imagnitude(vec2 a)
{
    return
    (
#ifdef SALG_HIGH_PRECISION
    rsqrt(dot(a, a))
#else
    rsqrt(dot(a, a))
#endif
    );
}

vec2 floor(vec2 a)
{
    return 
    {
#ifdef SALG_HIGH_PRECISION
    std::floor(a.data[0]), std::floor(a.data[1])
#else
    std::floorf(a.data[0]), std::floorf(a.data[1])
#endif
    };
}

vec2 ceil(vec2 a)
{
    return 
    {
#ifdef SALG_HIGH_PRECISION
    std::ceil(a.data[0]), std::ceil(a.data[1])
#else
    std::ceilf(a.data[0]), std::ceilf(a.data[1])
#endif
    };
}

std::ostream& operator<<(std::ostream& os, salg::vec2 v)
{
    return 
    os << "(" 
    << v.data[0] 
    << ", " 
    << v.data[1] 
    << ")";
}

}
