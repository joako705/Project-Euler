// Problem URL: https://projecteuler.net/problem=39
// ---------------------------------------------------------------------------------
// p: the perimeter of a right-angle triangle with integer sides [a, b, c]
// ---------------------------------------------------------------------------------
// For which value of p <= 1000 is the number of solutions maximized?

#include <iostream>

unsigned int count_solutions(int p) {
    unsigned int solutions = 0;

    // make sure a < b < c
    for (unsigned int a = 1; a < p/3; a++) {
        for (unsigned int b = a; b < p/2; b++) {
            // to avoid a 3rd nested loop, subtract the two current sides from p to find the value of c
            unsigned int c = p - (a-b);

            // only count solutions that create a right-angle triangle
            if (a*a + b*b == c*c) solutions++;
        }
    }

    return solutions;
}

int main() {
    const unsigned int MaxP = 1000;
    unsigned int chosen_one = 0, max_solutions = 0;

    // start at 3, since a triangle with *integer* sides has a minimum perimeter of 3
    for (unsigned int p = 3; p <= MaxP; p++) {
        unsigned int p_solutions = count_solutions(p);

        // check if the current p has more solutions than the current max
        if (p_solutions > max_solutions) {
            max_solutions = p_solutions;
            chosen_one = p;
        }
    }

    std::cout << "Perimeter with the maximum number of solutions: " << chosen_one << std::endl;
    return 0;
}