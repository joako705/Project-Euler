// Problem URL: https://projecteuler.net/problem=10
// -----------------------------------------------------------------------
// Find the sum of all the primes below 2 million

#include <iostream>
#include "../extras/primes.cpp"

int main() {
    long long sum = 0;
    std::vector<long long> primes = find_primes(2000000);

    for (auto &num : primes) sum += num;

    std::cout << "Sum of all the primes below 2 million: " << sum << std::endl;
    return 0;
}