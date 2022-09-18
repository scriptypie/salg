/**
 * @file vec1_func.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Functions for vec1 type
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#ifndef SALG_VECTOR_VEC1_FUNCTIONAL_H
#define SALG_VECTOR_VEC1_FUNCTIONAL_H

#include "vec1_type.h"

namespace salg
{

    inline bool operator==(vec1 a, vec1 b);
    inline bool operator!=(vec1 a, vec1 b);
    inline bool operator>=(vec1 a, vec1 b);
    inline bool operator<=(vec1 a, vec1 b);
    inline bool operator<(vec1 a, vec1 b);
    inline bool operator>(vec1 a, vec1 b);

    inline std::ostream& operator<<(std::ostream& os, salg::vec1 v);

}

#include "__impl/vec1_func.inl"

#endif