// Problem URL: https://projecteuler.net/problem=35
// -----------------------------------------------------------------------------------------
// Find all the circular primes below 1 million
// Circular primes are primes that remain prime for all rotations of their digits

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "../extras/helpers.cpp"

std::vector<long long> find_rotations(long long n) {
    std::vector<long long> rotations;
    std::string num = std::to_string(n);

    for (auto &digit : num) {
        rotate(num.begin(), num.begin()+1, num.end());
        rotations.push_back(stoll(num));
    }

    return rotations;
}

int main() {
    std::vector<long long> primes = find_primes(1000000);
    std::vector<long long> circulars;

    for (auto &num : primes) {
        std::vector<long long> rotations = find_rotations(num);
        std::vector<bool> tests(rotations.size(), true);

        for (unsigned int i = 0; i < rotations.size(); i++) {
            if (!is_prime(rotations[i])) {
                tests[i] = false;
                break;
            }
        }

        if (all_of(tests.begin(), tests.end(), [](bool i) { return i; })) circulars.push_back(num);
    }

    std::cout << "The number of circular primes below 1 million is: " << circulars.size() << std::endl;
    return 0;
}