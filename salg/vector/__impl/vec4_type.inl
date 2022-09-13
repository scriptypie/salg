#include "../vec4_type.h"

namespace salg
{

vec4::vec4(const scalar& x, const scalar& y, const scalar& z, const scalar& w) : vec_base(((scalar[EXNUM]){x, y, z, w}))
{
}

vec4::vec4(const vec3& v) : vec_base(((scalar[EXNUM]){v.data[0], v.data[1], v.data[2], 0}))
{
}

vec4::vec4(const vec2& v) : vec_base(((scalar[EXNUM]){v.data[0], v.data[1], 0, 0}))
{
}

vec2 vec4::xy()
{
    return {data[0], data[1]};
}

vec3 vec4::xyz()
{
    return {data[0], data[1], data[2]};
}

///////

template<class U>
vec4 vec4::operator + (const U& other)
{
    vec4 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] + static_cast<scalar>(other);
    return result;
}

vec4 vec4::operator + (const vec4& other)
{
    vec4 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

template<class U>
vec4 vec4::operator - (const U& other)
{
    vec4 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] - static_cast<scalar>(other);
    return result;
}

vec4 vec4::operator - (const vec4& other)
{
    vec4 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] - other.data[i];
    return result;
}

template<class U>
vec4 vec4::operator * (const U& other)
{
    vec4 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] * static_cast<scalar>(other);
    return result;
}

vec4 vec4::operator * (const vec4& other)
{
    vec4 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] * other.data[i];
    return result;
}

template<class U>
vec4 vec4::operator / (const U& other)
{
    vec4 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] / static_cast<scalar>(other);
    return result;
}

vec4 vec4::operator / (const vec4& other)
{
    vec4 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] / other.data[i];
    return result;
}

//////

template<class U>
vec4& vec4::operator += (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] += other;
    return *this;
}

vec4& vec4::operator += (const vec4& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] += other.data[i];
    return *this;
}

template<class U>
vec4& vec4::operator -= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] -= other;
    return *this;
}

vec4& vec4::operator -= (const vec4& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] -= other.data[i];
    return *this;
}

template<class U>
vec4& vec4::operator *= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] *= other;
    return *this;
}

vec4& vec4::operator *= (const vec4& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] *= other.data[i];
    return *this;
}

template<class U>
vec4& vec4::operator /= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] /= other;
    return *this;
}

vec4& vec4::operator /= (const vec4& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] /= other.data[i];
    return *this;
}


}
