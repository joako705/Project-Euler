// Problem URL: https://projecteuler.net/problem=2
// --------------------------------------------------------------------------------
// Find the sum of all the even Fibonacci numbers below 4 million

#include <iostream>

int sum_even_fibs(int limit) {
    int a = 0, b = 1, fib_sum = 0;

    while (b <= limit) {
        // check evenness
        if (b % 2 == 0) fib_sum += b;

        int temp = a; // save a's value for when it gets overwritten by b
        a = b;
        b += temp;
    }

    return fib_sum;
}

int main() {
    const int Limit = 4000000;

    std::cout << "Sum of all even Fibonacci numbers below " << Limit << ": " << sum_even_fibs(Limit) << std::endl;
    return 0;
}