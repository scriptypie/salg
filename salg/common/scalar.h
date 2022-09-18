/**
 * @file scalar.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Multibit primitive data type6 that may be both 32 and 64 bits. Also math functions for it.
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#ifndef SALG_COMMON_SCALAR_H
#define SALG_COMMON_SCALAR_H

namespace salg
{

#ifdef SALG_HIGH_PRECISION
using scalar = double;
using caster_t = long;
constexpr scalar EPSILON = 2.2204460492503131e-16;
#else
using scalar = float;
using caster_t = int;
constexpr scalar EPSILON = 1.19209290e-7F;
#endif

inline scalar fabs(const scalar& a);

inline scalar rsqrt(const scalar& a);

inline scalar sin(const scalar& a);

inline scalar cos(const scalar& a);

inline scalar tan(const scalar& a);

inline scalar atan2(const scalar& a, const scalar& b);

}

#include "__impl/scalar.inl"

#endif