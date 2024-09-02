// Problem URL: https://projecteuler.net/problem=7
// -------------------------------------------------------------------
// Find the 10,001st prime number

#include <iostream>
#include "../extras/primes.cpp"

int main() {
    int count = 0, num = 2;

    while (count < 10001) {
        if (is_prime(num)) count++;
        num++;
    }

    std::cout << "10,001st prime number: " << num - 1 << std::endl;
    return 0;
}