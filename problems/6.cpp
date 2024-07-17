//find the difference between the sum of the squares and the square of the sum (first 100 natural numbers)

#include <iostream>
#include <cmath>
using namespace std;

main() {
    int sum = 0;

    for (int i = 1; i <= 100; i++) sum += i;
    sum = pow(sum, 2); //square of the sum

    for (int i = 1; i <= 100; i++) sum -= pow(i, 2); //minus every square
    
    cout << "Difference between the sum of the squares and the square of the sum (for the first 100 natural numbers): " << sum;
}