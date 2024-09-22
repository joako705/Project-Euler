// Problem URL: https://projecteuler.net/problem=1
// --------------------------------------------------------------------------------
// Find the sum of all the multiples of 3 and 5 below 1,000

#include <iostream>

int main() {
    const int Limit = 1000;
    int sum_multiples = 0;

    for (int i = 0; i < Limit; i++) {
        // check if the number is a multiple of 3 or 5
        if ((i % 3 == 0) || (i % 5 == 0)) sum_multiples += i;
    }

    std::cout << "Sum of all multiples of 3 and 5 below " << Limit << ": " << sum_multiples << std::endl;
    return 0;
}