#pragma once
#ifndef SALG_VEC_BASE
#define SALG_VEC_BASE

#include "../common/common.h"

namespace salg
{

    template<size_t N> struct vec_base;

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
            scalar data[1] = {};
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
            scalar data[2] = {};
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
            scalar data[3] = {};
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
            scalar data[4] = {};
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