#include <cmath>
#include <vector>
using namespace std;

//using long longs since the numbers can get really big

//checks if a number is prime (duh)
bool prime_Checker(long long num) {
    if (num <= 1) return false;

    for (long long i = 2; i <= sqrt(num); i++) { //only need to check up to the square root of the number for optimization reasons
        if (num % i == 0) return false;
    }

    return true;
}

//finds all the prime number in the given range
vector<long long> prime_Finder(long long start, long long end) {
    vector<long long> primes;

    for (int i = start; i <= end; i++) {
        if (prime_Checker(i)) primes.push_back(i);
    }

    return primes;
}

//finds the sum of all the primes up to the given limit
long long sum_primes(long long limit) {
    long long sum = 0;
    vector<long long> primes = prime_Finder(2, limit);

    for (auto &num : primes) sum += num;

    return sum;
}

//finds all the prime factors of a number
vector<long long> prime_Factors(long long num) {
    vector<long long> factors;
    
    for (long long i = 2; i <= sqrt(num); i++) {
        while (num % i == 0) {
            if (prime_Checker(i)) {
                factors.push_back(i);
            }
            
            num /= i;
        }
    }

    if ((num > 1) && (prime_Checker(num))) {
        factors.push_back(num);
    }

    return factors;
}

//finds the sum of the prime factors of a given number
long long sum_prime_Factors(long long num) {
    long long sum = 0;
    vector<long long> factors = prime_Factors(num);

    for (auto &num : factors) sum += num;

    return sum;
}