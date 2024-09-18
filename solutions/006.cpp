// Problem URL: https://projecteuler.net/problem=6
// --------------------------------------------------------------------------------
// Find the difference between the sum of the squares and the square of the sum of the first 100 natural numbers

#include <iostream>

int main() {
    const int Limit = 100;
    int result = 0;

    for (int i = 1; i <= Limit; i++) result += i;
    result *= result; // square the sum

    for (int i = 1; i <= Limit; i++) result -= i*i; // subtract every square
    
    std::cout << "Difference of the sum of the squares and the square of the sum (for the first " << Limit << " natural numbers): " << result << std::endl;
    return 0;
}