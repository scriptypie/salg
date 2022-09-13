#include "../vec2_type.h"

namespace salg
{

vec2::vec2(const scalar& x, const scalar& y) : vec_base(((scalar[EXNUM]){x, y}))
{
}

///////

template<class U>
vec2 vec2::operator + (const U& other)
{
    vec2 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] + static_cast<scalar>(other);
    return result;
}

vec2 vec2::operator + (const vec2& other)
{
    vec2 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

template<class U>
vec2 vec2::operator - (const U& other)
{
    vec2 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] - static_cast<scalar>(other);
    return result;
}

vec2 vec2::operator - (const vec2& other)
{
    vec2 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] - other.data[i];
    return result;
}

template<class U>
vec2 vec2::operator * (const U& other)
{
    vec2 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] * static_cast<scalar>(other);
    return result;
}

vec2 vec2::operator * (const vec2& other)
{
    vec2 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] * other.data[i];
    return result;
}

template<class U>
vec2 vec2::operator / (const U& other)
{
    vec2 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] / static_cast<scalar>(other);
    return result;
}

vec2 vec2::operator / (const vec2& other)
{
    vec2 result = {};
    for (short i = 0; i < EXNUM; i++)
        result.data[i] = data[i] / other.data[i];
    return result;
}

//////

template<class U>
vec2& vec2::operator += (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] += other;
    return *this;
}

vec2& vec2::operator += (const vec2& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] += other.data[i];
    return *this;
}

template<class U>
vec2& vec2::operator -= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] -= other;
    return *this;
}

vec2& vec2::operator -= (const vec2& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] -= other.data[i];
    return *this;
}

template<class U>
vec2& vec2::operator *= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] *= other;
    return *this;
}

vec2& vec2::operator *= (const vec2& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] *= other.data[i];
    return *this;
}

template<class U>
vec2& vec2::operator /= (const U& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] /= other;
    return *this;
}

vec2& vec2::operator /= (const vec2& other)
{
    for (short i = 0; i < EXNUM; i++)
        data[i] /= other.data[i];
    return *this;
}


}
