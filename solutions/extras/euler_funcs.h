// #
// #############################################################################################################################
// ## These functions are used in more than one problem, so they're collected here to avoid duplicating the code each time :D ##
// #############################################################################################################################
// #

#include <vector>

// Finds the sum of all divisors of a number
long long sum_divisors(long long num);

// Checks if a number is prime
bool is_prime(long long num);

// Uses the Sieve of Eratosthenes to find all the primes up to the given number
std::vector<bool> prime_sieve(long long num);

// Uses prime_sieve to return all the prime numbers up to the given number in a vector
std::vector<long long> find_primes(long long num);

// Finds all the prime factors of a number
std::vector<long long> prime_factors(long long num);

// --------------------------------------------------------------------------------

long long sum_divisors(long long num) {
    if (num <= 1) return 0;

    long long div_sum = 1; // initialize at 1 and start the loop at 2, since 1 is a divisor of all numbers
    
    // only check up to the square root of the number, since the square root is the largest possible divisor
    for (long long i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            div_sum += i;
            long double complement_div = num/i; // calculate the complementary divisor to i

            // cast the result to an int and check if it's the same as i -- if it is, that means i is the square root of num
            // this check avoids counting i as a divisor twice
            if (i != int(complement_div)) {
                div_sum += complement_div;
            }
        }
    }

    return div_sum;
}

bool is_prime(long long num) {
    // skip 0, 1, all negative numbers, and all even numbers except for 2
    if (num == 2) return true;
    if ((num <= 1) || (num % 2 == 0)) return false;

    // only check odd divisors + only check up to the square root of the number (which is the largest possible divisor)
    for (long long i = 3; i*i <= num; i += 2) {
        if (num % i == 0) return false; // if the number is divisible, exit immediately since it's not prime
    }

    return true;
}

std::vector<bool> prime_sieve(long long num) {
    // a vector used to mark each number as prime or not
    std::vector<bool> sieve(num+1, true);

    sieve[0] = sieve[1] = false; // 0 and 1 aren't prime

    for (long long i = 2; i*i <= num; i++) {
        // if the number's index is marked as true, it's prime
        if (sieve[i]) {
            // and if it's prime, this nested loop will mark all multiples of the prime as false, since they'd be divisible by the prime and thus not prime themselves
            for (long long j = i*i; j <= num; j += i) {
                sieve[j] = false;
            }
        }
    }

    // by the time the loop is done, the vector will have only prime indices marked as true
    return sieve;
}

std::vector<long long> find_primes(long long num) {
    std::vector<long long> primes;
    std::vector<bool> sieve = prime_sieve(num); // initialize the sieve of using the prime_sieve()

    for (long long i = 2; i <= num; i++) {
        if (sieve[i]) primes.push_back(i); // if the number is marked as prime, add it to the vector
    }

    return primes;
}

std::vector<long long> prime_factors(long long num) {
    std::vector<long long> factors;

    // find how many times 2 divides into num
    while (num % 2 == 0) {
        factors.push_back(2);
        num /= 2;
    }

    // num must be odd at this point, so even numbers are skipped (only iterating up to the square root of the number)
    for (long long i = 3; i*i <= num; i += 2) {
        // check how many times i divides into num
        while (num % i == 0) {
            factors.push_back(i);
            num /= i;
        }
    }

    // if num is still bigger than 2 after the loops, it's a prime, which means it's the last prime factor
    if (num > 2) factors.push_back(num);
    return factors;
}