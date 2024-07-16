//10,001st prime number

#include <iostream>
#include "helpers/primes.cpp"
using namespace std;

main() {
    int count = 0, i = 2;

    while (count < 10001) {
        if (prime_Checker(i)) {
            count++;
        }

        i++;
    }

    cout << "10,001st prime number: " << i-1;
}