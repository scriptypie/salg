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
        union 
        {
            struct 
            {
                scalar x;
            };
            scalar data[1] = {};
        };
    };

    template<>
    struct vec_base<2>
    {
        union 
        {
            struct {
                scalar x, y;
            };
            scalar data[2] = {};
        };
    };

    template<>
    struct vec_base<3>
    {
        union 
        {
            struct {
                scalar x, y, z;
            };
            scalar data[3] = {};
        };
    };

    template<>
    struct vec_base<4>
    {
        union 
        {
            struct {
                scalar x, y, z, w;
            };
            scalar data[4] = {};
        };
    };

}

#endif