#include "../vec3_type.h"

namespace salg
{

vec3::vec3(const scalar& x, const scalar& y, const scalar& z) : vec_base(((scalar[DIM]){x, y, z}))
{
}

vec3::vec3(const vec2& v) : vec_base(((scalar[DIM]){v.data[0], v.data[1], 0}))
{
}

vec2 vec3::xy()
{
    return {data[0], data[1]};
}

///////

template<class U>
vec3 vec3::operator + (const U& other)
{
    vec3 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] + static_cast<scalar>(other);
    return result;
}

vec3 vec3::operator + (const vec3& other)
{
    vec3 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

template<class U>
vec3 vec3::operator - (const U& other)
{
    vec3 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] - static_cast<scalar>(other);
    return result;
}

vec3 vec3::operator - (const vec3& other)
{
    vec3 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] - other.data[i];
    return result;
}

template<class U>
vec3 vec3::operator * (const U& other)
{
    vec3 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] * static_cast<scalar>(other);
    return result;
}

vec3 vec3::operator * (const vec3& other)
{
    vec3 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] * other.data[i];
    return result;
}

template<class U>
vec3 vec3::operator / (const U& other)
{
    vec3 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] / static_cast<scalar>(other);
    return result;
}

vec3 vec3::operator / (const vec3& other)
{
    vec3 result = {};
    for (short i = 0; i < DIM; i++)
        result.data[i] = data[i] / other.data[i];
    return result;
}

//////

template<class U>
vec3& vec3::operator += (const U& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] += other;
    return *this;
}

vec3& vec3::operator += (const vec3& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] += other.data[i];
    return *this;
}

template<class U>
vec3& vec3::operator -= (const U& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] -= other;
    return *this;
}

vec3& vec3::operator -= (const vec3& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] -= other.data[i];
    return *this;
}

template<class U>
vec3& vec3::operator *= (const U& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] *= other;
    return *this;
}

vec3& vec3::operator *= (const vec3& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] *= other.data[i];
    return *this;
}

template<class U>
vec3& vec3::operator /= (const U& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] /= other;
    return *this;
}

vec3& vec3::operator /= (const vec3& other)
{
    for (short i = 0; i < DIM; i++)
        data[i] /= other.data[i];
    return *this;
}


}
