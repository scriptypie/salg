#pragma once
#ifndef SALG_VEC_BASE
#define SALG_VEC_BASE

#include "../common/common.h"

namespace salg
{

    template<size_t N> struct vec_base;

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

    template<>
    struct vec_base<1>
    {
        inline static constexpr size_t DIM = {1};
        union 
        {
            struct 
            {
                scalar x;
            };
            scalar_array<DIM> data = {};
        };

        vec_base() = default;
        ~vec_base() = default;
        vec_base(const scalar _data[DIM])
        {
            for (short i = 0; i < DIM; i++)
                data[i] = _data[i];
        }
    };

    template<>
    struct vec_base<2>
    {
        inline static constexpr size_t DIM = {2};
        union 
        {
            struct {
                scalar x, y;
            };
            scalar_array<DIM> data = {};
        };

        vec_base() = default;
        ~vec_base() = default;
        vec_base(const scalar _data[DIM])
        {
            for (short i = 0; i < DIM; i++)
                data[i] = _data[i];
        }
    };

    template<>
    struct vec_base<3>
    {
        inline static constexpr size_t DIM = {3};
        union 
        {
            struct {
                scalar x, y, z;
            };
            scalar_array<DIM> data = {};
        };

        vec_base() = default;
        ~vec_base() = default;
        vec_base(const scalar _data[DIM])
        {
            for (short i = 0; i < DIM; i++)
                data[i] = _data[i];
        }
    };

    template<>
    struct vec_base<4>
    {
        inline static constexpr size_t DIM = {4};
        union 
        {
            struct {
                scalar x, y, z, w;
            };
            scalar_array<DIM> data = {};
        };

        vec_base() = default;
        ~vec_base() = default;
        vec_base(const scalar _data[DIM])
        {
            for (short i = 0; i < DIM; i++)
                data[i] = _data[i];
        }
    };

}

#endif