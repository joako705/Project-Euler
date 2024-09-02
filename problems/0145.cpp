// Problem URL: https://projecteuler.net/problem=145
// -------------------------------------------------------------------------------------------
// Reversible numbers: numbers for which (n + reverse(n)) has only odd numbers
// -------------------------------------------------------------------------------------------
// Find how many reversible numbers exist below 1 billion

#include <iostream>
#include <cmath>

unsigned int reverse_num(unsigned int x) {
    unsigned int result = 0;

    while (x > 0) {
        result *= 10;
        result += x % 10;
        x /= 10;
    }

    return result;
}

bool all_odd(unsigned int x) {
    while (x > 0) {
        if (x % 2 == 0) return false;
        x /= 10;
    }

    return true;
}

int main() {
    unsigned int count = 0;

    for (unsigned int i = 11; i < pow(10, 8); i += 2) {
        if (all_odd(i + reverse_num(i))) count += 2;
    }

    std::cout << count << std::endl;
    return 0;
}