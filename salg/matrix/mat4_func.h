#pragma once
#ifndef SALG_MATRIX_MAT4_FUNC_H
#define SALG_MATRIX_MAT4_FUNC_H

#include "mat4_type.h"

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
    inline mat4 scale(vec3 translation);    
    inline mat4 frustrum(scalar bottom, scalar top, scalar left, scalar right, scalar near, scalar far);
    inline mat4 perspectiveRH(scalar fovY, scalar aspect, scalar near, scalar far);
    inline mat4 perspectiveLH(scalar fovY, scalar aspect, scalar near, scalar far);   
    inline mat4 orthographicRH(scalar left, scalar right, scalar bottom, scalar top, scalar near, scalar far);
    inline mat4 orthographicLH(scalar left, scalar right, scalar bottom, scalar top, scalar near, scalar far);   
    inline mat4 lookAt(vec3 pos, vec3 direction, vec3 up);
    inline scalar determinant(mat4 m);
    inline scalar inverse(mat4 m);

}

#include "__impl/mat4_func.inl"

#endif