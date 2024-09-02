// Problem URL: https://projecteuler.net/problem=4
// -----------------------------------------------------------------------------------
// Find the largest palindrome made from the product of two 3-digit numbers

#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int biggest = 0;

    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) { // nested loop to check all combinations
            int product = i * j;

            std::string test_pal = std::to_string(product);
            std::string reversed_pal = test_pal;
            reverse(reversed_pal.begin(), reversed_pal.end());

            if (test_pal == reversed_pal) {
                int num = stoi(test_pal);
                if (biggest < num) biggest = num;
            }
        }
    }

    std::cout << "Biggest palindrome made from the product of two 3-digit numbers: " << biggest << std::endl;
    return 0;
}