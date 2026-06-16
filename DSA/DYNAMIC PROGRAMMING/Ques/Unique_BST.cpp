// Unique Binary Search Trees




/*

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1


*/







#include <iostream>
#include <vector>
using namespace std;








// | Approach                | Time Complexity | Space Complexity |
// | ----------------------- | --------------- | ---------------- |
// | Recursion               | O(2ⁿ)           | O(n)             |
// | Recursion + Memoization | O(n²)           | O(n)             |
// | Tabulation (DP)         | O(n²)           | O(n)             |








class Recursion {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1 ;
        
        int ans = 0 ;
        // Think i as root node
        for (int i = 1 ; i <= n ; i++)
            ans += numTrees(i-1) * numTrees(n-i) ;
        
        return ans ;
    }
};








class Recursion_Memoization {
    int solve(int n , vector<int>& dp)
    {
        if (n <= 1)
            return 1 ;
        
        if (dp[n] != -1)
            return dp[n] ;
        
        int ans = 0 ;
        // Think i as root node
        for (int i = 1 ; i <= n ; i++)
            ans += solve(i-1 , dp) * solve(n-i , dp) ;
        
        return dp[n] = ans ;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1 , -1) ;
        return solve(n , dp) ;
    }
};









class Tabulation {
    int solve(int n)
    {
        vector<int> dp(n+1 , 0) ;
        dp[0] = dp[1] = 1 ;

        // i -> number of nodes
        for (int i = 2 ; i <= n ; i++)
        {
            // j -> root node
            for (int j = 1 ; j <= i ; j++)
            {
                dp[i] += dp[j-1]*dp[i-j] ;
            }
        }
        
        return dp[n] ;
    }
public:
    int numTrees(int n) {
        return solve(n) ;
    }
};








int main() {

    int n = 5; // You can change this value to test other inputs

    // Using Recursion
    Recursion r;
    int res1 = r.numTrees(n);
    cout << "Recursion result for n = " << n << " is: " << res1 << endl;

    // Using Recursion + Memoization
    Recursion_Memoization rm;
    int res2 = rm.numTrees(n);
    cout << "Recursion + Memoization result for n = " << n << " is: " << res2 << endl;

    // Using Tabulation
    Tabulation t;
    int res3 = t.numTrees(n);
    cout << "Tabulation result for n = " << n << " is: " << res3 << endl;
    
    return 0;
}










