#pragma once
#ifndef SALG_COMMON_COMPARATOR_H
#define SALG_COMMON_COMPARATOR_H

#include "scalar.h"

namespace salg
{

struct comparator
{
    inline static bool equal(const scalar& a, const scalar& b);
    inline static bool greater(const scalar& a, const scalar& b);
    inline static bool less(const scalar& a, const scalar& b);
};

}

#include "__impl/comparator.inl"

#endif