// Problem URL: https://projecteuler.net/problem=21
// ----------------------------------------------------------------------
// Find the sum of all amicable numbers below 10000
// Amicable numbers: numbers whose sum of divisors is equal to each other

#include <iostream>
#include <vector>
#include "../extras/helpers.cpp"

bool are_amicable(int a, int b) {
    return (sum_divisors(a) == b) && (sum_divisors(b) == a);
}

int main() {
    int amicable_sum = 0;

    for (int i = 1; i < 10000; i++) {
        int j = sum_divisors(i);
        if (i != j && i == sum_divisors(j)) {
            amicable_sum += i;
        }
    }

    std::cout << "Sum of all amicable numbers under 10,000: " << amicable_sum << std::endl;
    return 0;
}