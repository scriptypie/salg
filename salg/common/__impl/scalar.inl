#include "../scalar.h"

#include <cmath> // sin(), sinf(), cos(), cosf(), tan(), tanf(), atan2(), atan2f()

namespace salg
{

scalar fabs(const scalar& a)
{
    caster_t tmp = *(caster_t*)&a;
#ifdef SALG_HIGH_PRECISION
    tmp &= 0x7fffffffffffffff;
#else
    tmp &= 0x7fffffff;
#endif
    return *(scalar*)&tmp;
}

scalar rsqrt(const scalar& a)
{
    caster_t i = *reinterpret_cast<caster_t*>(&const_cast<scalar&>(a));
#ifdef SALG_HIGH_PRECISION
    i = 0x5fe6eb50c7b537a9 - (i >> 1);
#else
    i = 0x5f3759df - (i >> 1);
#endif
    scalar b = *reinterpret_cast<scalar*>(&i);
    return b * (1.5f - 0.5f * a * b * b);
}

scalar sin(const scalar& a)
{
    return 
    (
#ifdef SALG_HIGH_PRECISION
    std::sin(a)
#else
    std::sinf(a)
#endif
    );
}

scalar cos(const scalar& a)
{
    return 
    (
#ifdef SALG_HIGH_PRECISION
    std::cos(a)
#else
    std::cosf(a)
#endif
    );
}

scalar tan(const scalar& a)
{
    return 
    (
#ifdef SALG_HIGH_PRECISION
    std::tan(a)
#else
    std::tanf(a)
#endif
    );
}

scalar atan2(const scalar& a, const scalar& b)
{
    return 
    (
#ifdef SALG_HIGH_PRECISION
    std::atan2(a, b)
#else
    std::atan2f(a, b)
#endif
    );
}

}
