// Problem URL: https://projecteuler.net/problem=44
// ---------------------------------------------------------------------------------
// Pentagonal number formula: (n * (3n - 1)) / 2
// ---------------------------------------------------------------------------------
// Find the pair of pentagonal numbers, j and k, for which:
// -> their sum and difference are both pentagonal
// -> d = |j - k| is minimized
// ---------------------------------------------------------------------------------
// What is the value of d?

#include <iostream>
#include <unordered_set> // for easy lookups
#include <vector>
#include <limits> // for std::numeric_limits
#include <cmath> // for std::abs()

std::vector<unsigned int> find_pentagonals(unsigned int n) {
    std::vector<unsigned int> pentagonals;

    // use the formula to calculate the first n pentagonal numbers
    for (unsigned int i = 1; i <= n; i++) {
        pentagonals.push_back((i * (3*i - 1)) / 2);
    }

    return pentagonals;
}

int main() {
    const unsigned int SearchLimit = 5000; // only generate the first 5000 pentagonal numbers
    unsigned int min_d = std::numeric_limits<unsigned int>::max(); // initialize min_d with the maximum possible value

    std::vector<unsigned int> pents = find_pentagonals(SearchLimit);
    std::unordered_set<unsigned int> pent_set(pents.begin(), pents.end()); // convert the vector to a set for faster lookups

    for (unsigned int j = 0; j < pents.size(); j++) {
        for (unsigned int k = j+1; k < pents.size(); k++) {
            unsigned int sum = pents[j] + pents[k];
            unsigned int diff = std::abs(static_cast<int>(pents[j] - pents[k]));

            if (pent_set.count(sum) && pent_set.count(diff)) {
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