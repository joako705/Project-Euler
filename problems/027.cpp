// Problem URL: https://projecteuler.net/problem=27
// ------------------------------------------------------------
// Considering quadratics of the form: n^2 + an + b, where |a| < 1000, |b| <= 1000,
// find the product of the coefficients, a and b, that produces the maximum
// number of primes for consecutive values of n, starting with n = 0

#include <iostream>
#include <cmath>
#include "../extras/helpers.cpp"

int main() {
    int max_a = 0, max_b = 0, consecutive = 0;

    // just brute force it, lol
    for (int a = -999; a <= 999; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int n = 0;

            // only increment while the function given keeps returning primes
            while (is_prime(pow(n, 2) + a*n + b)) n++;
            if (n > consecutive) {
                max_a = a;
                max_b = b;
                consecutive = n;
            }
        }
    }

    std::cout << "Product of the coefficients that produce the max number of primes consecutively: " << max_a*max_b << std::endl;
    return 0;
}