//product of the pythagorean triplet for which a+b+c = 1000

#include <iostream>
using namespace std;

int main() {
    int product = 1;

    for (int c = 1000; c >= 1; c--) {
        for (int b = c; b >= 1; b--) {
            for (int a = b; a >= 1; a--) {
                if ((a+b+c) == 1000 && (a*a + b*b == c*c)) {
                    product = a*b*c;
                    cout << "a: " << a << "\nb: " << b << "\nc: " << c << endl;
                    cout << "Product of the Pythagorean triplet for which a + b + c = 1000: " << product;
                    return 0;
                }
            }
        }
    }

    return 0;
}