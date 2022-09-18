/**
 * @file vec4_func.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Functions for vec4 type
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#ifndef SALG_VECTOR_VEC4_FUNCTIONAL_H
#define SALG_VECTOR_VEC4_FUNCTIONAL_H

#include "vec4_type.h"

namespace salg
{

    inline bool operator==(vec4 a, vec4 b);
    inline bool operator!=(vec4 a, vec4 b);
    inline bool operator>=(vec4 a, vec4 b);
    inline bool operator<=(vec4 a, vec4 b);
    inline bool operator<(vec4 a, vec4 b);
    inline bool operator>(vec4 a, vec4 b);

    inline vec4 max(vec4 a, vec4 b);
    inline vec4 min(vec4 a, vec4 b);

    inline scalar dot(vec4 a, vec4 b);
    inline scalar dot(vec3 a, vec4 b);
    inline scalar dot(vec4 a, vec3 b);
    inline scalar dot(vec4 a, vec2 b);
    inline scalar dot(vec2 a, vec4 b);
    inline vec4 project(vec4 a, vec4 b);
    inline vec4 reject(vec4 a, vec4 b);
    inline scalar length(vec4 a);
    inline scalar length2(vec4 a);
    inline vec4 normalize(vec4 a);
    inline vec4 floor(vec4 a);
    inline vec4 ceil(vec4 a);
    inline scalar magnitude(vec4 a);
    inline scalar magnitude2(vec4 a);
    inline scalar imagnitude(vec4 a);

    inline std::ostream& operator<<(std::ostream& os, salg::vec4 v);
}

#include "__impl/vec4_func.inl"

#endif