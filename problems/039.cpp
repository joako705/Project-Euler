// Problem URL: https://projecteuler.net/problem=39
// -----------------------------------------------------------------
// p is the perimeter of a right-angle triangle with integer sides {a, b, c}
// For which value of p <= 1000 is the number of solutions maximized?

#include <iostream>

int count_solutions(int p) {
    int solutions = 0;

    // make sure a <= b <= c
    for (int a = 1; a < p/3; a++) {
        for (int b = a; b < p/2; b++) {
            int c = p - a - b;

            // only count solutions that create a right-angle triangle
            if (a*a + b*b == c*c) solutions++;
        }
    }

    return solutions;
}

int main() {
    int chosen_one = 0, max_solutions = 0;

    for (int p = 3; p <= 1000; p++) {
        int temp = count_solutions(p);

        if (temp > max_solutions) {
            max_solutions = temp;
            chosen_one = p;
        }
    }

    std::cout << "Perimeter that has the maximum number of solutions: " << chosen_one << std::endl;
    return 0;
}