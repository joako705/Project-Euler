// Problem URL: https://projecteuler.net/problem=23
// ---------------------------------------------------------------------------------
// Abundant number: a number for which the total_sum of its proper divisors is greater than itself
// ---------------------------------------------------------------------------------
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers

#include <iostream>
#include "extras/euler_funcs.h" // for sum_divisors()

bool is_abundant(int num) {
    return sum_divisors(num) > num;
}

std::vector<int> find_abundants(int limit) {
    std::vector<int> abundants;

    // start at 12, since it's the smallest abundant number
    for (int i = 12; i <= limit; i++) {
        if (is_abundant(i)) abundants.push_back(i);
    }

    return abundants;
}

int main() {
    const int Limit = 28123; // all numbers larger than this limit *can* be written as the sum of two abundants
    int total_sum = 0;
    
    std::vector<int> abundants = find_abundants(Limit);
    std::vector<bool> sum_of_abundants(Limit+1, false); // to keep track of which numbers (under the limit) can be written as the sum of two abundants

    // start at 25, since 24 the smallest number that can be written as the sum of two abundants
    for (int i = 25; i <= Limit; i++) {
        for (auto &num : abundants) {
            if (num > i) continue; // if the abundant number is bigger than i, immediately go to the next abundant

            if (is_abundant(i-num)) { // check if the difference is also abundant
                sum_of_abundants[i] = true; // and if so, mark the number as true
                break;
            }
        }
    }

    // now that all the numbers that *can* be written as the sum of two abundants have been marked as true,
    // just go through all of them and add up the ones that are still false
    for (int i = 0; i <= Limit; i++) {
        if (!sum_of_abundants[i]) total_sum += i;
    }

    std::cout << "Sum of all positive integers that can't be written as the sum of two abundant numbers: " << total_sum << std::endl;
    return 0;
}