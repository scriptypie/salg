#pragma once
#ifndef SALG_COMMON_TRANSFORM_COMPONENT_H
#define SALG_COMMON_TRANSFORM_COMPONENT_H

#include "../vector/vec3.h"

namespace salg
{

struct transform_component
{
    vec3 translation;
    vec3 rotation;
    vec3 scale;
};


}

#endif