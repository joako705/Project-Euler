// Problem URL: https://projecteuler.net/problem=4
// --------------------------------------------------------------------------------
// Find the largest palindrome made from the product of two 3-digit numbers

#include <iostream>
#include <algorithm> // for reverse()
#include <string>

int main() {
    int biggest_pal = 0;

    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) { // nested loop to check all combinations of 3-digit numbers
            int product = i*j;

            // convert the number to a string and reverse it
            std::string test_pal = std::to_string(product);
            std::string reversed_pal = test_pal;
            reverse(reversed_pal.begin(), reversed_pal.end()); // reverse() modifies the original string passed to it

            // if the original string and its reverse are equal, it's a palindrome
            if (test_pal == reversed_pal) {
                int num = stoi(test_pal); // convert the string back to an int
                if (biggest_pal < num) biggest_pal = num; // check and update the biggest number
            }
        }
    }

    std::cout << "Biggest palindrome made from the product of two 3-digit numbers: " << biggest_pal << std::endl;
    return 0;
}