// Partition Equal Subset Sum




/*

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

*/







#include <iostream>
#include <vector>
using namespace std;







// | Method                  | Time Complexity | Space Complexity |
// | ----------------------- | --------------- | ---------------- |
// | Recursion               | O(2^n)          | O(n)             |
// | Recursion + Memoization | O(n * target)   | O(n * target)    |
// | Tabulation              | O(n * target)   | O(n * target)    |
// | Space Optimized         | O(n * target)   | O(target)        |







class Recursion {
    bool solve(int index , vector<int>& arr , int n , int target)
    {
        // Base Case
        if (index >= n)
            return 0 ;
        if (target < 0)
            return 0 ;
        if (target == 0)
            return 1 ;
        
        bool incl = solve(index+1 , arr , n , target - arr[index]) ;
        bool excl = solve(index+1 , arr , n ,target-0) ;

        return incl or excl ;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;

        int total = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            total += nums[i] ;
        }

        if (total & 1)
            return 0 ;
        
        int target = total/2 ;

        return solve(0 , nums , n , target) ;
    }
};








class Recursion_Memoization {
    bool solve(int index , vector<int>& arr , int n , int target , vector<vector<int>> &dp)
    {
        // Base Case
        if (index >= n)
            return 0 ;
        if (target < 0)
            return 0 ;
        if (target == 0)
            return 1 ;
        

        if (dp[index][target] != -1)
            return dp[index][target] ;
        
        bool incl = solve(index+1 , arr , n , target - arr[index] , dp) ;
        bool excl = solve(index+1 , arr , n ,target-0 , dp) ;

        return dp[index][target] = incl or excl ;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;

        int total = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            total += nums[i] ;
        }

        if (total & 1)
            return 0 ;
        
        int target = total/2 ;

        vector<vector<int>> dp(n , vector<int>(target+1 , -1)) ;

        return solve(0 , nums , n , target , dp) ;
    }
};








class Tabulation {
    bool solve(int N , vector<int>& arr , int total)
    {
        vector<vector<int>> dp(N+1 , vector<int>(total+1 , 0)) ;
        
        // Base Case: Sum 0 can always be made by picking no elements
        for (int i = 0 ; i <= N ; i++)
        {
            dp[i][0] = 1 ;
        }

        // Bottom-up DP
        for (int index = N-1 ; index >= 0 ; index--)
        {
            for (int target = 0 ; target <= total ; target++)
            {
                bool incl = false ;
                if (target - arr[index] >= 0)
                    incl = dp[index+1][target - arr[index]] ;

                bool excl = dp[index+1][target] ;

                dp[index][target] = incl || excl ;
            }
        }

        return dp[0][total] ;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;

        int total = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            total += nums[i] ;
        }

        // If total sum is odd, can't divide into 2 equal subsets
        if (total & 1)
            return false ;
        
        int target = total / 2 ;

        return solve(n, nums, target) ;
    }
};











class SO {
    bool solve(int N , vector<int>& arr , int total)
    {
        vector<int> next(total+1 , 0) ;
        vector<int> curr(total+1 , 0) ;

        curr[0] = 1 ;
        next[0] = 1 ;
        

        // Bottom-up DP
        for (int index = N-1 ; index >= 0 ; index--)
        {
            for (int target = 0 ; target <= total ; target++)
            {
                bool incl = false ;
                if (target - arr[index] >= 0)
                    incl = next[target - arr[index]] ;

                bool excl = next[target] ;

                curr[target] = incl || excl ;
            }
            next = curr ;
        }

        return next[total] ;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;

        int total = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            total += nums[i] ;
        }

        // If total sum is odd, can't divide into 2 equal subsets
        if (total & 1)
            return false ;
        
        int target = total / 2 ;

        return solve(n, nums, target) ;
    }
};












int main() {

    vector<int> nums = {1, 5, 11, 5};

    Recursion rec;
    Recursion_Memoization rec_mem;
    Tabulation tab;
    SO space_opt;

    cout << "Input Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    cout << "Recursion Result: " << (rec.canPartition(nums) ? "True" : "False") << endl;
    cout << "Memoization Result: " << (rec_mem.canPartition(nums) ? "True" : "False") << endl;
    cout << "Tabulation Result: " << (tab.canPartition(nums) ? "True" : "False") << endl;
    cout << "Space Optimized Result: " << (space_opt.canPartition(nums) ? "True" : "False") << endl;
    
    return 0;
}


