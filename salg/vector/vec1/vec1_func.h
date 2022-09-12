#pragma once
#ifndef SALG_VECTOR_VEC1_FUNCTIONAL_H
#define SALG_VECTOR_VEC1_FUNCTIONAL_H

#include "vec1_type.h"

namespace salg
{

    inline bool operator==(const vec1& a, const vec1& b);
    inline bool operator!=(const vec1& a, const vec1& b);
    inline bool operator>=(const vec1& a, const vec1& b);
    inline bool operator<=(const vec1& a, const vec1& b);
    inline bool operator<(const vec1& a, const vec1& b);
    inline bool operator>(const vec1& a, const vec1& b);

    inline std::ostream& operator<<(std::ostream& os, const salg::vec1& v);

}

#include "../__impl/vec1_func.inl"

#endif