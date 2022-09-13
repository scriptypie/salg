#pragma once
#ifndef SALG_VECTOR_VEC3_FUNCTIONAL_H
#define SALG_VECTOR_VEC3_FUNCTIONAL_H

#include "vec3_type.h"

namespace salg
{

    inline bool operator==(vec3 a, vec3 b);
    inline bool operator!=(vec3 a, vec3 b);
    inline bool operator>=(vec3 a, vec3 b);
    inline bool operator<=(vec3 a, vec3 b);
    inline bool operator<(vec3 a, vec3 b);
    inline bool operator>(vec3 a, vec3 b);

    inline vec3 max(vec3 a, vec3 b);
    inline vec3 min(vec3 a, vec3 b);

    inline scalar dot(vec3 a, vec3 b);
    inline scalar dot(vec3 a, vec2 b);
    inline scalar dot(vec2 a, vec3 b);
    inline vec3 cross(vec3 a, vec3 b);
    inline vec3 project(vec3 a, vec3 b);
    inline vec3 reject(vec3 a, vec3 b);
    inline scalar length(vec3 a);
    inline scalar length2(vec3 a);
    inline scalar distance(vec3 from, vec3 to);
    inline vec3 normalize(vec3 a);
    inline vec3 floor(vec3 a);
    inline vec3 ceil(vec3 a);
    inline scalar magnitude(vec3 a);
    inline scalar magnitude2(vec3 a);
    inline scalar imagnitude(vec3 a);

    inline std::ostream& operator<<(std::ostream& os, salg::vec3 v);
}

#include "__impl/vec3_func.inl"

#endif