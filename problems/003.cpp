// Problem URL: https://projecteuler.net/problem=3
// --------------------------------------------------------------------------------
// Find the largest prime factor of the given number

#include <iostream>
#include <vector>
#include "../extras/helpers.cpp" // for prime_factors()

int main() {
    const long long BigNum = 600851475143; // the number given by the problem
    long long biggest_factor = 0;

    std::vector<long long> factors = prime_factors(BigNum);

    for (auto &factor : factors) { // iterate over all the prime factors and compare each to the current biggest_factor
        if (factor > biggest_factor) biggest_factor = factor;
    }

    std::cout << "Biggest prime factor of " << BigNum << ": " << biggest_factor << std::endl;
    return 0;
}