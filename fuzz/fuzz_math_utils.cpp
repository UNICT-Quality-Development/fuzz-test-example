#include <cstdint>
#include <cstddef>
#include "math_utils.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    if (size < 8) return 0;

    int a = *(reinterpret_cast<const int*>(data));
    int b = *(reinterpret_cast<const int*>(data + 4));

    SafeDivide(a, b);
    return 0;
}
