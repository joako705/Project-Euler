//the largest prime factor of a specific number

#include <iostream>
#include <vector>
#include "helpers/primes.cpp"
using namespace std;

main() {
    long long num = 0, biggest = 0;
    cout << "Enter the number: ";
    cin >> num;

    vector<long long> factors = prime_Factors(num);

    for (auto &factor : factors) {
        biggest = max(biggest, factor);
    }

    cout << "Biggest prime factor of " << num << ": " << biggest;
}