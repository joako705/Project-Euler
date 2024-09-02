// Problem URL: https://projecteuler.net/problem=1
// --------------------------------------------------------------------------
// Find the sum of all the multiples of 3 and 5 below 1000

#include <iostream>

int main() {
    const int limit = 1000;
    int sum = 0;

    for (int i = 0; i < limit; i++) {
        if ((i % 3 == 0) || (i % 5 == 0)) sum += i;
    }

    std::cout << "Sum of all the multiples of 3 and 5 below " << limit << ": " << sum << std::endl;
    return 0;
}