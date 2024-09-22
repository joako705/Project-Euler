// Problem URL: https://projecteuler.net/problem=12
// --------------------------------------------------------------------------------
// Nth triangle number = sum of all natural numbers up to n
// Formula for nth triangle number: (n * (n+1)) / 2
// --------------------------------------------------------------------------------
// Find the first triangle number with over 500 divisors

#include <iostream>
#include <vector>
#include <map>
#include "extras/euler_funcs.h" // for prime_factors()

int count_divisors(int num) {
    int divisors = 1;
    std::map<int, int> factor_counts; // keys are the prime factors; values are the exponents (how many times they appear as a factor)
    std::vector<long long> factors = prime_factors(num); // get the prime factors of num

    for (auto &factor : factors) {
        factor_counts[factor]++; // increment the exponent of the factor
    }

    // calculate divisors with the divisor formula: (a+1) * (b+1) * (c+1) * (...)
    // where a, b, c are the prime factors' exponents
    for (auto &factor : factor_counts) { // iterate through each key-value pair in the dictionary
        divisors *= (factor.second + 1); // use .second to access the value stored by the key
    }

    return divisors;
}

int main() {
    const int DivisorCount = 500;
    int n = 1;

    while (true) {
        int triangle_num = (n * (n+1)) / 2; // use the formula to find the nth triangle number
        
        // count how many divisors the current triangle_num has and see if it's larger than DivisorCount 
        int divisors = count_divisors(triangle_num);
        if (divisors > DivisorCount) {
            std::cout << "First triangle number with over " << DivisorCount << " divisors: " << triangle_num << std::endl;
            break;
        }

        n++;
    }

    return 0;
}