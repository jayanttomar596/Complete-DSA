/*
4. Pigeonhole Principle
This principle states: If you put 
𝑛
n items into 
𝑚
m containers, and 
𝑛
>
𝑚
n>m, at least one container must contain more than one item.

Example 1:
If there are 13 people, at least 2 of them must have their birthday in the same month.
Why? There are only 12 months, so with 13 people, one month must repeat.
Example 2:
In a group of 367 people, at least 2 have the same birthday.
Why? There are only 366 possible birthdays (including February 29).
Applications:
Proving existence (e.g., two people with the same score in a test).
Finding duplicates in arrays.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    vector<int> duplicates;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            duplicates.push_back(num);
        } else {
            seen.insert(num);
        }
    }
    return duplicates;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 3, 5, 4};
    vector<int> duplicates = findDuplicates(nums);

    for (int dup : duplicates) {
        cout << dup << " ";
    }
    return 0;
}



