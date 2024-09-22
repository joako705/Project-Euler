// Problem URL: https://projecteuler.net/problem=27
// ---------------------------------------------------------------------------------
// Considering quadratics of the form: n^2 + an + b, where |a| < 1000, |b| <= 1000:
// Find the product of the coefficients, a and b, that produces the maximum number of primes for consecutive values of n, starting with n = 0

#include <iostream>
#include "extras/euler_funcs.h" // for is_prime()

int main() {
    int max_a = 0, max_b = 0, max_consecutives = 0;

    // brute force approach: check all combinations of a and b within the bounds given
    for (int a = -999; a <= 999; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int n = 0;

            // only increment while the function keeps returning primes
            while (is_prime(n*n + a*n + b)) n++;
            if (n > max_consecutives) { // if n is longer than the current max length, update the max values
                max_a = a;
                max_b = b;
                max_consecutives = n;
            }
        }
    }

    std::cout << "Product of the coefficients that produce the max number of primes consecutively: " << max_a*max_b << std::endl;
    return 0;
}