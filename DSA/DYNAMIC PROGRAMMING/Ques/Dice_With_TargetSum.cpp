// Number of Dice Rolls With Target Sum





/*

You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

*/





#include <iostream>
#include <vector>
using namespace std;








// | Approach                   | Time Complexity     | Space Complexity |
// | -------------------------- | ------------------- | ---------------- |
// | Recursion                  | O(k^n)              | O(n)             |
// | Recursion + Memoization    | O(n * target * k)   | O(n * target)    |
// | Tabulation                 | O(n * target * k)   | O(n * target)    |
// | Space Optimized Tabulation | O(n * target * k)   | O(target)        |








class Recursion {
    int solve(int dice , int faces , int target)
    {
        // Base Case
        if (target < 0)
            return 0 ;
        
        if (dice == 0 && target != 0)
            return 0 ;
        
        if (target == 0 && dice != 0)
            return 0 ;
        
        if (dice == 0 && target == 0)
            return 1 ;
        
        int ans = 0 ;
        for (int i = 1 ; i <= faces ; i++)
        {
            ans = ans + solve(dice-1 , faces , target-i) ;
        }

        return ans ;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n , k , target) ;
    }
};









class Recursion_Memoization {
    int solve(int dice , int faces , int target , vector<vector<int>> &dp)
    {
        // Base Case
        if (target < 0)
            return 0 ;
        
        if (dice == 0 && target != 0)
            return 0 ;
        
        if (target == 0 && dice != 0)
            return 0 ;
        
        if (dice == 0 && target == 0)
            return 1 ;

        if (dp[dice][target] != -1)
            return dp[dice][target] ;
        
        int ans = 0 ;
        for (int i = 1 ; i <= faces ; i++)
        {
            ans = ans%1000000007 + solve(dice-1 , faces , target-i , dp)%1000000007 ;
        }

        return dp[dice][target] = (ans)%(1000000007) ;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1)) ;
        return solve(n , k , target , dp) ;
    }
};








class  Tabulation {
    int solve(int d , int faces , int t)
    {
        vector<vector<int>> dp(d+1 , vector<int> (t+1 , 0)) ;
        // After analysing base case
        dp[0][0] = 1 ;

        for (int dice = 1 ; dice <= d ; dice++)
        {
            for (int target = 1 ; target <= t ; target++)
            {
                int ans = 0 ;
                for (int i = 1 ; i <= faces ; i++)
                {
                    if (target - i >= 0)
                        ans = ans%1000000007 + dp[dice-1][target-i]%1000000007 ;
                }
                dp[dice][target] = ans%1000000007 ;
            }
        }

        return dp[d][t] ;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n , k , target) ;
    }
};









class SO {
    int solve(int d , int faces , int t)
    {
        vector<int> prev(t+1 , 0) ;
        vector<int> curr(t+1 , 0) ;

        // After analysing base case
        prev[0] = 1 ;

        for (int dice = 1 ; dice <= d ; dice++)
        {
            for (int target = 1 ; target <= t ; target++)
            {
                int ans = 0 ;
                for (int i = 1 ; i <= faces ; i++)
                {
                    if (target - i >= 0)
                        ans = ans%1000000007 + prev[target-i]%1000000007 ;
                }
                curr[target] = ans%1000000007 ;
            }
            prev = curr ;
        }

        return prev[t] ;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n , k , target) ;
    }
};









int main() {


    int n = 3, k = 6, target = 7;

    Recursion r;
    Recursion_Memoization rm;
    Tabulation tab;
    SO so;

    cout << "Pure Recursion Output: " << r.numRollsToTarget(n, k, target) << endl;
    cout << "Recursion with Memoization Output: " << rm.numRollsToTarget(n, k, target) << endl;
    cout << "Tabulation (Bottom-Up DP) Output: " << tab.numRollsToTarget(n, k, target) << endl;
    cout << "Space Optimized DP Output: " << so.numRollsToTarget(n, k, target) << endl;
    
    return 0;
}







