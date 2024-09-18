// Problem URL: https://projecteuler.net/problem=23
// ---------------------------------------------------------------------------
// Abundant number: a number for which the total_sum of its proper divisors is greater than itself
// Find the total_sum of all the positive integers which cannot be written as the total_sum of two abundant numbers

#include <iostream>
#include "extras/euler_funcs.h"

bool is_abundant(int num) {
    return sum_divisors(num) > num;
}

std::vector<int> find_abundants(int limit) {
    std::vector<int> abundants;

    for (int i = 12; i <= limit; i++) { // 12 is the smallest abundant number
        if (is_abundant(i)) abundants.push_back(i);
    }

    return abundants;
}

int main() {
    int total_sum = 0;
    const int limit = 28123;
    std::vector<int> abundants = find_abundants(limit);
    std::vector<bool> sum_of_abundants(limit+1, false); // keep track of which numbers (under the limit) can be written as the sum of two abundants

    for (int i = 24; i <= limit; i++) { // 24 is the smallest number that can be written as the total_sum of two abundant numbers
        for (auto &num : abundants) {
            if (num > i) break;

            if (is_abundant(i-num)) { // check if the difference is also an abundant number
                sum_of_abundants[i] = true; // mark that the number can be written as the sum of two abundants
                break;
            }
        }
    }

    for (int i = 0; i <= limit; i++) {
        if (!sum_of_abundants[i]) {
            total_sum += i;
        }
    }

    std::cout << "Sum of all positive integers that can't be written as the sum of two abundant numbers: " << total_sum << std::endl;
    return 0;
}