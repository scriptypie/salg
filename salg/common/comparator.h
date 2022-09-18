/**
 * @file comparator.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Used for fast approximated comparison with floating-point-units (32/64bit)
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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