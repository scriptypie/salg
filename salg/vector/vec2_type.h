/**
 * @file vec2_type.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Pure vec2 type structure
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#ifndef SALG_VECTOR_VEC2_TYPE_H
#define SALG_VECTOR_VEC2_TYPE_H

#include "vec_base.h"

namespace salg
{

struct vec2 : vec_base<2>
{
    inline vec2() = default;
    inline ~vec2() = default;
    inline vec2(const vec2&) = default;
    inline vec2& operator=(const vec2&) = default;
    inline vec2(vec2&&) = default;
    inline vec2& operator=(vec2&&) = default;

    vec2(const scalar& x, const scalar& y);

    template<class U>
    vec2 operator + (const U& other);
    vec2 operator + (const vec2& other);

    template<class U>
    vec2 operator - (const U& other);
    vec2 operator - (const vec2& other);

    template<class U>
    vec2 operator * (const U& other);
    vec2 operator * (const vec2& other);

    template<class U>
    vec2 operator / (const U& other);
    vec2 operator / (const vec2& other);


    template<class U>
    vec2& operator += (const U& other);
    vec2& operator += (const vec2& other);

    template<class U>
    vec2& operator -= (const U& other);
    vec2& operator -= (const vec2& other);

    template<class U>
    vec2& operator *= (const U& other);
    vec2& operator *= (const vec2& other);

    template<class U>
    vec2& operator /= (const U& other);
    vec2& operator /= (const vec2& other);

};

}

#include "__impl/vec2_type.inl"

#endif