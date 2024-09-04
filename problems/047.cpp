// Problem URL: https://projecteuler.net/problem=47
// -------------------------------------------------------------------------------------------
// Find the first four consecutive integers to have four *distinct* prime factors each

#include <iostream>
#include <vector>
#include <set>
#include "../extras/helpers.cpp"

int main() {
    int counter = 0;
    long long i = 1;

    while (counter < 4) {
        std::vector<long long> factors = prime_factors(i);
        std::set<long long> distinct_factors(factors.begin(), factors.end());

        if (distinct_factors.size() >= 4) counter++;
        else counter = 0;
        i++;
    }

    std::cout << "The first of 4 consecutive integers to have 4 distinct prime factors each is: " << i-4 << std::endl;
    return 0;
}