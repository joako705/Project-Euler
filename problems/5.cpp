//smallest number evenly divisible by all numbers from 1 to 20

#include <iostream>
using namespace std;

main() {
    int num = 20;
    
    while (true) {
        bool found = true;
        
        for (int i = 1; i <= 20; i++) {
            if (num%i != 0) {
                num++;
                found = false;
                break;
            }
        }

        if (found) break;
    }

    cout << "Smallest number evenly divisible by all numbers from 1 to 20: " << num;
}