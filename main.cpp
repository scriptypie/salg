#include "salg/salg.h"

#include <iostream>

using namespace salg;

int main()
{
    vec3 testx = {22, 1392, 183};
    vec3 testx2 = testx + 22;
    testx += -11;
    bool eq = testx == testx2;
    float lenvec2 = length(testx);
    vec3 normalized = normalize(testx);

    lenvec2 = salg::dot(testx, testx2);

    std::cout << "Hello, World!" << normalized << std::endl;
    return 0;
}
