#include "salg/salg.h"

#include <iostream>

using namespace salg;

int main()
{
    vec1 testx = 22;
    vec1 testx2 = testx + 33;
    testx += -11;
    bool eq = testx == testx2;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
