// Problem URL: https://projecteuler.net/problem=37
// -----------------------------------------------------------------------------------------------------------------------
// Find the sum of all the truncatable primes
// Truncatable primes are primes that can continuously have their digits removed from either end and still be prime

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "../extras/primes.cpp"

int main() {
    std::vector<long long> primes = find_primes(1000000);
    std::vector<long long> truncatable;
    long long sum_truncs = 0;

    for (auto &num : primes) {
        std::string str_num = std::to_string(num);
        std::vector<bool> tests(str_num.size(), true);

        for (unsigned int i = 0; i < str_num.size(); i++) {
            std::string left = str_num.substr(i);
            std::string right = str_num.substr(0, str_num.size()-i);

            if (!is_prime(stoll(left)) || !is_prime(stoll(right))) {
                tests[i] = false;
                break;
            }
        }

        if (all_of(tests.begin(), tests.end(), [](bool i) { return i; })) truncatable.push_back(num);
    }

    for (unsigned int i = 4; i < truncatable.size(); i++) sum_truncs += truncatable[i];

    std::cout << "The sum of all truncatable primes is: " << sum_truncs << std::endl;
    return 0;
}