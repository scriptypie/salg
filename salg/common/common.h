#pragma once
#ifndef SALG_COMMON_COMMON_H
#define SALG_COMMON_COMMON_H

#include "macros.h"
#include "scalar.h"
#include "scalar_array.h"
#include "comparator.h"

#include <ostream>

namespace salg
{

    using size_t = unsigned long;

    template<class T>
    inline constexpr T min(const T& a, const T& b)
    {
        if (a == b) return a;
        return (a < b) ? a : b;
    }

    template<class T>
    inline constexpr T max(const T& a, const T& b)
    {
        if (a == b) return a;
        return (a > b) ? a : b;
    }
    
}

#endif