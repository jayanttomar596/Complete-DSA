// 0 - 1 Knapsack Problem


/*

Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

*/





#include <iostream>
#include <vector>
using namespace std;






// Approach	               Time Complexity	   Space Complexity
// Recursion (Brute Force)	      O(2^n)	       O(n)
// Memoization (Top-Down)	      O(n * W)	       O(n * W)
// Tabulation (Bottom-Up)	      O(n * W)	       O(n * W)
// Space Optimization (2D)	      O(n * W)	       O(W)
// Space Optimization (1D)	      O(n * W)	       O(W)

// n - no of items and w maximum weight




class Recursion {
    
    int solve(vector<int>& weight , vector<int>& value , int index , int capacity)
    {
        // Base Case
        // If only 1 item to steal , then just compare its weight with the knapsack capacity 
        if (index == 0)
        {
            if (weight[0] <= capacity)
                return value[0] ;
            else
                return 0 ;
        }
        
        int include = 0 ;
        if (weight[index] <= capacity)
            include = value[index] + solve(weight , value , index - 1 , capacity - weight[index]) ;
        
        int exclude = 0 + solve(weight , value , index-1 , capacity) ;
        
        int ans = max(include , exclude) ;
        return ans ;
    }
    
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size() ;
        
        return solve(wt , val , n-1 , W) ;
    }
};







class Recursion_Memoization{
    
    int solve(vector<int>& weight , vector<int>& value , int index , int capacity , vector<vector<int>>& dp)
    {
        // Base Case
        // If only 1 item to steal , then just compare its weight with the knapsack capacity 
        if (index == 0)
        {
            if (weight[0] <= capacity)
                return value[0] ;
            else
                return 0 ;
        }
        
        
        if (dp[index][capacity] != -1)
            return dp[index][capacity] ;
        
        
        int include = 0 ;
        if (weight[index] <= capacity)
            include = value[index] + solve(weight , value , index - 1 , capacity - weight[index] , dp) ;
        
        int exclude = 0 + solve(weight , value , index-1 , capacity , dp) ;
        
        
        dp[index][capacity] = max(include , exclude) ;
        return dp[index][capacity] ;
    }
    
  public:
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size() ;
        
        vector<vector<int>> dp( n , vector<int>(W+1 , -1)) ; 
        return solve(wt , val , n-1 , W , dp) ;
    }
};







class Tabulation {
    
    int solve(vector<int>& weight , vector<int>& value , int n , int capacity)
    {
        // Step 1 :
        vector<vector<int>> dp( n , vector<int>(capacity+1 , 0)) ; 
        
        
        // Step 2 : Analyze Base Case
        for (int w = weight[0] ; w <= capacity ; w++)
        {
            if (weight[0] <= capacity)
                dp[0][w] = value[0] ;
            else
                dp[0][w] = 0 ;
        }
        
        
        // Take care of remaining recursive calls
        
        for (int index = 1 ; index < n ; index++)
        {
            for (int w = 0 ; w <= capacity ; w++)
            {
                int include = 0 ;
                
                if (weight[index] <= w)
                    include = value[index] + dp[index - 1][w - weight[index]] ;
        
                int exclude = 0 + dp[index-1][w] ;
        
        
                dp[index][w] = max(include , exclude) ;
            }
        }
        
        return dp[n-1][capacity] ;
    }
    
  public:
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size() ;
        
        return solve(wt , val , n , W ) ;
    }
};






class Space_Optimization_2D {
    
    int solve(vector<int>& weight , vector<int>& value , int n , int capacity)
    {
        // Step 1 :
        vector<int> prev(capacity+1 , 0) ;
        vector<int> curr(capacity+1 , 0) ;
        
        
        // Step 2 : Analyze Base Case
        for (int w = weight[0] ; w <= capacity ; w++)
        {
            if (weight[0] <= capacity)
                prev[w] = value[0] ;
            else
                prev[w] = 0 ;
        }
        
        
        for (int index = 1 ; index < n ; index++)
        {
            for (int w = 0 ; w <= capacity ; w++) // yeh loop right to left me bhi chal jayega 
            {
                int include = 0 ;
                
                if (weight[index] <= w)
                    include = value[index] + prev[w - weight[index]] ;
        
                int exclude = 0 + prev[w] ;
        
        
                curr[w] = max(include , exclude) ;
            }
            
            prev = curr ;
        }
        
        return prev[capacity] ;
    }
    
  public:
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size() ;
        
        return solve(wt , val , n , W ) ;
    }
};








class Space_Optimization_1D {
    
    int solve(vector<int>& weight , vector<int>& value , int n , int capacity)
    {
        // Step 1 :
        vector<int> curr(capacity+1 , 0) ;
        
        
        // Step 2 : Analyze Base Case
        for (int w = weight[0] ; w <= capacity ; w++)
        {
            if (weight[0] <= capacity)
                curr[w] = value[0] ;
            else
                curr[w] = 0 ;
        }
        
        
        for (int index = 1 ; index < n ; index++)
        {
            for (int w = capacity ; w >= 0 ; w--)
            {
                int include = 0 ;
                
                if (weight[index] <= w)
                    include = value[index] + curr[w - weight[index]] ;
        
                int exclude = 0 + curr[w] ;
        
        
                curr[w] = max(include , exclude) ;
            }
            
        }
        
        return curr[capacity] ;
    }
    
  public:
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size() ;
        
        return solve(wt , val , n , W ) ;
    }
};









int main() {

    int W = 10;
    vector<int> wt = {1, 3, 4, 6};
    vector<int> val = {20, 30, 10, 50};

    // Test Recursion
    Recursion r;
    cout << "Recursion Result: " << r.knapsack(W, val, wt) << endl;

    // Test Recursion + Memoization
    Recursion_Memoization rm;
    cout << "Recursion + Memoization Result: " << rm.knapsack(W, val, wt) << endl;

    // Test Tabulation
    Tabulation t;
    cout << "Tabulation Result: " << t.knapsack(W, val, wt) << endl;

    // Test Space Optimized 2D
    Space_Optimization_2D so2d;
    cout << "Space Optimization (2D) Result: " << so2d.knapsack(W, val, wt) << endl;

    // Test Space Optimized 1D
    Space_Optimization_1D so1d;
    cout << "Space Optimization (1D) Result: " << so1d.knapsack(W, val, wt) << endl;
    


    return 0;
}






