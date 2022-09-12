#include "../scalar.h"

namespace salg
{

scalar fabs(const scalar& a)
{
    caster_t tmp = *(caster_t*)&a;
#ifdef SALG_HIGH_PRECISION
    tmp &= 0x7fffffffffffffff;
#else
    tmp &= 0x7FFFFFFF;
#endif
    return *(scalar*)&tmp;
}

}
