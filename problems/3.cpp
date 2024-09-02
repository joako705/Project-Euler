// Problem URL: https://projecteuler.net/problem=3
// --------------------------------------------------------------------------
// Find the largest prime factor of the given number

#include <iostream>
#include <vector>
#include "../extras/primes.cpp"

int main() {
    const long long num = 600851475143;
    int biggest = 0;

    std::vector<long long> factors = prime_factors(num);

    for (auto &factor : factors) {
        if (factor > biggest) biggest = factor;
    }

    std::cout << "Biggest prime factor of " << num << ": " << biggest << std::endl;
    return 0;
}