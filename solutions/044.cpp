// Problem URL: https://projecteuler.net/problem=44
// -----------------------------------------------------------------------------------------------------------
// Pentagonal number formula: (n * (3n - 1)) / 2
// -----------------------------------------------------------------------------------------------------------
// Find the pair of pentagonal numbers, j and k, for which their sum and difference are both pentagonal,
// and for which d = |j - k| is minimized. What is the value of d?

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

std::vector<unsigned int> find_pentagonals(int n) {
    std::vector<unsigned int> pentagonals;

    for (int i = 1; i <= n; i++) {
        pentagonals.push_back((i * (3*i - 1)) / 2);
    }

    return pentagonals;
}

bool is_pentagonal(unsigned int x) {
    // if this formula returns a natural number, then the given number x is the nth pentagonal number
    // further reading and such: https://en.wikipedia.org/wiki/Pentagonal_number#Tests_for_pentagonal_numbers
    
    double n = (1 + sqrt(24 * x + 1)) / 6;
    return n == int(n);
}

int main() {
    std::vector<unsigned int> pents = find_pentagonals(10000);
    int min_d = std::numeric_limits<int>::max(); // initialize min_d with the max possible value

    for (unsigned int j = 0; j < pents.size(); j++) {
        for (unsigned int k = j+1; k < pents.size(); k++) {
            int sum = pents[j] + pents[k];
            int diff = std::abs(int(pents[j] - pents[k]));

            if (is_pentagonal(sum) && is_pentagonal(diff)) {
                if (diff < min_d) { // if a smaller value is found, break out of the loop early
                    min_d = diff;
                    break;
                }
            }
        }
    }

    std::cout << "Minimum difference produced by two pentagonal numbers: " << min_d << std::endl;
    return 0;
}