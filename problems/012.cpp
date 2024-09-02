// Problem URL: https://projecteuler.net/problem=12
// -----------------------------------------------------------------------
// Find the first triangle number with over 500 divisors
// Formula for nth triangle number: (n * (n+1)) / 2

#include <iostream>
#include <cmath>
#include <map>

int count_divisors(int num) {
    int divisors = 1;
    std::map<int, int> factor_counts; // dictionary where the keys are the prime factors and the values are the exponents

    // handle 2 (and all even factors)
    while (num % 2 == 0) {
        factor_counts[2]++;
        num /= 2;
    }

    // handle odd factors
    for (int i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            factor_counts[i]++;
            num /= i;
        }
    }
     
    // handle remaining prime factors
    if (num > 2) factor_counts[num]++;

    // calculate divisors with the formula: (a+1) * (b+1) * (c+1) * (...)
    // where a, b, c are the exponents of the prime factors
    for (auto &factor : factor_counts) {
        divisors *= (factor.second + 1);
    }

    return divisors;
}

int main() {
    int num = 1, triangle_num = 1;

    while (true) {
        triangle_num = (num * (num+1)) / 2; // use the formula
        
        int factors = count_divisors(triangle_num);

        if (factors > 500) {
            std::cout << "First triangle number with over 500 divisors: " << triangle_num << std::endl;
            break;
        }

        num++;
    }

    return 0;
}