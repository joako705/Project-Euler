// Problem URL: https://projecteuler.net/problem=14
// ---------------------------------------------------------------------------------
// Collatz Sequence:
// n -> n/2 (if n is even)
// n -> 3n + 1 (if n is odd)
// ---------------------------------------------------------------------------------
// Find the starting number (under 1 million) that makes the longest sequence

#include <iostream>

int main() {
    const unsigned int Limit = 1e6;

    // unsigned ints since the numbers of the sequence should always be positive
    unsigned int chosen_one = 0;
    unsigned int longest = 0;

    for (unsigned int i = 2; i < Limit; i++) {
        unsigned long long n = i; // work with n to not mess with the iterator
        unsigned int sequence = 0;

        while (n != 1) {
            if (n % 2 == 0) n = n/2;
            else n = 3*n + 1;
            sequence++;
        }

        if (longest < sequence) { // check the current sequence against the current longest length
            longest = sequence;
            chosen_one = i; // the first element is the starting number
        }
    }

    std::cout << "The Chosen One: " << chosen_one << std::endl;
    std::cout << "Length of the sequence it makes: " << longest << std::endl;
    return 0;
}