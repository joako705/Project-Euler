// Problem URL: https://projecteuler.net/problem=14
// ---------------------------------------------------------------------------------
// Collatz Sequence:
// n -> n/2 (if n is even)
// n -> 3n + 1 (if n is odd)
// ---------------------------------------------------------------------------------
// Find the starting number (under 1 million) that makes the longest sequence

#include <iostream>
#include <vector>

int main() {
    // using unsigned ints bc the numbers of the sequence should always be positive
    unsigned int chosen_one = 0;
    unsigned int longest = 0;

    for (unsigned int i = 2; i < 1000000; i++) {
        unsigned long long n = i;
        std::vector<unsigned int> sequence = { i };

        while (n != 1) {
            if (n % 2 == 0) n = n/2;
            else n = 3*n + 1;
            sequence.push_back(n);
        }

        if (longest < sequence.size()) {
            longest = sequence.size();
            chosen_one = sequence[0];
        }
    }

    std::cout << "The Chosen One is: " << chosen_one << std::endl;
    std::cout << "The length of the sequence it makes is: " << longest << std::endl;
    return 0;
}