// Disarrangement of balls


/*

You are given n balls numbered from 1 to n and there are n baskets numbered from 1 to n in front of you. The ith basket is meant for the ith ball. Calculate the number of ways in which no ball goes into its respective basket.


Input: n = 2
Output: 1
Explanation: For two balls {1, 2}, there is only one possible derangement {2, 1}.
*/





#include <iostream>
#include <vector>
using namespace std;







// Approach	     Time Complexity	Space Complexity
// Recursive	        O(2ⁿ)	       O(n)
// Memoization	        O(n)	       O(n)
// Tabulation	        O(n)	       O(n)
// Space Optimized	    O(n)	       O(1)



class Solution_Recursion {
  public:
    int countDer(int n) {
        // Base Case
        if (n == 1)
            return 0 ;
        if (n == 2)
            return 1 ;
    
        int ans = (n-1)*(countDer(n-1) + countDer(n-2)) ;

        return ans ;
    }
};






class Solution_Memoization {
    int solve(int n , vector<int>&dp)
    {
        // Base Case
        if (n == 1)
            return 0 ;
        if (n == 2)
            return 1 ;
            
        if (dp[n] != -1)
            return dp[n] ;
    
        dp[n] = (n-1)*(solve(n-1 , dp) + solve(n-2 , dp)) ;

        return dp[n] ;
    }
    
  public:
    int countDer(int n) {
        vector<int> dp(n+1 , -1) ;
    
        return solve(n , dp) ;
    }
};






class Solution_Tabulation {
    int solve(int n )
    {
        vector<int> dp(n+1 , -1) ;
        dp[1] = 0 ;
        dp[2] = 1 ;

        for (int i = 3 ; i <= n ; i++)
        {
            int first = dp[i-1] ;
            int second = dp[i-2] ;
            int sum = first + second ;

            int ans = (i-1)*sum ;
            dp[i] = ans ;
        }

        return dp[n] ;
    }
    
  public:
    int countDer(int n) {

        return solve(n) ;
    }
};






class Solution_SO {
    int solve(int n )
    {
        if (n == 1)
            return 0 ;
    

        int prev2 = 0 ;
        int prev1 = 1 ;

        for (int i = 3 ; i <= n ; i++)
        {
            int first = prev1 ;
            int second = prev2 ;
            int sum = first + second ;

            int ans = (i-1)*sum ;
            prev2 = prev1 ;
            prev1 = ans ;
        }

        return prev1 ;
    }
    
  public:
    int countDer(int n) {

        return solve(n) ;
    }
};






int main() {

    int n = 5;

    Solution_Recursion s1;
    Solution_Memoization s2;
    Solution_Tabulation s3;
    Solution_SO s4;

    cout << "Derangement of " << n << " using Recursion: " << s1.countDer(n) << endl;
    cout << "Derangement of " << n << " using Memoization: " << s2.countDer(n) << endl;
    cout << "Derangement of " << n << " using Tabulation: " << s3.countDer(n) << endl;
    cout << "Derangement of " << n << " using Space Optimization: " << s4.countDer(n) << endl;
    
    return 0;
}