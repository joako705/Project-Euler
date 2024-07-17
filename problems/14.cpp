//collatz sequence:
//n -> n/2 (if n is even)
//n -> 3n+1 (if n is odd)
//find the starting number (under 1 million) that makes the longest sequence

#include <iostream>
#include <vector>
using namespace std;

main() {
    //they're all unsigned bc the numbers of the sequence should always be positive
    unsigned int chosen_one = 0;
    unsigned int longest = 0;

    for (unsigned int i = 2; i < 1000000; i++) {
        unsigned long long n = i; //long long bc the numbers can get massive
        vector<unsigned int> sequence = { i };

        while (n != 1) {
            if (n%2 == 0) n = n/2;
            else n = n*3 + 1;
            sequence.push_back(n);
        }

        if (longest < sequence.size()) {
            longest = sequence.size();
            chosen_one = sequence[0];
        }
    }

    cout << "The chosen one is: " << chosen_one << endl;
    cout << "The length of the sequence it makes is: " << longest;
}