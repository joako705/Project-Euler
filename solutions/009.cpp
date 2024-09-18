// Problem URL: https://projecteuler.net/problem=9
// --------------------------------------------------------------------------------
// Pythagorean triplet: 3 natural numbers for which:
// -- a < b < c
// -- a^2 + b^2 = c^2
// --------------------------------------------------------------------------------
// Find the product of the pythagorean triplet for which a+b+c = 1000

#include <iostream>

int main() {
    const int ABC_Sum = 1000;
    int product = 1;

    // work backwards from the biggest possible c, since a < b < c
    // has to be ABC_Sum-2, since a and b have to be at least 1
    for (int c = ABC_Sum-2; c >= 1; c--) {
        for (int b = c; b >= 1; b--) {
            for (int a = b; a >= 1; a--) {

                if ((a+b+c == ABC_Sum) && (a*a + b*b == c*c)) {
                    product = a*b*c;
                    std::cout << "a: " << a << "\nb: " << b << "\nc: " << c << std::endl;
                    std::cout << "Product of the Pythagorean triplet for which a + b + c = " << ABC_Sum << ": " << product << std::endl;
                    return 0; // return 0 to exit the all loops immediately
                }
                
            }
        }
    }

    return 0;
}