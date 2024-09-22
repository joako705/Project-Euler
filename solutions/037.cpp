// Problem URL: https://projecteuler.net/problem=37
// ---------------------------------------------------------------------------------
// Truncatable primes: primes that can continuously have their digits removed from either side and still be prime
// ---------------------------------------------------------------------------------
// Find the sum of all truncatable primes

#include <iostream>
#include <string> // for std::stoll()
#include <vector>
#include "extras/euler_funcs.h" // for find_primes(), is_prime()

int main() {
    std::vector<long long> primes = find_primes(1e6);
    int sum_truncs = 0;

    for (auto &prime : primes) {
        if (prime < 10) continue; // skip single-digit primes

        std::string prime_str = std::to_string(prime); // convert the prime to a string
        bool is_truncatable = true;

        // check all truncations of the prime
        for (unsigned int i = 1; i < prime_str.size(); i++) {
            std::string left = prime_str.substr(i); // create a substring starting from index i
            std::string right = prime_str.substr(0, i); // create a substring ending at index i

            // convert both substrings to long longs and check if they're prime
            if (!is_prime(std::stoll(left)) || !is_prime(std::stoll(right))) {
                is_truncatable = false;
                break; // if one of the truncations isn't prime, there's no need to check the rest
            }
        }

        if (is_truncatable) sum_truncs += prime;
    }

    std::cout << "Sum of all truncatable primes: " << sum_truncs << std::endl;
    return 0;
}