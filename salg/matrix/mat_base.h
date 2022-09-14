#pragma once
#ifndef SALG_MATRIX_MAT_BASE_H
#define SALG_MATRIX_MAT_BASE_H

#include "../common/common.h"
#include "../vector/vec_base.h"

namespace salg
{

//              |         -
template<size_t C, size_t R> struct mat_base;

template<>
struct mat_base<4, 4>
{
    inline static constexpr size_t NUMCOLS = 4 ;
    inline static constexpr size_t NUMROWS = 4 ;
    inline static constexpr size_t NUMELMS = 16;

    union
    {
        scalar m[NUMROWS][NUMCOLS];
        scalar_array<NUMELMS> data = {};
    };

    mat_base()
    {
        for (short i = 0; i < min(NUMROWS, NUMCOLS); i++)
            m[i][i] = 1;
    }



};

}

#endif