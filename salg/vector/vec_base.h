#pragma once
#ifndef SALG_VEC_BASE
#define SALG_VEC_BASE

#include "../common/common.h"

namespace salg
{

    template<size_t N> struct vec_base;

    template<size_t SIZE>
    struct vec_data
    {
        scalar data[SIZE] = {};

        inline vec_data() = default;
        inline vec_data(vec_data&&) = default;
        inline vec_data(const vec_data&) = default;
        inline vec_data& operator=(vec_data&&) = default;
        inline vec_data& operator=(const vec_data&) = default;
        inline ~vec_data() = default;
        inline vec_data(scalar _data[SIZE]) : data(_data) {}

        scalar& operator[](size_t n) { return data[n]; }
        const scalar& operator[](size_t n) const { return data[n]; }

    };

    template<>
    struct vec_base<1>
    {
        enum {EXNUM = 1};
        union 
        {
            struct 
            {
                scalar x;
            };
            vec_data<EXNUM> data = {};
        };

        vec_base() = default;
        vec_base(const scalar _data[EXNUM])
        {
            for (short i = 0; i < EXNUM; i++)
                data[i] = _data[i];
        }
    };

    template<>
    struct vec_base<2>
    {
        enum {EXNUM = 2};
        union 
        {
            struct {
                scalar x, y;
            };
            vec_data<EXNUM> data = {};
        };

        vec_base() = default;
        vec_base(const scalar _data[EXNUM])
        {
            for (short i = 0; i < EXNUM; i++)
                data[i] = _data[i];
        }
    };

    template<>
    struct vec_base<3>
    {
        enum {EXNUM = 3};
        union 
        {
            struct {
                scalar x, y, z;
            };
            vec_data<EXNUM> data = {};
        };

        vec_base() = default;
        vec_base(const scalar _data[EXNUM])
        {
            for (short i = 0; i < EXNUM; i++)
                data[i] = _data[i];
        }
    };

    template<>
    struct vec_base<4>
    {
        enum {EXNUM = 4};
        union 
        {
            struct {
                scalar x, y, z, w;
            };
            vec_data<EXNUM> data = {};
        };

        vec_base() = default;
        vec_base(const scalar _data[EXNUM])
        {
            for (short i = 0; i < EXNUM; i++)
                data[i] = _data[i];
        }
    };

}

#endif