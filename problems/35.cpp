//find all the circular primes below 1 million
//circular primes are primes that remain prime for all rotations of their digits

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "../helpers/primes.cpp"
using namespace std;

vector<long long> find_rotations(long long n) {
    vector<long long> rotations;
    string num = to_string(n);

    for (auto &digit : num) {
        rotate(num.begin(), num.begin()+1, num.end());
        rotations.push_back(stoll(num));
    }

    return rotations;
}

main() {
    vector<long long> primes = prime_Finder(1000000);
    vector<long long> circulars;

    for (auto &num : primes) {
        vector<long long> rotations = find_rotations(num);
        vector<bool> tests(rotations.size(), true);

        for (unsigned int i = 0; i < rotations.size(); i++) {
            if (!prime_Checker(rotations[i])) {
                tests[i] = false;
                break;
            }
        }

        if (all_of(tests.begin(), tests.end(), [](bool i) { return i; })) circulars.push_back(num);
    }

    cout << "The number of circular primes below 1 million is: " << circulars.size();
}