// Problem URL: https://projecteuler.net/problem=10
// --------------------------------------------------------------------------------
// Find the sum of all the primes below 2 million

#include <iostream>
#include "../extras/helpers.cpp" // for find_primes()

int main() {
    const int Limit = 2000000;
    long long prime_sum = 0;
    std::vector<long long> primes = find_primes(Limit);

    for (auto &prime : primes) prime_sum += prime; // go through the list of primes and add them all up

    std::cout << "Sum of all the primes below " << Limit << ": " << prime_sum << std::endl;
    return 0;
}