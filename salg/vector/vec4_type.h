#pragma once
#ifndef SALG_VECTOR_VEC4_TYPE_H
#define SALG_VECTOR_VEC4_TYPE_H

#include "vec_base.h"

namespace salg
{

struct vec4 : vec_base<4>
{
    inline vec4() = default;
    inline ~vec4() = default;
    inline vec4(const vec4&) = default;
    inline vec4& operator=(const vec4&) = default;
    inline vec4(vec4&&) = default;
    inline vec4& operator=(vec4&&) = default;

    vec4(const scalar& x, const scalar& y, const scalar& z, const scalar& w);
    vec4(const vec3& v);
    vec4(const vec2& v);

    inline vec2 xy();
    inline vec3 xyz();

    template<class U>
    vec4 operator + (const U& other);
    vec4 operator + (const vec4& other);

    template<class U>
    vec4 operator - (const U& other);
    vec4 operator - (const vec4& other);

    template<class U>
    vec4 operator * (const U& other);
    vec4 operator * (const vec4& other);

    template<class U>
    vec4 operator / (const U& other);
    vec4 operator / (const vec4& other);


    template<class U>
    vec4& operator += (const U& other);
    vec4& operator += (const vec4& other);

    template<class U>
    vec4& operator -= (const U& other);
    vec4& operator -= (const vec4& other);

    template<class U>
    vec4& operator *= (const U& other);
    vec4& operator *= (const vec4& other);

    template<class U>
    vec4& operator /= (const U& other);
    vec4& operator /= (const vec4& other);

};

}

#include "__impl/vec4_type.inl"

#endif