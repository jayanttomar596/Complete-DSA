// Longest Increasing Subsequence





/*

Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/





#include <iostream>
#include <vector>
using namespace std;









// | Approach                | Time Complexity | Space Complexity |
// | ----------------------- | --------------- | ---------------- |
// | Recursion               | O(2ⁿ)           | O(n)             |
// | Recursion + Memoization | O(n²)           | O(n²) + O(n)     |
// | Tabulation              | O(n²)           | O(n²)            |
// | Space Optimized         | O(n²)           | O(n)             |
// | DP + Binary Search      | O(n log n)      | O(n)             |






class Recursion {
    int solve(int n , vector<int> &a , int curr , int prev)
    {
        // Base Case
        if (curr == n)
            return 0 ;
        
        // Include
        int take = 0 ;
        if (prev == -1 || a[curr] > a[prev])
            take = 1 + solve(n , a , curr + 1 , curr) ;
        
        // Exclude
        int notTake = 0 + solve(n , a , curr + 1 , prev) ;

        return max(take , notTake) ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        return solve(n , nums , 0 , -1) ;
    }
};







class Recursion_Memoization {
    int solve(int n , vector<int> &a , int curr , int prev , vector<vector<int>>& dp)
    {
        // Base Case
        if (curr == n)
            return 0 ;
            
        if (dp[curr][prev+1] != -1)
            return dp[curr][prev+1] ;

        // Include
        int take = 0 ;
        if (prev == -1 || a[curr] > a[prev])
            take = 1 + solve(n , a , curr + 1 , curr , dp) ;
        
        // Exclude
        int notTake = 0 + solve(n , a , curr + 1 , prev , dp) ;

        return dp[curr][prev+1] = max(take , notTake) ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n , vector<int>(n+1 , -1)) ;
        return solve(n , nums , 0 , -1 , dp) ;
    }
};







class Tabulation
{
    int solve(int n , vector<int> &a)
    {
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0)) ;

        for (int curr = n-1 ; curr >= 0 ; curr--)
        {
            for (int prev = curr - 1 ; prev >= -1 ; prev--)
            {
                // Include
                int take = 0 ;
                if (prev == -1 || a[curr] > a[prev])
                    take = 1 + dp[curr + 1][curr + 1] ;
                
                // Exclude 
                int notTake = 0 + dp[curr + 1][prev + 1] ;

                dp[curr][prev + 1] = max(take , notTake) ;
            }
        }

        return dp[0][0] ;
    }

public :
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        return solve(n , nums) ;
    }
};








class SO
{
    int solve(int n , vector<int> &a)
    {
        vector<int> currRow(n+1 , 0) ;
        vector<int> nextRow(n+1 , 0) ;

        for (int curr = n-1 ; curr >= 0 ; curr--)
        {
            for (int prev = curr - 1 ; prev >= -1 ; prev--)
            {
                // Include
                int take = 0 ;
                if (prev == -1 || a[curr] > a[prev])
                    take = 1 + nextRow[curr + 1] ;
                
                // Exclude 
                int notTake = 0 + nextRow[prev + 1] ;

                currRow[prev + 1] = max(take , notTake) ;
            }

            nextRow = currRow ;
        }

        return nextRow[0] ;
    }

public :
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        return solve(n , nums) ;
    }
};








class DP_BS
{
    int solve(int n , vector<int> &a)
    {
        if (n == 0)
            return 0 ;
        
        vector<int> ans ;
        ans.push_back(a[0]) ;

        for (int i = 1 ; i < n ; i++)
        {
            if (a[i] > ans.back())
                ans.push_back(a[i]) ;
            else
            {
                // Find index of just badaa element in ans 
                int index = lower_bound(ans.begin() , ans.end() , a[i]) - ans.begin() ;
                ans[index] = a[i] ;
            }
        }

        return ans.size() ;
    }
    
public :
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        return solve(n , nums) ;
    }
};









int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Recursion r;
    cout << "Recursion: " << r.lengthOfLIS(nums) << endl;

    Recursion_Memoization rm;
    cout << "Recursion + Memoization: " << rm.lengthOfLIS(nums) << endl;

    Tabulation t;
    cout << "Tabulation: " << t.lengthOfLIS(nums) << endl;

    SO so;
    cout << "Space Optimized: " << so.lengthOfLIS(nums) << endl;

    DP_BS dpbs;
    cout << "DP + Binary Search: " << dpbs.lengthOfLIS(nums) << endl;
    
    return 0;
}







