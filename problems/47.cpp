//find the first four consecutive integers to have four *distinct* prime factors each

#include <iostream>
#include <vector>
#include <set>
#include "../helpers/primes.cpp"
using namespace std;

main() {
    int counter = 0;
    long long i = 1;

    while (counter < 4) {
        vector<long long> factors = prime_Factors(i);
        set<long long> distinct_factors(factors.begin(), factors.end());

        if (distinct_factors.size() >= 4) counter++;
        else counter = 0;
        i++;
    }

    cout << "The first of 4 consecutive integers to have 4 distinct prime factors each is: " << i-4;
}