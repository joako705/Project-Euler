//sum of all the multiples of 3 and 5 below a limit

#include <iostream>
using namespace std;

main() {
    int limit = 0, sum = 0;
    cout << "Enter the limit: ";
    cin >> limit;

    for (int i = 0; i < limit; i++) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            sum += i;
        }
    }

    cout << "Sum of all the multiples of 3 and 5 below " << limit << ": " << sum;
}