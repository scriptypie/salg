#include "../vec1/vec1_type.h"

namespace salg
{

vec1::vec1(const scalar& x)
{
    storage.data[0] = x;
}

///////

template<class U>
vec1 vec1::operator + (const U& other)
{
    vec1 result = {};
    result = storage.data[0] + static_cast<scalar>(other);
    return result;
}

vec1 vec1::operator + (const vec1& other)
{
    vec1 result = {};
    result = storage.data[0] + other.storage.data[0];
    return result;
}

template<class U>
vec1 vec1::operator - (const U& other)
{
    vec1 result = {};
    result = storage.data[0] - static_cast<scalar>(other);
    return result;
}

vec1 vec1::operator - (const vec1& other)
{
    vec1 result = {};
    result = storage.data[0] - other.storage.data[0];
    return result;
}

template<class U>
vec1 vec1::operator * (const U& other)
{
    vec1 result = {};
    result = storage.data[0] * static_cast<scalar>(other);
    return result;
}

vec1 vec1::operator * (const vec1& other)
{
    vec1 result = {};
    result = storage.data[0] * other.storage.data[0];
    return result;
}

template<class U>
vec1 vec1::operator / (const U& other)
{
    vec1 result = {};
    result = storage.data[0] / static_cast<scalar>(other);
    return result;
}

vec1 vec1::operator / (const vec1& other)
{
    vec1 result = {};
    result = storage.data[0] / other.storage.data[0];
    return result;
}

//////

template<class U>
vec1& vec1::operator += (const U& other)
{
    storage.data[0] += other;
    return *this;
}

vec1& vec1::operator += (const vec1& other)
{
    storage.data[0] += other.storage.data[0];
    return *this;
}

template<class U>
vec1& vec1::operator -= (const U& other)
{
    storage.data[0] -= other;
    return *this;
}

vec1& vec1::operator -= (const vec1& other)
{
    storage.data[0] -= other.storage.data[0];
    return *this;
}

template<class U>
vec1& vec1::operator *= (const U& other)
{
    storage.data[0] *= other;
    return *this;
}

vec1& vec1::operator *= (const vec1& other)
{
    storage.data[0] *= other.storage.data[0];
    return *this;
}

template<class U>
vec1& vec1::operator /= (const U& other)
{
    storage.data[0] /= other;
    return *this;
}

vec1& vec1::operator /= (const vec1& other)
{
    storage.data[0] /= other.storage.data[0];
    return *this;
}


}
