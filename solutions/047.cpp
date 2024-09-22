// Problem URL: https://projecteuler.net/problem=47
// ---------------------------------------------------------------------------------
// Find the first four consecutive integers to have four *distinct* prime factors each

#include <iostream>
#include <vector>
#include <unordered_set>
#include "extras/euler_funcs.h" // for prime_factors()

int main() {
    int counter = 0;
    int i = 1;

    while (counter < 4) {
        std::vector<long long> factors = prime_factors(i);
        std::unordered_set<long long> distinct_factors(factors.begin(), factors.end()); // convert factors to a set to remove duplicates

        // increment counter if the number has 4 or more distinct prime factors
        if (distinct_factors.size() >= 4) counter++;
        else counter = 0; // but if it doesn't, reset counter
        i++;
    }

    std::cout << "The first of 4 consecutive integers to have 4 distinct prime factors each is: " << i-4 << std::endl;
    return 0;
}