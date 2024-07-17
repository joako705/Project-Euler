//nth triangle number: sum of natural numbers up to n
//find the first triangle number with over 500 divisors

#include <iostream>
#include <cmath>
#include <map>
using namespace std;

long long count_divisors(long long num) {
    long long divisors = 1;
    map<long long, long long> factor_counts; //dictionary where the keys are the prime factors and the values are the exponents

    //handle 2 (and all even factors)
    while (num % 2 == 0) {
        factor_counts[2]++;
        num /= 2;
    }

    //handle odd factors
    for (long long i = 3; i <= sqrt(num); i += 2) {
        while (num%i == 0) {
            factor_counts[i]++;
            num /= i;
        }
    }
     
    //handle remaining prime factors
    if (num > 2) factor_counts[num]++;

    //calculate divisors with the formula: (a+1) * (b+1) * (c+1) * ...
    //where a, b, c are the exponents of the prime factors
    for (auto &factor : factor_counts) {
        divisors *= (factor.second + 1);
    }

    return divisors;
}

main() {
    long long num = 1, triangle_num = 1;

    while (true) {
        triangle_num = (num * (num+1)) / 2; //formula for nth triangle number
        
        long long factors = count_divisors(triangle_num);

        if (factors > 500) {
            cout << "The first triangle number with over 500 divisors: " << triangle_num;
            break;
        }

        num++;
    }
}