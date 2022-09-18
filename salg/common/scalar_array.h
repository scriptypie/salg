#pragma once
#ifndef SALG_COMMON_SCALAR_ARRAY_H
#define SALG_COMMON_SCALAR_ARRAY_H

#include "scalar.h"

namespace salg
{

    template<size_t SIZE>
    struct scalar_array
    {
        scalar data[SIZE] = {};

        inline scalar_array() = default;
        inline scalar_array(scalar_array&&) = default;
        inline scalar_array(const scalar_array&) = default;
        inline scalar_array& operator=(scalar_array&&) = default;
        inline scalar_array& operator=(const scalar_array&) = default;
        inline ~scalar_array() = default;
        inline scalar_array(scalar _data[SIZE]) : data(_data) {}

        scalar& operator[](size_t n) { return data[n]; }
        const scalar& operator[](size_t n) const { return data[n]; }

    };

}

#endif