// Problem URL: https://projecteuler.net/problem=145
// ---------------------------------------------------------------------------------
// Reversible numbers: numbers for which (n + reverse(n)) has only odd numbers
// ---------------------------------------------------------------------------------
// Find how many reversible numbers exist below 1 billion

#include <iostream>

bool all_odd(unsigned int x) {
    // continually remove digits from x and check if the last one is odd
    while (x > 0) {
        if (x % 2 == 0) return false; // if x's last digit is even, the whole number is even, which means it's not reversible
        x /= 10; // remove the last digit
    }

    return true;
}

bool is_reversible(unsigned int x) {
    unsigned int reversed = 0, original = x; // store x's original value

    while (x > 0) {
        reversed *= 10; // add a 0 to shift reversed's digits to the left
        reversed += x % 10; // add x's last digit to reversed
        x /= 10; // remove x's last digit
    }

    return all_odd(original + reversed);
}

int main() {
    const int Limit = 1e9;
    unsigned int count = 0;

    // the loop starts at 11 (to skip single-digit numbers), and skips all even numbers
    // count is incremented by 2 each time a reversible number is found, to count both the number and its reverse
    // for i + reverse(i) to have only odd digits, i must have only odd digits and reverse(i) only even digits (since odd + even = odd)
    // this means that reverse(i) would be even, and never be encountered by the loop, which is why it's accounted for when incrementing count twice
    for (unsigned int i = 11; i < Limit; i += 2) {
        if (is_reversible(i)) count += 2;
    }

    std::cout << "Reversible numbers below " << Limit << ": " << count << std::endl;
    return 0;
}