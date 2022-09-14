#include "../mat4_func.h"

namespace salg
{

mat4 perspectiveLH(scalar fovY, scalar aspect, scalar near, scalar far) 
{
    scalar sinFov = sin(fovY * 0.5);
    scalar cosFov = cos(fovY * 0.5);
    scalar height = cosFov / sinFov;
    scalar width = height / aspect;
    scalar fRange = far / (far - near);

    mat4 tmp
    (
        width, 0, 0, 0,
        0, height, 0, 0, 
        0, 0, fRange, 0, 
        0, 0, -fRange * near, 0
    );
    return tmp;
}

}
