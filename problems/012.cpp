// Problem URL: https://projecteuler.net/problem=12
// --------------------------------------------------------------------------------
// Nth triangle number = sum of all natural numbers up to n
// Formula for nth triangle number: (n * (n+1)) / 2
// --------------------------------------------------------------------------------
// Find the first triangle number with over 500 divisors

#include <iostream>
#include <map>

int count_divisors(int num) {
    int divisors = 1;
    std::map<int, int> factor_counts; // keys are the prime factors and the values are the exponents (how many times they appear as a factor)

    // find how many times 2 divides into num (handle all even numbers)
    while (num % 2 == 0) {
        factor_counts[2]++;
        num /= 2;
    }

    // find how many times each odd factor divides into num
    // only go up to the square root of num since it's the largest possible divisor
    for (int i = 3; i*i <= num; i += 2) {
        while (num % i == 0) {
            factor_counts[i]++;
            num /= i;
        }
    }
     
    // if num is still bigger than 2, that means it's prime, and that it's the last prime factor
    if (num > 2) factor_counts[num]++;

    // calculate divisors with the formula: (a+1) * (b+1) * (c+1) * (...)
    // where a, b, c are the exponents of the prime factors
    for (auto &factor : factor_counts) { // iterate through each key-value pair in the dictionary
        divisors *= (factor.second + 1); // .second accesses the value stored by the key
    }

    return divisors;
}

int main() {
    const int divisor_count = 500;
    int n = 1;

    while (true) {
        int triangle_num = (n * (n+1)) / 2; // use the formula
        
        int factors = count_divisors(triangle_num);

        if (factors > divisor_count) {
            std::cout << "First triangle number with over " << divisor_count << " divisors: " << triangle_num << std::endl;
            break;
        }

        n++;
    }

    return 0;
}