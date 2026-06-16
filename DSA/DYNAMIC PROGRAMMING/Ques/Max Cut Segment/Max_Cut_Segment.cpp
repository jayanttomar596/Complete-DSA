// Maximize The Cut Segments




/*

Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.

Note: if no segment can be cut then return 0.

*/








#include <iostream>
#include <vector>

using namespace std;





// Time Complexity	O(n)
// Space Complexity	O(n)

class My_Solution {
    int solveRec(vector<int> &coins , int x , vector<int> &dp)
    {
        // Base Case
        if (x == 0)
            return 0 ;
        
        if (x < 0)
            return INT_MIN ;
            
        if (dp[x] != -1)
        {
            return dp[x] ;
        }
        
        int maxi = INT_MIN ;
        for (int i = 0 ; i < coins.size() ; i++)
        {
            int ans = solveRec(coins , x-coins[i] , dp) ;
            if (ans != INT_MIN)
                maxi = max(maxi , 1+ans) ;
        }
        
        dp[x] = maxi ;

        return dp[x] ;
    }
    
    
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        
        vector<int> coins = {x , y , z} ;
        vector<int> dp(n+1 , -1) ;
        int ans = solveRec(coins , n , dp) ;
        if (ans == INT_MIN)
        {
            return 0 ;
        }
        
        return ans ;
        
    }
};






int main() {


    My_Solution sol;

    // Example 1:
    int n = 7, x = 5, y = 2, z = 2;
    int result = sol.maximizeTheCuts(n, x, y, z);
    cout << "Maximum number of cuts for length " << n << " is: " << result << endl;

    // Example 2:
    n = 17, x = 5, y = 1, z = 2;
    result = sol.maximizeTheCuts(n, x, y, z);
    cout << "Maximum number of cuts for length " << n << " is: " << result << endl;
    

    return 0;
}

