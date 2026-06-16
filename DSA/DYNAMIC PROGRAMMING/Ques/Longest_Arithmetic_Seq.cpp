// Longest Arithmetic Subsequence




/*

Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
 



Example 1:

Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length = 3.
Example 2:

Input: nums = [9,4,7,2,10]
Output: 3
Explanation:  The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].

*/








#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;







// | Approach                  | Time Complexity | Space Complexity | 
// | ------------------------- | --------------- | ---------------- | 
// | Recursion Only            |  O(n^3)         |  O(n)            | 
// | Recursion + Memo          |  O(n^2)         |  O(n^2)          | 
// | Tabulation (Bottom-Up DP) |  O(n^2)         |  O(n^2)          | 







class Recursion {
    int solve(int index , int diff , vector<int>& A)
    {
        // Backward Check
        if (index < 0)
            return 0 ;
        
        int ans = 0 ;
        for (int j = index-1 ; j >= 0 ; j--)
        {
            if (A[index] - A[j] == diff)
                ans = max(ans , 1+solve(j , diff , A)) ;
        }

        return ans ;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() ;
        if (n <= 2)
            return n ;
        
        int ans = 0 ;

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = i+1 ; j < n ; j++)
            {
                ans = max(ans , 2 + solve(i , nums[j] - nums[i] , nums)) ;
            }
        }

        return ans ;    
    }
};








class Recursion_Memoization {
    int solve(int index , int diff , vector<int>& A , unordered_map<int , int> dp[])
    {
        // Backward Check
        if (index < 0)
            return 0 ;
        
        if (dp[index].count(diff))
            return dp[index][diff] ;
        
        int ans = 0 ;
        for (int j = index-1 ; j >= 0 ; j--)
        {
            if (A[index] - A[j] == diff)
                ans = max(ans , 1+solve(j , diff , A , dp)) ;
        }

        return dp[index][diff] = ans ;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() ;
        if (n <= 2)
            return n ;
        
        int ans = 0 ;

        unordered_map<int , int> dp[n+1] ;

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = i+1 ; j < n ; j++)
            {
                ans = max(ans , 2 + solve(i , nums[j] - nums[i] , nums , dp)) ;
            }
        }

        return ans ;    
    }
};










class Tabulation {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() ;
        if (n <= 2)
            return n ;
        
        int ans = 0 ;

        unordered_map<int , int> dp[n+1] ;

        for (int i = 1 ; i < n ; i++)
        {
            for (int j = 0 ; j < i ; j++)
            {
                int diff = nums[i] - nums[j] ;
                int cnt = 1 ;

                // Check if answer already present 
                if (dp[j].count(diff))
                    cnt = dp[j][diff] ;
                
                dp[i][diff] = 1 + cnt ;
                ans = max(ans , dp[i][diff]) ;
            }
        }

        return ans ;    
    }
};









int main() {


    vector<int> nums = {3, 6, 9, 12};

    Recursion r1;
    Recursion_Memoization r2;
    Tabulation r3;

    cout << "Input: {3, 6, 9, 12}" << endl;

    cout << "Recursion Only: " << r1.longestArithSeqLength(nums) << endl;
    cout << "Recursion + Memoization: " << r2.longestArithSeqLength(nums) << endl;
    cout << "Tabulation (Bottom-Up): " << r3.longestArithSeqLength(nums) << endl;
    

    return 0;
}





