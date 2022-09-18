/**
 * @file vec2_func.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Functions for vec2 type
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#ifndef SALG_VECTOR_VEC2_FUNCTIONAL_H
#define SALG_VECTOR_VEC2_FUNCTIONAL_H

#include "vec2_type.h"

namespace salg
{

    inline bool operator==(vec2 a, vec2 b);
    inline bool operator!=(vec2 a, vec2 b);
    inline bool operator>=(vec2 a, vec2 b);
    inline bool operator<=(vec2 a, vec2 b);
    inline bool operator<(vec2 a, vec2 b);
    inline bool operator>(vec2 a, vec2 b);

    inline vec2 max(vec2 a, vec2 b);
    inline vec2 min(vec2 a, vec2 b);

    inline scalar dot(vec2 a, vec2 b);
    inline scalar skew(vec2 a, vec2 b);
    inline scalar cross(vec2 a, vec2 b);
    inline scalar length(vec2 a);
    inline scalar length2(vec2 a);
    inline scalar distance(vec2 from, vec2 to);
    inline vec2 normalize(vec2 a);
    inline vec2 floor(vec2 a);
    inline vec2 ceil(vec2 a);
    inline scalar magnitude(vec2 a);
    inline scalar imagnitude(vec2 a);

    inline std::ostream& operator<<(std::ostream& os, salg::vec2 v);
}

#include "__impl/vec2_func.inl"

#endif