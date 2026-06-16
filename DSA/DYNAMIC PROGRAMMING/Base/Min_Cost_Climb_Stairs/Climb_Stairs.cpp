#include <iostream>
#include <vector>
using namespace std;




// Simple Recursion
// T.C. -> O(2^N)
// S.C. -> O(N)

/*

This recursive formula leads to a binary tree of calls, where each call makes two more recursive calls, similar to computing Fibonacci numbers.

The number of calls grows exponentially with nStairs.

Specifically, the time complexity is: o(2^n)







This is due to the function call stack created by recursion:

At most, the recursive call stack will have n function calls (in the worst-case path of all n decreasing to 0).


*/


long long int  count_ways_to_climbstairs(long long nStairs)
{

    // Base Case
    if (nStairs < 0)
        return 0 ;

    if (nStairs == 0)
        return 1 ;

    // Recursion Call
    return count_ways_to_climbstairs(nStairs - 1) + count_ways_to_climbstairs(nStairs - 2);
}





// 2nd Reccursion method 
class Solution_2
{
private : 
    int solve(long long nStairs , int i)
    {
        // Base Case
        if ( i == nStairs)
            return 1 ;
        
        if (i > nStairs)
            return 0 ;
        
        return (solve(nStairs , i+1) + solve(nStairs , i+2) ) ;
    }


    int countDistinctWayToClimbStair(long long nStairs)
    {
        int ans = solve(nStairs , 0) ;

        return ans ;
    }
};



class Solution_2_dp
{
private:
    // Memoization to store already computed values
    std::vector<int> dp;

    int solve(long long nStairs, int i)
    {
        // Base Case
        if (i == nStairs)
            return 1;  // 1 way to reach the top (i == nStairs)
        
        if (i > nStairs)
            return 0;  // No way to go beyond the top

        // If the result is already computed, return it
        if (dp[i] != -1)
            return dp[i];

        // Recursive step: sum of ways from i+1 and i+2
        dp[i] = solve(nStairs, i + 1) + solve(nStairs, i + 2);

        return dp[i];
    }    
};






// Recursion + Memoization Approach
// T.C. -> O(N)
// S.C. -> O(N)  { O(N) + O(N) }

class Solution {
    int rec(int n , vector<int> &dp)
    {
        if (n < 0)
            return 0 ;

        if ( n == 0)
            return 1 ;

        if (dp[n] != -1)
        {
            return dp[n] ;
        }    

        dp[n] = rec(n-1 , dp) + rec(n-2 , dp) ;
        return dp[n] ;
    }

public:
    int climbStairs(int n) 
    {
        vector<int> dp(n+1 , -1) ;

        return rec(n , dp) ;
    }
};






int main() {


    Solution sol;

    // Test Cases
    int test1 = 2;
    int test2 = 3;
    int test3 = 5;

    
    cout << "Ways to climb " << test1 << " steps: " << sol.climbStairs(test1) << endl;
    cout << "Ways to climb " << test2 << " steps: " << sol.climbStairs(test2) << endl;
    cout << "Ways to climb " << test3 << " steps: " << sol.climbStairs(test3) << endl;
    

    return 0;
}





