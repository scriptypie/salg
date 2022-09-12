#pragma once
#ifndef SALG_VECTOR_VEC1_TYPE_H
#define SALG_VECTOR_VEC1_TYPE_H

#include "../vec_base.h"

namespace salg
{

struct vec1 : vec_base<1>
{
    inline vec1() = default;
    inline ~vec1() = default;
    inline vec1(const vec1&) = default;
    inline vec1& operator=(const vec1&) = default;
    inline vec1(vec1&&) = default;
    inline vec1& operator=(vec1&&) = default;

    vec1(const scalar& x);

    inline operator scalar() const { return data[0]; }

    template<class U>
    vec1 operator + (const U& other);
    vec1 operator + (const vec1& other);

    template<class U>
    vec1 operator - (const U& other);
    vec1 operator - (const vec1& other);

    template<class U>
    vec1 operator * (const U& other);
    vec1 operator * (const vec1& other);

    template<class U>
    vec1 operator / (const U& other);
    vec1 operator / (const vec1& other);


    template<class U>
    vec1& operator += (const U& other);
    vec1& operator += (const vec1& other);

    template<class U>
    vec1& operator -= (const U& other);
    vec1& operator -= (const vec1& other);

    template<class U>
    vec1& operator *= (const U& other);
    vec1& operator *= (const vec1& other);

    template<class U>
    vec1& operator /= (const U& other);
    vec1& operator /= (const vec1& other);

};

}

#include "../__impl/vec1_type.inl"

#endif