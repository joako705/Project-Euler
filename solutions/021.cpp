// Problem URL: https://projecteuler.net/problem=21
// ---------------------------------------------------------------------------------
// Amicable numbers: numbers whose sum of divisors is equal to each other (but the numbers are not the same)
// ---------------------------------------------------------------------------------
// Find the sum of all amicable numbers below 10000

#include <iostream>
#include "extras/euler_funcs.h" // for sum_divisors()

int main() {
    const int Limit = 1000;
    int amicable_sum = 0;

    for (int a = 1; a < Limit; a++) {
        int b = sum_divisors(a);
        if (a != b && a == sum_divisors(b)) { // make sure a and b aren't the same
            amicable_sum += a;
        }
    }

    std::cout << "Sum of all amicable numbers under " << Limit << ": " << amicable_sum << std::endl;
    return 0;
}