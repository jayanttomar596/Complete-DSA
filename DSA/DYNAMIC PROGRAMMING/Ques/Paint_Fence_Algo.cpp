// Painting the Fence



/*

Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.
Answers are guaranteed to be fit into a 32 bit integer.

Examples:

Input: n = 3, k = 2 
Output: 6
Explanation: Let the 2 colours be 'R' and 'B'. We have following possible combinations:
1. RRB
2. RBR
3. RBB
4. BRR
5. BRB
6. BBR

*/






#include <iostream>
#include <vector>
using namespace std;





// Approach	                 Time Complexity	Space Complexity
// Recursion	                    O(2ⁿ)	       O(n)
// Recursion + Memoization	        O(n)	       O(n)
// Tabulation	                    O(n)	       O(n)
// Space Optimized	                O(n)	       O(1)



class Recursion {
    int solve(int n , int k )
    {
        // Base Case
        if (n == 1)
            return k ;
        if (n == 2)
            return k*k ;
        
        int ans = (k-1)*(solve(n-2 , k ) + solve(n-1 , k )) ;
        return ans ;
    }
  public:
    int countWays(int n, int k) {
        return solve(n , k ) ;
        
    }
};







class Recursion_Memoization {
    int solve(int n , int k , vector<int> &dp)
    {
        // Base Case
        if (n == 1)
            return k ;
        if (n == 2)
            return k*k ;
        
        if (dp[n] != -1)
            return dp[n] ;
        
        dp[n] = (k-1)*(solve(n-2 , k , dp) + solve(n-1 , k , dp)) ;
        return dp[n] ;
    }
  public:
    int countWays(int n, int k) {
        vector<int> dp(n+1 , -1) ;
        return solve(n , k , dp) ;
        
    }
};








class Tabulation {
    
    int solve(int n , int k )
    {
        vector<int> dp(n+1 , -1) ;
        
        dp[1] = k ;
        dp[2] = k*k ;
        
        for (int i = 3 ; i <= n ; i++)
        {
            dp[i] = (k-1)*(dp[i-2] + dp[i-1]) ;
        }
        
        return dp[n] ;
    }
    
    
  public:
    int countWays(int n, int k) {
        return solve(n , k ) ;
        
    }
};






class SO {
    
    int solve(int n , int k )
    {
        if (n == 1)
        {
            return k ;
        }
        
        vector<int> dp(n+1 , -1) ;
        
        int prev2 = k ;
        int prev1 = k*k ;
    
        for (int i = 3 ; i <= n ; i++)
        {
            int ans = (k-1)*(prev2 + prev1) ;
            prev2 = prev1 ;
            prev1 = ans ;
        }
        
        return prev1 ;
    }
    
    
  public:
    int countWays(int n, int k) {
        return solve(n , k ) ;
        
    }
};







int main() {


    int n = 5, k = 3; // Example: 5 posts, 3 colors

    Recursion r;
    Recursion_Memoization rm;
    Tabulation tab;
    SO opt;

    cout << "Recursion: " << r.countWays(n, k) << endl;
    cout << "Recursion + Memoization: " << rm.countWays(n, k) << endl;
    cout << "Tabulation: " << tab.countWays(n, k) << endl;
    cout << "Space Optimized: " << opt.countWays(n, k) << endl;


    
    return 0;
}


