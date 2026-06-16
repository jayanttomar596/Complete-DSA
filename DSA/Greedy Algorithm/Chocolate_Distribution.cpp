// Chocolate Distribution Problem





/*

Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
      i. Each student gets exactly one packet.
     ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.

Examples:

Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].

*/






#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




// Time Complexity: O(n log n)

// Space Complexity: O(1)







class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin() , a.end()) ;
        
        int i = 0 ; 
        int j = m-1 ;
        
        int mini = INT_MAX ;
        
        while( j < a.size())
        {
            int diff = a[j] - a[i] ;
            mini = min(mini , diff) ;
            i++ ;
            j++ ;
        }
        
        return mini ;
    }
};






// 💡 Why is this greedy?
// It makes locally optimal choices (choosing the smallest difference in each sorted window of size m) to achieve the global optimum.

// It doesn’t look ahead or go back (no recursion, no backtracking), it just assumes:
// “If I pick the smallest difference window now, it’ll be the best overall.”







int main() {

    Solution sol;

    // Sample Input
    vector<int> chocolates = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7; // Number of students

    // Function Call
    int result = sol.findMinDiff(chocolates, m);

    // Output the result
    cout << "Minimum difference is: " << result << endl;
    
    return 0;
}








