// #
// ##################################################################################################
// ## I use these functions in more than one problem, so I collected them into this header file :D ##
// ##################################################################################################
// #

#include <vector>
#include <cmath>

// Finds the sum of divisors of a number
long long sum_divisors(long long num);

// Checks if a number is prime
bool is_prime(long long num);

// Uses the Sieve of Eratosthenes to find all primes up to the given number
std::vector<bool> prime_sieve(long long num);

// Uses prime_sieve() to return all primes up to the given number as a vector
std::vector<long long> find_primes(long long num);

// Uses prime factorization to find all of the given number's prime factors
std::vector<long long> prime_factors(long long num);

// --------------------------------------------------------------------------------

long long sum_divisors(long long num) {
    if (num <= 1) return 0;

    long long sqrt_num = static_cast<long long>(std::sqrt(num)); // precalculate sqrt(num) beforehand
    long long div_sum = 1; // initialize at 1 and start the loop at 2, since 1 is a divisor of all numbers
    
    // only check up to the square root of the number, since the square root is the largest possible divisor
    for (long long i = 2; i <= sqrt_num; i++) {
        if (num % i == 0) {
            div_sum += i;
            auto complement_div = num/i; // calculate the complementary divisor to i

            // check if complement_div is the same as i -- if it is, that means i is the square root of num
            // this check avoids counting i as a divisor twice
            if (i != complement_div) div_sum += complement_div;
        }
    }

    return div_sum;
}

bool is_prime(long long num) {
    // skip 0, 1, all negative numbers, and all even numbers except for 2
    if (num == 2) return true;
    if ((num <= 1) || (num % 2 == 0)) return false;

    long long sqrt_num = static_cast<long long>(std::sqrt(num)); // precalculate sqrt(num) beforehand

    // only check odd divisors + only check up to the square root of the number, since it's the largest possible divisor
    for (long long i = 3; i <= sqrt_num; i += 2) {
        if (num % i == 0) return false; // if the number is divisible, exit immediately since it's not prime
    }

    return true;
}

std::vector<bool> prime_sieve(long long num) {
    std::vector<bool> sieve(num+1, true); // used to mark each number as prime or not
    long long sqrt_num = static_cast<long long>(std::sqrt(num)); // precalculate sqrt(num) beforehand

    sieve[0] = sieve[1] = false; // 0 and 1 aren't prime

    for (long long i = 2; i <= sqrt_num; i++) {
        if (sieve[i]) { // if the number is prime:
            // this nested loop will mark all multiples of the prime as false, since they'd be divisible by it and thus not prime themselves
            for (long long j = i*i; j <= num; j += i) {
                sieve[j] = false;
            }
        }
    }

    // by the time the loop is done, the vector will only have prime indices marked as true
    return sieve;
}

std::vector<long long> find_primes(long long num) {
    std::vector<long long> primes;
    std::vector<bool> sieve = prime_sieve(num); // initialize using prime_sieve()

    for (long long i = 2; i <= num; i++) {
        if (sieve[i]) primes.push_back(i); // if the number is marked as prime, add it to the vector
    }

    return primes;
}

std::vector<long long> prime_factors(long long num) {
    std::vector<long long> factors;
    long long sqrt_num = static_cast<long long>(std::sqrt(num)); // precalculate sqrt(num) beforehand

    // find how many times 2 divides into num (and remove all other even factors)
    while (num % 2 == 0) {
        factors.push_back(2);
        num /= 2;
    }

    // find how many times each odd factor divides into num
    // only go up to the square root of num since it's the largest possible divisor
    for (long long i = 3; i <= sqrt_num; i += 2) {
        while (num % i == 0) {
            factors.push_back(i);
            num /= i;
        }
    }

    // if num is still bigger than 2, that means it's prime and the last prime factor
    if (num > 2) factors.push_back(num);
    return factors;
}