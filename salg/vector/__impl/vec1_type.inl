#include "../vec1_type.h"

namespace salg
{

vec1::vec1(const scalar& x) : vec_base(((scalar[]){x}))
{
}

///////

template<class U>
vec1 vec1::operator + (const U& other)
{
    vec1 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] + static_cast<scalar>(other);
    return result;
}

vec1 vec1::operator + (const vec1& other)
{
    vec1 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

template<class U>
vec1 vec1::operator - (const U& other)
{
    vec1 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] - static_cast<scalar>(other);
    return result;
}

vec1 vec1::operator - (const vec1& other)
{
    vec1 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] - other.data[i];
    return result;
}

template<class U>
vec1 vec1::operator * (const U& other)
{
    vec1 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] * static_cast<scalar>(other);
    return result;
}

vec1 vec1::operator * (const vec1& other)
{
    vec1 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] * other.data[i];
    return result;
}

template<class U>
vec1 vec1::operator / (const U& other)
{
    vec1 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] / static_cast<scalar>(other);
    return result;
}

vec1 vec1::operator / (const vec1& other)
{
    vec1 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] / other.data[i];
    return result;
}

//////

template<class U>
vec1& vec1::operator += (const U& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] += other;
    return *this;
}

vec1& vec1::operator += (const vec1& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] += other.data[i];
    return *this;
}

template<class U>
vec1& vec1::operator -= (const U& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] -= other;
    return *this;
}

vec1& vec1::operator -= (const vec1& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] -= other.data[i];
    return *this;
}

template<class U>
vec1& vec1::operator *= (const U& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] *= other;
    return *this;
}

vec1& vec1::operator *= (const vec1& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] *= other.data[i];
    return *this;
}

template<class U>
vec1& vec1::operator /= (const U& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] /= other;
    return *this;
}

vec1& vec1::operator /= (const vec1& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] /= other.data[i];
    return *this;
}


}
