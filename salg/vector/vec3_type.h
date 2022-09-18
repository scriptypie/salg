/**
 * @file vec3_type.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Pure vec3 type structure
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#ifndef SALG_VECTOR_VEC3_TYPE_H
#define SALG_VECTOR_VEC3_TYPE_H

#include "vec_base.h"

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
    vec3(const vec2& v);

    inline vec2 xy();

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

#include "__impl/vec3_type.inl"

#endif