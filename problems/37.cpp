//find the sum of all the truncatable primes
//truncatable primes are primes that can continuously have their digits removed from either end and still be prime

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "../helpers/primes.cpp"
using namespace std;

main() {
    vector<long long> primes = prime_Finder(1000000);
    vector<long long> truncatable;
    long long sum_truncs = 0;

    for (auto &num : primes) {
        string str_num = to_string(num);
        vector<bool> tests(str_num.size(), true);

        for (unsigned int i = 0; i < str_num.size(); i++) {
            string left = str_num.substr(i);
            string right = str_num.substr(0, str_num.size()-i);

            if (!prime_Checker(stoll(left)) || !prime_Checker(stoll(right))) {
                tests[i] = false;
                break;
            }
        }

        if (all_of(tests.begin(), tests.end(), [](bool i) { return i; })) truncatable.push_back(num);
    }

    for (unsigned int i = 4; i < truncatable.size(); i++) sum_truncs += truncatable[i];

    cout << "The sum of all truncatable primes is: " << sum_truncs;
}