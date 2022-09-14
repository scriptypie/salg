#pragma once
#ifndef SALG_MATRIX_MAT4_TYPE_H
#define SALG_MATRIX_MAT4_TYPE_H

#include "mat_base.h"

namespace salg
{

struct mat4 : mat_base<4, 4>
{
    mat4() = default;
    ~mat4() = default;

    mat4(
        const scalar& m00, const scalar& m01, const scalar& m02, const scalar& m03,
        const scalar& m10, const scalar& m11, const scalar& m12, const scalar& m13,
        const scalar& m20, const scalar& m21, const scalar& m22, const scalar& m23,
        const scalar& m30, const scalar& m31, const scalar& m32, const scalar& m33
    );
};

}

#include "__impl/mat4_type.inl"

#endif