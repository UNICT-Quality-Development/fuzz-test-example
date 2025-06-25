#include <iostream>
using namespace std;

int SafeDivide(int a, int b) {
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    if (b == 0) {
        return 0; // Return 0 if division by zero
    }

    return a / b;
}


int main() {
    int a, b;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << SafeDivide(a, b) << endl;

    return 0;
}
