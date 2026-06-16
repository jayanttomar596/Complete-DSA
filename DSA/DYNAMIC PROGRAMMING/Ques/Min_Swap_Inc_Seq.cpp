// Minimum Swaps To Make Sequences Increasing





/*

You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

 

Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.


*/








#include <iostream>
#include <vector>
using namespace std;








// | Approach                | Time Complexity | Space Complexity |
// | ----------------------- | --------------- | ---------------- |
// | Recursion               |  O(2^n)         |  O(n)            |
// | Recursion + Memoization |  O(n)           |  O(n)            |
// | Tabulation              |  O(n)           |  O(n)            |
// | Space Optimized         |  O(n)           |  O(1)            |









class Recursion {
    int solve(vector<int>& nums1 , vector<int>& nums2 , int index , bool swapped)
    {
        // Base Case
        if (index == nums1.size())
            return 0 ;
        
        int ans = INT_MAX ;

        int prev1 = nums1[index-1] ;
        int prev2 = nums2[index-1] ;

        // Catch
        if (swapped)
            swap(prev1 , prev2) ;
        
        // NoSwap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1 , nums2 , index+1 , 0) ;
        
        // Swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans , 1 + solve(nums1 , nums2 , index+1 , 1)) ;
        
        return ans ;
    }
public:
    int minSwap(vector<int> nums1, vector<int> nums2) {
        nums1.insert(nums1.begin() , -1) ;
        nums2.insert(nums2.begin() , -1) ;

        // It means that the previous were swapped or not 
        bool swapped = 0 ;
        return solve(nums1 , nums2 , 1 , swapped) ;
    }
};









class Recursion_Memoization {
    int solve(vector<int>& nums1 , vector<int>& nums2 , int index , bool swapped , vector<vector<int>>& dp)
    {
        // Base Case
        if (index == nums1.size())
            return 0 ;
        
        int ans = INT_MAX ;

        int prev1 = nums1[index-1] ;
        int prev2 = nums2[index-1] ;

        // Catch
        if (swapped)
            swap(prev1 , prev2) ;
        
        if (dp[index][swapped] != -1)
            return dp[index][swapped] ;
        
        // NoSwap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1 , nums2 , index+1 , 0 , dp) ;
        
        // Swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans , 1 + solve(nums1 , nums2 , index+1 , 1 , dp)) ;
        
        return dp[index][swapped] = ans ;
    }
public:
    int minSwap(vector<int> nums1, vector<int> nums2) {
        nums1.insert(nums1.begin() , -1) ;
        nums2.insert(nums2.begin() , -1) ;


        // It means that the previous were swapped or not 
        bool swapped = 0 ;


        int n = nums1.size() ;
        vector<vector<int>> dp(n , vector<int>(2 , -1)) ;
        
        return solve(nums1 , nums2 , 1 , swapped , dp) ;
    }
};









class Tabulation {
    int solve(vector<int>& nums1 , vector<int>& nums2)
    {
        int n = nums1.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(2 , 0)) ;
        


        for (int index = n-1 ; index >= 1 ; index--)
        {
            for (int swapped = 1 ; swapped >= 0 ; swapped--)
            {
                int ans = INT_MAX ;

                int prev1 = nums1[index-1] ;
                int prev2 = nums2[index-1] ;

                // Catch
                if (swapped)
                    swap(prev1 , prev2) ;
    
                // NoSwap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0] ;
        
                // Swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans , 1 + dp[index+1][1]) ;
        
                dp[index][swapped] = ans ;
            }
        }

        return dp[1][0] ;   
    }
public:
    int minSwap(vector<int> nums1, vector<int> nums2) {
        nums1.insert(nums1.begin() , -1) ;
        nums2.insert(nums2.begin() , -1) ;

        
        return solve(nums1 , nums2) ;
    }
};











class SO {
    int solve(vector<int>& nums1 , vector<int>& nums2 )
    {
        int n = nums1.size() ;

        int swap = 0 ;
        int noswap = 0 ;
        int currswap = 0 ;
        int currnoswap = 0 ;


        for (int index = n-1 ; index >= 1 ; index--)
        {
            for (int swapped = 1 ; swapped >= 0 ; swapped--)
            {
                int ans = INT_MAX ;

                int prev1 = nums1[index-1] ;
                int prev2 = nums2[index-1] ;

                // Catch
                if (swapped)
                {
                    int temp = prev2 ;
                    prev2 = prev1 ;
                    prev1 = temp ;
                }
    
                // NoSwap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noswap ;
        
                // Swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans , 1 + swap) ;
        
                if (swapped)
                    currswap = ans ;
                else
                    currnoswap = ans ;
            }

            swap = currswap ;
            noswap = currnoswap ;
        }

        return min(swap , noswap) ;   
    }
public:
    int minSwap(vector<int> nums1, vector<int> nums2) {
        nums1.insert(nums1.begin() , -1) ;
        nums2.insert(nums2.begin() , -1) ;

        
        return solve(nums1 , nums2) ;
    }
};











int main() {

    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};

    Recursion r;
    Recursion_Memoization rm;
    Tabulation t;
    SO so;

    cout << "Recursion: " << r.minSwap(nums1, nums2) << endl;
    cout << "Recursion + Memoization: " << rm.minSwap(nums1, nums2) << endl;
    cout << "Tabulation: " << t.minSwap(nums1, nums2) << endl;
    cout << "Space Optimized: " << so.minSwap(nums1, nums2) << endl;
    
    return 0;
}



