// Problem URL: https://projecteuler.net/problem=46
// ---------------------------------------------------------------------------------
// Find the smallest odd composite number that cannot be written as the sum of a prime and twice a square

#include <iostream>
#include <vector>
#include <cmath> // for std::sqrt()
#include "extras/euler_funcs.h"

bool check_conjecture(int num, const std::vector<bool> &prime_cache) {
    for (int i = 2; i < num; i++) {
        if (prime_cache[i]) {
            int diff = num - i; // find the difference between the number and a prime

            if (diff % 2 == 0) { // only check even differences
                int square = diff / 2;
                int root = std::sqrt(square); // check if the square root is an integer
                if (root*root == square) return true; // if it is, diff is 2*root^2 and the conjecture holds
            }
        }
    }

    return false;
}

int main() {
    const int PrimeLimit = 1e6;
    std::vector<bool> prime_cache = prime_sieve(PrimeLimit); // cache the primes so they don't have to be recalculated

    for (int i = 9; i < PrimeLimit; i += 2) { // start at 9, the first odd composite number
        if (prime_cache[i]) continue; // skip primes

        // once check_conjecture() returns false, the conjecture is disproven and i is the answer
        if (!check_conjecture(i, prime_cache)) {
            std::cout << "Smallest odd composite number that disproves Goldbach's 'other' conjecture: " << i << std::endl;
            break;
        }
    }

    return 0;
}