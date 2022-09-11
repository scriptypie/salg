#pragma once
#ifndef SALG_COMMON_SCALAR_H
#define SALG_COMMON_SCALAR_H

namespace salg
{

#ifdef SALG_HIGH_PRECISION
using scalar = double;
#else
using scalar = float;
#endif

}

#endif