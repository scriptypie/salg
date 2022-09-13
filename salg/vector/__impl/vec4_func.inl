#include "../vec4_func.h"

#include <cmath>

namespace salg
{

bool operator==(vec4 a, vec4 b)
{
    return 
    (
        comparator::equal(a.data[0], b.data[0]) &&
        comparator::equal(a.data[1], b.data[1]) &&
        comparator::equal(a.data[2], b.data[2]) &&
        comparator::equal(a.data[3], b.data[3])
    );
}

bool operator!=(vec4 a, vec4 b)
{
    return 
    (
        !comparator::equal(a.data[0], b.data[0]) &&
        !comparator::equal(a.data[1], b.data[1]) &&
        !comparator::equal(a.data[2], b.data[2]) &&
        !comparator::equal(a.data[3], b.data[3])
    );
}

bool operator>=(vec4 a, vec4 b)
{
    return 
    (
        a.data[0] >= b.data[0] &&
        a.data[1] >= b.data[1] &&
        a.data[2] >= b.data[2] &&
        a.data[3] >= b.data[3]
    );
}

bool operator<=(vec4 a, vec4 b)
{
    return 
    (
        a.data[0] <= b.data[0] &&
        a.data[1] <= b.data[1] &&
        a.data[2] <= b.data[2] &&
        a.data[3] <= b.data[3]
    );
}

bool operator<(vec4 a, vec4 b)
{
    return 
    (
        comparator::less(a.data[0], b.data[0]) &&
        comparator::less(a.data[1], b.data[1]) &&
        comparator::less(a.data[2], b.data[2]) &&
        comparator::less(a.data[3], b.data[3])
    );
}

bool operator>(vec4 a, vec4 b)
{
    return 
    (
        comparator::greater(a.data[0], b.data[0]) &&
        comparator::greater(a.data[1], b.data[1]) &&
        comparator::greater(a.data[2], b.data[2]) &&
        comparator::greater(a.data[3], b.data[3])
    );
}

vec4 max(vec4 a, vec4 b)
{
    return (a > b) ? a : b;
}

vec4 min(vec4 a, vec4 b)
{
    return (a < b) ? a : b;
}

scalar dot(vec4 a, vec4 b)
{
    return 
    (
        a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w
    );
}

scalar dot(vec4 a, vec3 b)
{
    return 
    (
        a.x * b.x + a.y * b.y + a.z * b.z
    );
}

scalar dot(vec3 a, vec4 b)
{
    return 
    (
        a.x * b.x + a.y * b.y + a.z * b.z
    );
}

scalar dot(vec4 a, vec2 b)
{
    return 
    (
        a.x * b.x + a.y * b.y
    );
}

scalar dot(vec2 a, vec4 b)
{
    return 
    (
        a.x * b.x + a.y * b.y
    );
}

vec4 project(vec4 a, vec4 b)
{
    return
    (
        b * dot(a, b)
    );
}

vec4 reject(vec4 a, vec4 b)
{
    return
    (
        a - b * dot(a, b)
    );
}

scalar length(vec4 a)
{
    return
    (
#ifdef SALG_HIGH_PRECISION
    std::sqrt(
        a.data[0] * a.data[0] +
        a.data[1] * a.data[1] +
        a.data[2] * a.data[2] +
        a.data[3] * a.data[3]
        )
#else
    std::sqrtf(
        a.data[0] * a.data[0] +
        a.data[1] * a.data[1] +
        a.data[2] * a.data[2] +
        a.data[3] * a.data[3]
        )
#endif
    );
}

scalar length2(vec4 a)
{
    return length(a) * length(a);
}

vec4 normalize(vec4 a)
{
    scalar len = length(a);
    if (!len) return a;
    vec4 b(a);
    b *= (static_cast<scalar>(1) / len);
    return b;
}

scalar magnitude(vec4 a)
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

scalar magnitude2(vec4 a)
{
    return
    (
        dot(a, a)
    );
}

scalar imagnitude(vec4 a)
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

vec4 floor(vec4 a)
{
    return 
    {
#ifdef SALG_HIGH_PRECISION
    std::floor(a.data[0]), std::floor(a.data[1]), std::floor(a.data[2]), std::floor(a.data[3])
#else
    std::floorf(a.data[0]), std::floorf(a.data[1]), std::floorf(a.data[2]), std::floorf(a.data[3])
#endif
    };
}

vec4 ceil(vec4 a)
{
    return 
    {
#ifdef SALG_HIGH_PRECISION
    std::ceil(a.data[0]), std::ceil(a.data[1]), std::ceil(a.data[2]), std::ceil(a.data[3])
#else
    std::ceilf(a.data[0]), std::ceilf(a.data[1]), std::ceilf(a.data[2]), std::ceilf(a.data[3])
#endif
    };
}

std::ostream& operator<<(std::ostream& os, salg::vec4 v)
{
    return 
    os << "(" 
    << v.data[0] 
    << ", " 
    << v.data[1] 
    << ", " 
    << v.data[2] 
    << ", " 
    << v.data[3] 
    << ")";
}

}
