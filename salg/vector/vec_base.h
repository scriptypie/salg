/**
 * @file vec_base.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Base data types for vectors used in library
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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