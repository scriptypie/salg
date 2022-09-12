#pragma once
#ifndef SALG_COMMON_SCALAR_H
#define SALG_COMMON_SCALAR_H

namespace salg
{

#ifdef SALG_HIGH_PRECISION
using scalar = double;
using caster_t = long;
constexpr scalar EPSILON = __DBL_EPSILON__;
#else
using scalar = float;
using caster_t = int;
constexpr scalar EPSILON = __FLT_EPSILON__;
#endif

inline scalar fabs(const scalar& a);

}

#include "__impl/scalar.inl"

#endif