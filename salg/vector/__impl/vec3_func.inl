#include "../vec3/vec3_func.h"

#include <cmath>

namespace salg
{

bool operator==(vec3 a, vec3 b)
{
    return 
    (
        comparator::equal(a.data[0], b.data[0]) &&
        comparator::equal(a.data[1], b.data[1]) &&
        comparator::equal(a.data[2], b.data[2])
    );
}

bool operator!=(vec3 a, vec3 b)
{
    return 
    (
        !comparator::equal(a.data[0], b.data[0]) &&
        !comparator::equal(a.data[1], b.data[1]) &&
        !comparator::equal(a.data[2], b.data[2])
    );
}

bool operator>=(vec3 a, vec3 b)
{
    return 
    (
        a.data[0] >= b.data[0] &&
        a.data[1] >= b.data[1] &&
        a.data[2] >= b.data[2]
    );
}

bool operator<=(vec3 a, vec3 b)
{
    return 
    (
        a.data[0] <= b.data[0] &&
        a.data[1] <= b.data[1] &&
        a.data[2] <= b.data[2]
    );
}

bool operator<(vec3 a, vec3 b)
{
    return 
    (
        comparator::less(a.data[0], b.data[0]) &&
        comparator::less(a.data[1], b.data[1]) &&
        comparator::less(a.data[2], b.data[2])
    );
}

bool operator>(vec3 a, vec3 b)
{
    return 
    (
        comparator::greater(a.data[0], b.data[0]) &&
        comparator::greater(a.data[1], b.data[1]) &&
        comparator::greater(a.data[2], b.data[2])
    );
}

vec3 max(vec3 a, vec3 b)
{
    return (a > b) ? a : b;
}

vec3 min(vec3 a, vec3 b)
{
    return (a < b) ? a : b;
}

scalar dot(vec3 a, vec3 b)
{
    return 
    (
        a.x * b.x + a.y * b.y + a.z * b.z
    );
}

vec3 cross(vec3 a, vec3 b)
{
    return 
    (
        vec3{
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z, 
            a.x * b.y - a.y * b.x
        }
    );
}

vec3 project(vec3 a, vec3 b)
{
    return
    (
        b * dot(a, b)
    );
}

vec3 reject(vec3 a, vec3 b)
{
    return
    (
        a - b * dot(a, b)
    );
}

scalar length(vec3 a)
{
    return
    (
#ifdef SALG_HIGH_PRECISION
    std::sqrt(
        a.data[0] * a.data[0] +
        a.data[1] * a.data[1] +
        a.data[2] * a.data[2]
        )
#else
    std::sqrtf(
        a.data[0] * a.data[0] +
        a.data[1] * a.data[1] +
        a.data[2] * a.data[2]
        )
#endif
    );
}

scalar length2(vec3 a)
{
    return length(a) * length(a);
}

scalar distance(vec3 from, vec3 to)
{
    return length(
        vec3{
            to.data[0] - from.data[0],
            to.data[1] - from.data[1],
            to.data[2] - from.data[2]
        }
    );
}

vec3 normalize(vec3 a)
{
    scalar len = length(a);
    if (!len) return a;
    vec3 b(a);
    b *= (static_cast<scalar>(1) / len);
    return b;
}

scalar magnitude(vec3 a)
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

scalar magnitude2(vec3 a)
{
    return
    (
        dot(a, a)
    );
}

scalar imagnitude(vec3 a)
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

vec3 floor(vec3 a)
{
    return 
    {
#ifdef SALG_HIGH_PRECISION
    std::floor(a.data[0]), std::floor(a.data[1]), std::floor(a.data[2])
#else
    std::floorf(a.data[0]), std::floorf(a.data[1]), std::floorf(a.data[2])
#endif
    };
}

vec3 ceil(vec3 a)
{
    return 
    {
#ifdef SALG_HIGH_PRECISION
    std::ceil(a.data[0]), std::ceil(a.data[1]), std::ceil(a.data[2])
#else
    std::ceilf(a.data[0]), std::ceilf(a.data[1]), std::ceilf(a.data[2])
#endif
    };
}

std::ostream& operator<<(std::ostream& os, salg::vec3 v)
{
    return 
    os << "(" 
    << v.data[0] 
    << ", " 
    << v.data[1] 
    << ")";
}

}
