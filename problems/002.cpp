// Problem URL: https://projecteuler.net/problem=2
// --------------------------------------------------------------------------
// Find the sum of all the even Fibonacci numbers below 4 million

#include <iostream>

int sum_even_fibs(int max_value) {
    int a = 0, b = 1, sum = 0;

    while (b <= max_value) {
        if (b % 2 == 0) sum += b;

        int temp = a;
        a = b;
        b += temp;
    }

    return sum;
}

int main() {
    const int max_value = 4000000;

    std::cout << "Sum of all Fibonacci numbers below " << max_value << ": " << sum_even_fibs(max_value) << std::endl;
    return 0;
}