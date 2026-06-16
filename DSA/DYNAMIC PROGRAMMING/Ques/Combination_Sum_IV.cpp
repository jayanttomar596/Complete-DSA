// Combination Sum IV




/*

Given an array of unique integers arr and a target value k. Return the total number of distinct combinations of elements from nums that sum up to the target. Each element from nums can be used multiple times in a combination.

*/





#include <iostream>
#include <vector>
using namespace std;







// | Approach               | Time Complexity | Space Complexity | Suitable For         |
// | ---------------------- | --------------- | ---------------- | -------------------- |
// | Recursion              | O(n^t)          | O(t) call stack  | Small inputs only    |
// | Rec + Memoization      | O(n × t)        | O(t)             | Medium/Large inputs  |
// | Tabulation (Iterative) | O(n × t)        | O(t)             | Best for performance |






class Recursion {
    int solve(vector<int> &num , int tar)
    {
        // Base Case

        if (tar < 0)
            return 0 ;
        
        if (tar == 0)
            return 1 ;
        
        int ans = 0 ;
        for (int i = 0 ; i < num.size() ; i++)
        {
            ans += solve(num , tar - num[i]) ;
        }

        return ans ;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums , target) ;
    }
};







class Recursion_Memoization {

    int solve(vector<int> &num , int tar , vector<int> &dp)
    {
        // Base Case

        if (tar < 0)
            return 0 ;
        
        if (tar == 0)
            return 1 ;

        if (dp[tar] != -1)
            return dp[tar] ;
        
        int ans = 0 ;
        for (int i = 0 ; i < num.size() ; i++)
        {
            ans += solve(num , tar - num[i] , dp) ;
        }

        dp[tar] = ans ;
        return dp[tar] ;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1 , -1) ;
        return solve(nums , target , dp) ;
    }
};









class Tabulation {

    int solve(vector<int> &num , int tar)
    {
        vector<unsigned long long> dp(tar+1 , 0) ;
        dp[0] = 1 ;

        // traversing from target 1 to tar
        for (int i = 1 ; i <= tar ; i++)
        {
            // Traversing on num vector
            for (int j = 0 ; j < num.size() ; j++)
            {
                if (i-num[j] >= 0)
                    dp[i] += dp[i-num[j]] ;
            }
        }

        return dp[tar] ;
    }


public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums , target ) ;
    }
};









int main() {


    vector<int> nums = {1, 2, 3};
    int target = 4;

    // 1️⃣ Test Pure Recursion (Warning: Slow for large target)
    Recursion r;
    cout << "Recursion result: " << r.combinationSum4(nums, target) << endl;

    // 2️⃣ Test Recursion + Memoization
    Recursion_Memoization rm;
    cout << "Recursion + Memoization result: " << rm.combinationSum4(nums, target) << endl;

    // 3️⃣ Test Tabulation
    Tabulation t;
    cout << "Tabulation result: " << t.combinationSum4(nums, target) << endl;
    
    return 0;
}





