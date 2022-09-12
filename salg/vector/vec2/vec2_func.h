#pragma once
#ifndef SALG_VECTOR_VEC2_FUNCTIONAL_H
#define SALG_VECTOR_VEC2_FUNCTIONAL_H

#include "vec2_type.h"

namespace salg
{

    inline bool operator==(const vec2& a, const vec2& b);
    inline bool operator!=(const vec2& a, const vec2& b);
    inline bool operator>=(const vec2& a, const vec2& b);
    inline bool operator<=(const vec2& a, const vec2& b);
    inline bool operator<(const vec2& a, const vec2& b);
    inline bool operator>(const vec2& a, const vec2& b);

    inline vec2 max(const vec2& a, const vec2& b);
    inline vec2 min(const vec2& a, const vec2& b);

    inline scalar dot(const vec2& a, const vec2& b);
    inline scalar skew(const vec2& a, const vec2& b);
    inline scalar cross(const vec2& a, const vec2& b);
    inline scalar length(const vec2& a);
    inline scalar length2(const vec2& a);
    inline scalar distance(const vec2& from, const vec2& to);
    inline vec2 normalize(const vec2& a);
    inline vec2 floor(const vec2& a);
    inline vec2 ceil(const vec2& a);
    inline scalar magnitude(const vec2& a);

    inline std::ostream& operator<<(std::ostream& os, const salg::vec2& v);
}

#include "../__impl/vec2_func.inl"

#endif