// Problem URL: https://projecteuler.net/problem=7
// --------------------------------------------------------------------------------
// Find the 10,001st prime number

#include <iostream>
#include "../extras/helpers.cpp" // for is_prime()

int main() {
    const int PrimeIndex = 100;
    int count = 0, num = 2; // num starts at 2, the first prime number

    while (count < PrimeIndex) { 
        if (is_prime(num)) count++; // increment count only if the number is prime
        num++;
    }

    // subtract 1 from num, since it'll have incremented an extra time after the loop breaks
    std::cout << "Prime #" << PrimeIndex << ": " << num-1 << std::endl;
    return 0;
}