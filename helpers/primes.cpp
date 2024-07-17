#include <cmath>
#include <vector>
using namespace std;

//using long longs since the numbers can get really big
bool prime_Checker(long long num); //checks if a number is prime (duh)
vector<long long> prime_Finder(long long num); //finds all the prime numbers up to the given number (using the sieve of eratosthenes)
vector<long long> prime_Factors(long long num); //finds all the prime factors of a number
long long sum_primes(long long num); //finds the sum of all the primes up to the given number
long long sum_prime_Factors(long long num); //finds the sum of the prime factors of a given number

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

bool prime_Checker(long long num) {
    if (num <= 1) return false; //0 and 1 aren't prime
    if (num == 2) return true; //2 is prime
    if (num%2 == 0) return false; //exclude even numbers


    //only check odd divisors + only check up to the square root of the number
    for (long long i = 3; i <= sqrt(num); i += 2) {
        if (num%i == 0) return false;
    }

    return true;
}

vector<long long> prime_Finder(long long num) {
    vector<long long> primes;
    vector<bool> sieve(num+1, true);

    sieve[0] = sieve[1] = false; //0 and 1 aren't prime

    for (long long i = 2; i <= sqrt(num); i++) {
        if (sieve[i]) {
            for (long long j = i*i; j <= num; j += i) {
                sieve[j] = false;
            }
        }
    }

    for (long long i = 2; i <= num; i++) {
        if (sieve[i]) primes.push_back(i);
    }

    return primes;
}

vector<long long> prime_Factors(long long num) {
    vector<long long> factors;
    
    for (long long i = 2; i*i <= num; i++) {
        while (num%i == 0) {
            factors.push_back(i);
            num /= i;
        }
    }

    if (num > 1) factors.push_back(num);

    return factors;
}

long long sum_primes(long long num) {
    long long sum = 0;
    vector<long long> primes = prime_Finder(num);

    for (auto &num : primes) sum += num;

    return sum;
}

long long sum_prime_Factors(long long num) {
    long long sum = 0;
    vector<long long> factors = prime_Factors(num);

    for (auto &num : factors) sum += num;

    return sum;
}