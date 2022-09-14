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
struct mat_base<3, 3>
{
    inline static constexpr size_t NUMCOLS = 3;
    inline static constexpr size_t NUMROWS = 3;
    inline static constexpr size_t NUMELMS = 9;

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

    mat_base(
        const scalar& m00, const scalar& m01, const scalar& m02,
        const scalar& m10, const scalar& m11, const scalar& m12,
        const scalar& m20, const scalar& m21, const scalar& m22
    )
    {
        m[0][0] = m00; m[1][0] = m10; m[2][0] = m20;
        m[0][1] = m01; m[1][1] = m11; m[2][1] = m21;
        m[0][2] = m02; m[1][2] = m12; m[2][2] = m22;
    }

};

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

    mat_base(
        const scalar& m00, const scalar& m01, const scalar& m02, const scalar& m03,
        const scalar& m10, const scalar& m11, const scalar& m12, const scalar& m13,
        const scalar& m20, const scalar& m21, const scalar& m22, const scalar& m23,
        const scalar& m30, const scalar& m31, const scalar& m32, const scalar& m33
    )
    {
        m[0][0] = m00; m[1][0] = m10; m[2][0] = m20; m[3][0] = m30;
        m[0][1] = m01; m[1][1] = m11; m[2][1] = m21; m[3][1] = m31;
        m[0][2] = m02; m[1][2] = m12; m[2][2] = m22; m[3][2] = m32;
        m[0][3] = m03; m[1][3] = m13; m[2][3] = m23; m[3][3] = m33;
    }

};

}

#endif