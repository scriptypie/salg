#include "salg/salg.h"

#include <iostream>

using namespace salg;

int main()
{
    mat4 m4 = perspectiveLH(65.0, 1.668, 0.1, 1000.0);

    (void)m4;
    return 0;
}
