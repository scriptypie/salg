#include "../vec3/vec3_type.h"

namespace salg
{

vec3::vec3(const scalar& x, const scalar& y, const scalar& z) : vec_base(((scalar[]){x, y, z}))
{
}

vec3& vec3::xyz()
{
    return *this;
}

///////

template<class U>
vec3 vec3::operator + (const U& other)
{
    vec3 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] + static_cast<scalar>(other);
    return result;
}

vec3 vec3::operator + (const vec3& other)
{
    vec3 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

template<class U>
vec3 vec3::operator - (const U& other)
{
    vec3 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] - static_cast<scalar>(other);
    return result;
}

vec3 vec3::operator - (const vec3& other)
{
    vec3 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] - other.data[i];
    return result;
}

template<class U>
vec3 vec3::operator * (const U& other)
{
    vec3 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] * static_cast<scalar>(other);
    return result;
}

vec3 vec3::operator * (const vec3& other)
{
    vec3 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] * other.data[i];
    return result;
}

template<class U>
vec3 vec3::operator / (const U& other)
{
    vec3 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] / static_cast<scalar>(other);
    return result;
}

vec3 vec3::operator / (const vec3& other)
{
    vec3 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] / other.data[i];
    return result;
}

//////

template<class U>
vec3& vec3::operator += (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] += other;
    return *this;
}

vec3& vec3::operator += (const vec3& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] += other.data[i];
    return *this;
}

template<class U>
vec3& vec3::operator -= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] -= other;
    return *this;
}

vec3& vec3::operator -= (const vec3& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] -= other.data[i];
    return *this;
}

template<class U>
vec3& vec3::operator *= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] *= other;
    return *this;
}

vec3& vec3::operator *= (const vec3& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] *= other.data[i];
    return *this;
}

template<class U>
vec3& vec3::operator /= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] /= other;
    return *this;
}

vec3& vec3::operator /= (const vec3& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] /= other.data[i];
    return *this;
}


}
