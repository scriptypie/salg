/**
 * @file transform_component.h
 * @author Krivenko (scriptypie) Slava (miracl303@inbox.ru)
 * @brief Extension for extracting transform component for e.g. ECS.
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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