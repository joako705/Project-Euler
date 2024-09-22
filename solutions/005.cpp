// Problem URL: https://projecteuler.net/problem=5
// --------------------------------------------------------------------------------
// Find the smallest number evenly divisible by all numbers from 1 to 20

#include <iostream>

int main() {
    const int N = 20;
    int num = N; // start at N since the number must be divisible by N
    
    while (true) {
        bool found = true;
        
        for (int i = 1; i <= N; i++) {
            if (num % i != 0) { // if it's not divisible by any of the numbers, increment num and break out of the for-loop
                num++;
                found = false;
                break;
            }
        }

        if (found) break; // if found is still true after the for-loop, the current num is the answer
    }

    std::cout << "Smallest number evenly divisible by all numbers from 1 to " << N << ": " << num << std::endl;
    return 0;
}