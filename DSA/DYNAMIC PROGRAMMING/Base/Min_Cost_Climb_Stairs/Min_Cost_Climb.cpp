#include <iostream>
#include <vector>
using namespace std;






// Approach	             Time Complexity	Space Complexity
// Recursion (Brute)	      O(2ⁿ)	              O(n)
// Memoization (Top-Down)	  O(n)	              O(n)
// Tabulation (Bottom-Up)	  O(n)	              O(n)
// Space Optimized DP	      O(n)	              O(1)





// T.C. -> O(2^N)
// S.C. -> O(N)

class Solution_Recursion {
    int solve(vector<int> &cost , int n)
    {
        // Base Case
        if (n == 0)
            return cost[0] ;
        if (n == 1)
            return cost[1] ;

        int ans = cost[n] + min(solve(cost , n-1) , solve(cost , n-2)) ;

        return ans ;        
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        
        int ans = min(solve(cost , n-1) , solve(cost , n-2)) ;

        return ans ;
    }
};





// Top Down Approach [Recursion + Memoization]
// T.C. -> O(N)
// S.C. -> O(N)

class Solution_Memoization {
    
    int solve(vector<int> &cost , int n , vector<int> &dp)
    {
        // BASE CASE
        if (n == 0)
            return cost[0] ;

        if (n == 1)
            return cost[1] ;

        // Step3
        if (dp[n] != -1)
            return dp[n] ;

        // Step2
        dp[n] = cost[n] + min(solve(cost , n-1 , dp) , solve(cost , n-2 , dp)) ;
        return dp[n] ;  
    }


public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size() ;
        
        // Step 1 
        vector<int> dp(n+1 , -1) ;
        int ans = min(solve(cost , n-1 , dp) , solve(cost , n-2 , dp)) ;

        return ans ;
    }
};





// Bottom Up Appraoch
// T.C. -> O(N)
// S.C. -> O(N)

class Solution_Tabulation {

    int solve(vector<int> &cost , int n)
    {
        // Step1 : Creation of dp array
        vector<int> dp(n+1) ;

        // Step2 : Base Case Analyse
        dp[0] = cost[0] ;
        dp[1] = cost[1] ;

        // Step3
        for (int i = 2 ; i < n ; i++)
        {
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]) ;
        }

        return min(dp[n-1] , dp[n-2]) ;
    }


public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size() ;
        return solve(cost , n) ;
    }
};






// Space Optimization
// T.C. -> O(N)
// S.C. -> O(1)

class Solution_Space {

    int solve(vector<int>& cost , int n)
    {
        int prev2 = cost[0] ;
        int prev1 = cost[1] ;

        for (int i = 2 ; i < n ; i++)
        {
            int curr = cost[i] + min(prev1 , prev2) ;
            prev2 = prev1 ;
            prev1 = curr ;
        }

        return min(prev1 , prev2) ;
    }


public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size() ;
        return solve(cost , n) ;

    }
};








int main() {


    // Example 1: Simple case
    vector<int> cost1 = {10, 15, 20};
    Solution_Recursion sol1;
    cout << "\n\nMinimum cost for climbing stairs (Example 1): " << sol1.minCostClimbingStairs(cost1) << endl;

    // Example 2: Larger input
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost for climbing stairs (Example 2): " << sol1.minCostClimbingStairs(cost2) << endl;






    
    Solution_Recursion sol2;
    cout << "\n\nMinimum cost for climbing stairs (Example 1): " << sol2.minCostClimbingStairs(cost1) << endl;

    
    cout << "Minimum cost for climbing stairs (Example 2): " << sol2.minCostClimbingStairs(cost2) << endl;






    
    Solution_Memoization sol3;
    cout << "\n\nMinimum cost for climbing stairs (Example 1): " << sol3.minCostClimbingStairs(cost1) << endl;

    
    cout << "Minimum cost for climbing stairs (Example 2): " << sol3.minCostClimbingStairs(cost2) << endl;






    
    Solution_Space sol4;
    cout << "\n\nMinimum cost for climbing stairs (Example 1): " << sol4.minCostClimbingStairs(cost1) << endl;

    
    cout << "Minimum cost for climbing stairs (Example 2): " << sol4.minCostClimbingStairs(cost2) << endl;
    


    
    return 0;
}





