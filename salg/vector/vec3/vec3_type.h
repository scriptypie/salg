#pragma once
#ifndef SALG_VECTOR_VEC3_TYPE_H
#define SALG_VECTOR_VEC3_TYPE_H

#include "../vec_base.h"

namespace salg
{

struct vec3 : vec_base<3>
{
    inline vec3() = default;
    inline ~vec3() = default;
    inline vec3(const vec3&) = default;
    inline vec3& operator=(const vec3&) = default;
    inline vec3(vec3&&) = default;
    inline vec3& operator=(vec3&&) = default;

    vec3(const scalar& x, const scalar& y, const scalar& z);

    inline vec2& xy();
    inline vec3& xyz();

    template<class U>
    vec3 operator + (const U& other);
    vec3 operator + (const vec3& other);

    template<class U>
    vec3 operator - (const U& other);
    vec3 operator - (const vec3& other);

    template<class U>
    vec3 operator * (const U& other);
    vec3 operator * (const vec3& other);

    template<class U>
    vec3 operator / (const U& other);
    vec3 operator / (const vec3& other);


    template<class U>
    vec3& operator += (const U& other);
    vec3& operator += (const vec3& other);

    template<class U>
    vec3& operator -= (const U& other);
    vec3& operator -= (const vec3& other);

    template<class U>
    vec3& operator *= (const U& other);
    vec3& operator *= (const vec3& other);

    template<class U>
    vec3& operator /= (const U& other);
    vec3& operator /= (const vec3& other);

};

}

#include "../__impl/vec3_type.inl"

#endif