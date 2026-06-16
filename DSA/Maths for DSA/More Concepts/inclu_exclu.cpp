/*
This principle helps calculate the size of the union of multiple sets by considering overlaps.

Example:
Find how many integers from 1 to 100 are divisible by 2, 3, or 5.
*/


#include <iostream>
using namespace std;

int inclusionExclusion() {
    int n = 100, a = 2, b = 3, c = 5;

    // Divisors
    int countA = n / a;
    int countB = n / b;
    int countC = n / c;

    // Pairwise intersections
    int countAB = n / (a * b);
    int countBC = n / (b * c);
    int countAC = n / (a * c);

    // Triple intersection
    int countABC = n / (a * b * c);

    // Apply inclusion-exclusion principle
    return countA + countB + countC - countAB - countBC - countAC + countABC;
}

int main() {
    cout << inclusionExclusion() << endl;  // Output: 74
    return 0;
}
