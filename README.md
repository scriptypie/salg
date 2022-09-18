# salg

Simple and sometimes stupid math library for gamedev.

## Installation

Just include folder where 'salg' folder is standing, and feel free to use it!

## Usage

```cpp
// First, include main salg.h file
#include <salg/salg.h>

void makeSomehting()
{
    salg::mat4 projMat = salg::perspectiveLH(65, 1.778, 0.1, 1000);
    salg::vec3 pos = {1, 12, 0};
    // and so on...
}
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
