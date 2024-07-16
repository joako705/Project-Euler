//sum of all the even fibonacci numbers below a certain limit

#include <iostream>
using namespace std;

int sum_even_fibs(int limit) {
    int a = 0, b = 1, sum = 0;

    while (b <= limit) {
        if (b % 2 == 0) {
            sum += b;
        }

        int temp = a;
        a = b;
        b += temp;
    }

    return sum;
}

main() {
    int limit = 0;

    cout << "Enter the limit: ";
    cin >> limit;

    cout << "Sum of all Fibonacci numbers below " << limit << ": " << sum_even_fibs(limit);
}