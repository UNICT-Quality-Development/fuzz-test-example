#include <iostream>
using namespace std;

#define MAX_INT_VALUE -2147483648

int SafeDivide(int a, int b) {
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    if (b == 0) {
        return 0; // Return 0 if division by zero
    }

    return a / b;
}


int main() {
    // from hex (signed) to decimal value
    // 0x00, 0x00, 0x00, 0x80,   // a = 0x80000000 = -2147483648, int32 max value
    // 0xff, 0xff, 0xff, 0xff    // b = 0xffffffff = -1

    cout << "max int value: " << int(2147483647) << endl;
    cout << "max int value + 1: " << int(2147483647 + 1) << endl; // -2147483648

    cout << SafeDivide(MAX_INT_VALUE, -1) << endl; // this will cause a crash

    return 0;
}
