#pragma once
#ifndef SALG_MATRIX_MAT4_FUNC_H
#define SALG_MATRIX_MAT4_FUNC_H

#include "mat4_type.h"
#include "../common/transform_component.h"

namespace salg
{

    inline bool operator==(mat4 a, mat4 b);
    inline bool operator!=(mat4 a, mat4 b);
    inline bool operator>=(mat4 a, mat4 b);
    inline bool operator<=(mat4 a, mat4 b);
    inline bool operator<(mat4 a, mat4 b);
    inline bool operator>(mat4 a, mat4 b);

    inline mat4 max(mat4 a, mat4 b);
    inline mat4 min(mat4 a, mat4 b);

    inline mat4 translate(vec3 translation);    
    inline vec3 getTranslation(mat4 m);
    inline vec3 getScale(mat4 m);
    inline transform_component decompose(mat4 m);
    inline void orthoNormalize(mat4& m);
    inline mat4 transpose(mat4 m);
    inline mat4 scale(vec3 s);    
    inline mat4 rotateX(const scalar& angle);
    inline mat4 rotateY(const scalar& angle);
    inline mat4 rotateZ(const scalar& angle);
    inline mat4 rotate(const scalar& r, const scalar& i, const scalar& j, const scalar& k);
    inline mat4 frustrum(scalar bottom, scalar top, scalar left, scalar right, scalar near, scalar far);
    inline mat4 perspectiveRH(scalar fovY, scalar aspect, scalar near, scalar far);
    inline mat4 perspectiveLH(scalar fovY, scalar aspect, scalar near, scalar far);   
    inline mat4 orthographicRH(scalar left, scalar right, scalar bottom, scalar top, scalar near, scalar far);
    inline mat4 orthographicLH(scalar left, scalar right, scalar bottom, scalar top, scalar near, scalar far);   
    inline mat4 lookAt(vec3 fromPos, vec3 toPos, vec3 up);
    inline scalar determinant(mat4 m);
    inline mat4 inverse(mat4 m);
    inline mat4 identity();

}

#include "__impl/mat4_func.inl"

#endif