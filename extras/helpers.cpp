#include <vector>
#include <cmath>

// Finds the sum of all divisors of a number
long long sum_divisors(long long num);

// Checks if a number is prime
bool is_prime(long long num);

// Uses Sieve of Eratosthenes to find all the primes up to the given number
std::vector<bool> prime_sieve(long long num);

// Returns all the prime numbers up to the given number as a vector using prime_sieve()
std::vector<long long> find_primes(long long num);

// Finds all the prime factors of a number
std::vector<long long> prime_factors(long long num);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

long long sum_divisors(long long num) {
    if (num <= 1) return 0;

    long long div_sum = 1; // 1 is a divisor of any number
    long long sqrt_num = llround(sqrt(num)); // only check up to the square root of the number

    for (long long i = 2; i <= sqrt_num; i++) {
        if (num % i == 0) {
            div_sum += i;
            if (i != num/i) {
                div_sum += num/i;
            }
        }
    }

    return div_sum;
}

bool is_prime(long long num) {
    // skip 0, 1, and all even numbers except for 2 (and negative numbers)
    if (num == 2) return true;
    if ((num <= 1) || (num % 2 == 0)) return false;

    // only check odd divisors + only check up to the square root of the number
    for (long long i = 3; i*i <= num; i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

std::vector<bool> prime_sieve(long long num) {
    std::vector<bool> sieve(num+1, true);

    sieve[0] = sieve[1] = false; // 0 and 1 aren't prime

    for (long long i = 2; i*i <= num; i++) {
        if (sieve[i]) {
            for (long long j = i*i; j <= num; j += i) {
                sieve[j] = false;
            }
        }
    }

    return sieve;
}

std::vector<long long> find_primes(long long num) {
    std::vector<long long> primes;
    std::vector<bool> sieve = prime_sieve(num);

    for (long long i = 2; i <= num; i++) {
        if (sieve[i]) primes.push_back(i);
    }

    return primes;
}

std::vector<long long> prime_factors(long long num) {
    std::vector<long long> factors;
    
    for (long long i = 2; i*i <= num; i++) {
        while (num % i == 0) {
            factors.push_back(i);
            num /= i;
        }
    }

    if (num > 1) factors.push_back(num);

    return factors;
}