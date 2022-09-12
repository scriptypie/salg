#include "../comparator.h"

namespace salg
{

bool comparator::equal(const scalar& a, const scalar& b)
{
    return salg::fabs(a - b) < EPSILON;
}

bool comparator::greater(const scalar& a, const scalar& b)
{
    return (a - b) > ( (salg::fabs(a) < salg::fabs(b) ? salg::fabs(b) : salg::fabs(a)) * EPSILON);
}

bool comparator::less(const scalar& a, const scalar& b)
{
    return (b - a) > ( (salg::fabs(a) < salg::fabs(b) ? salg::fabs(b) : salg::fabs(a)) * EPSILON);
}

}
