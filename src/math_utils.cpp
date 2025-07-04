#include "math_utils.h"

#define INT_MIN -2147483648
#define INT_MAX 2147483647

int SafeDivide(int a, int b) {
    if (b == 0) {
        return 0; // Return 0 if division by zero
    }

    // this is not a real solution but it's more a workaround
    if (a == INT_MIN && b < 0) {
        return 0;
    }

    return a / b;
}
