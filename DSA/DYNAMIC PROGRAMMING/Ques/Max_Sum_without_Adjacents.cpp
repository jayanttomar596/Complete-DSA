// Max Sum without Adjacents




/*

Given an array arr containing positive integers. Find the maximum sum of any possible subsequence such that no two numbers in the subsequence should be adjacent in array arr.

*/





#include <iostream>
#include <vector>
using namespace std;





// T.C. -> O(2^N)
// S.C. -> O(N)

class Solution_Recursion {
    private :
      int solve(vector<int> &nums , int n)
      {
          // Base Case
          if (n < 0)
              return 0 ;
          if (n == 0)
              return nums[0] ;
          
          int incl = solve(nums , n-2) + nums[n] ;
          int excl = solve(nums , n-1) + 0 ;
          
          return max(incl , excl) ;
      }
      
    public:
      // calculate the maximum sum with out adjacent
      int findMaxSum(vector<int>& arr) {
          int n = arr.size() ;
          int ans = solve(arr , n-1) ;
          return ans ;
      }
};






// T.C. -> O(N)
// S.C. -> O(N)

class Solution_Memoization {
    private :
      int solveMem(vector<int> &nums , int n , vector<int> &dp)
      {
          // Base Case
          if (n < 0)
              return 0 ;
          
          if (n == 0)
              return nums[0] ;
          
          if (dp[n] != -1)
              return dp[n] ;
          
          int incl = solveMem(nums , n-2 , dp) + nums[n] ;
          int excl = solveMem(nums , n-1 , dp) + 0 ;
          
          
          dp[n] = max(incl , excl) ;
          return dp[n] ;
      }
      
    public:
      // calculate the maximum sum with out adjacent
      int findMaxSum(vector<int>& arr) {
          int n = arr.size() ;
          vector<int> dp(n , -1) ;
          return solveMem(arr , n-1 , dp) ;
      }
};






// T.C. -> O(N)
// S.C. -> O(N)

class Solution_Tabulation {
    private :
      int solveTab(vector<int> &nums)
      {
          int n = nums.size() ;
          vector<int> dp(n , 0) ;
          
          dp[0] = nums[0] ;
          dp[1] = max(nums[0] , nums[1]) ;
          
          for (int i = 2 ; i < n ; i++)
          {
              int incl = dp[i-2] + nums[i] ;
              int excl = dp[i-1] + 0 ;
              dp[i] = max(incl , excl) ;
          }
          
          return dp[n-1] ;
      }
      
    public:
      // calculate the maximum sum with out adjacent
      int findMaxSum(vector<int>& arr) {
          
          return solveTab(arr) ;
      }
};







// T.C. -> O(N)
// S.C. -> O(1)

class Solution_SO {
    private :
      int solveTab(vector<int> &nums)
      {
          int n = nums.size() ;
          
          
          int prev2 = 0 ;
          int prev1 = nums[0] ;
          
          for (int i = 1 ; i < n ; i++)
          {
              int incl = prev2 + nums[i] ;
              int excl = prev1 + 0 ;
              
              int ans = max(incl , excl) ;
              prev2 = prev1 ;
              prev1 = ans ;
          }
          
          return prev1 ;
      }
      
    public:
      // calculate the maximum sum with out adjacent
      int findMaxSum(vector<int>& arr) {
          
          return solveTab(arr) ;
      }
};






int main() {

    vector<int> arr = {3, 2, 5, 10, 7};  // Example array

    // Testing Recursion Approach
    Solution_Recursion rec;
    cout << "Recursion Approach: " << rec.findMaxSum(arr) << endl;

    // Testing Memoization Approach
    Solution_Memoization memo;
    cout << "Memoization Approach: " << memo.findMaxSum(arr) << endl;

    // Testing Tabulation Approach
    Solution_Tabulation tab;
    cout << "Tabulation Approach: " << tab.findMaxSum(arr) << endl;

    // Testing Space Optimization Approach
    Solution_SO spaceOpt;
    cout << "Space Optimization Approach: " << spaceOpt.findMaxSum(arr) << endl;
    
    return 0;
}

