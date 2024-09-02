// Problem URL: https://projecteuler.net/problem=10
// -----------------------------------------------------------------------
// Find the sum of all the primes below 2 million

#include <iostream>
#include "../extras/primes.cpp"

int main() {
    std::cout << "Sum of all the primes below 2 million: " << sum_primes(2000000) << std::endl;
    return 0;
}