// Problem URL: https://projecteuler.net/problem=35
// ---------------------------------------------------------------------------------
// Circular primes: primes that remain prime for all rotations of their digits
// ---------------------------------------------------------------------------------
// Find all the circular primes below 1 million

#include <iostream>
#include <algorithm> // for std::rotate()
#include <string>
#include <vector>
#include "extras/euler_funcs.h" // for find_primes(), is_prime()

std::vector<long long> find_rotations(long long n) {
    std::vector<long long> rotations;
    std::string num_str = std::to_string(n);

    // std::rotate() takes three iterator arguments: the start of the range, the new start after the rotation, and the end of the range
    // this for-loop iterates through each digit in num_str and shifts it to the right on each iteration
    // for example: "123" -> "231" -> "312" (each one getting added to the rotations vector)
    for (auto &digit : num_str) {
        std::rotate(num_str.begin(), num_str.begin() + 1, num_str.end());
        rotations.push_back(std::stoll(num_str)); // after rotating the string, it's converted back to a long long, and added it to the vector
    }

    return rotations;
}

int main() {
    const int PrimeLimit = 1e6;
    std::vector<long long> primes = find_primes(PrimeLimit);
    std::vector<long long> circulars;

    // for each number in the 'primes' vector, find the number's rotations and check if they're all prime
    for (auto &prime : primes) {
        std::vector<long long> rotations = find_rotations(prime);
        bool all_prime = 0;

        for (unsigned int i = 0; i < rotations.size(); i++) {
            if (!is_prime(rotations[i])) {
                all_prime = false;
                break; // if one of the rotations isn't prime, there's no need to check the rest
            }
        }

        if (all_prime) circulars.push_back(prime);
    }

    std::cout << "Number of circular primes below " << PrimeLimit << ": " << circulars.size() << std::endl;
    return 0;
}