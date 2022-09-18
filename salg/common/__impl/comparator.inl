#include "../comparator.h"

namespace salg
{

bool comparator::equal(const scalar& a, const scalar& b)
{
    return salg::fabs(a - b) < EPSILON;
}

bool comparator::greater(const scalar& a, const scalar& b)
{
    scalar fabs_a = salg::fabs(a);
    scalar fabs_b = salg::fabs(b);
    return (a - b) > ( (fabs_a < fabs_b ? fabs_b : fabs_a) * EPSILON);
}

bool comparator::less(const scalar& a, const scalar& b)
{
    scalar fabs_a = salg::fabs(a);
    scalar fabs_b = salg::fabs(b);
    return (b - a) > ( (fabs_a < fabs_b ? fabs_b : fabs_a) * EPSILON);
}

}
