// Problem URL: https://projecteuler.net/problem=6
// ---------------------------------------------------------------------------------------------------------------------------
// Find the difference between the sum of the squares and the square of the sum of the first 100 natural numbers

#include <iostream>
#include <cmath>

int main() {
    int sum = 0;

    for (int i = 1; i <= 100; i++) sum += i;
    sum = pow(sum, 2); // square of the sum

    for (int i = 1; i <= 100; i++) sum -= pow(i, 2); // minus every square
    
    std::cout << "Difference between the sum of the squares and the square of the sum (for the first 100 natural numbers): " << sum << std::endl;
    return 0;
}