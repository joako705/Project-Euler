// Problem URL: https://projecteuler.net/problem=5
// ------------------------------------------------------------------------------------
// Find the smallest number evenly divisible by all numbers from 1 to 20

#include <iostream>

int main() {
    int num = 20;
    
    while (true) {
        bool found = true;
        
        for (int i = 1; i <= 20; i++) {
            if (num % i != 0) {
                num++;
                found = false;
                break;
            }
        }

        if (found) break;
    }

    std::cout << "Smallest number evenly divisible by all numbers from 1 to 20: " << num << std::endl;
    return 0;
}