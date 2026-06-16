// Largest square formed in a matrix




/*

Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.

Examples:

Input: mat = [[0, 1, 1, 0, 1], 
              [1, 1, 0, 1, 0],
              [0, 1, 1, 1, 0],
              [1, 1, 1, 1, 0],
              [1, 1, 1, 1, 1],
              [0, 0, 0, 0, 0]]
Output: 3

*/





#include <iostream>
#include <vector>
using namespace std;






// | Class                   | Time Complexity | Space Complexity |
// | ----------------------- | --------------- | ---------------- |
// | `Recursion`             | O(3^(n×m))      | O(n + m)         |
// | `Recursion_Memoization` | O(n×m)          | O(n×m)           |
// | `Tabulation`            | O(n×m)          | O(n×m)           |
// | `SO` (Space Optimized)  | O(n×m)          | O(m)             |







class Recursion {
    int solve(vector<vector<int>> &mat , int i , int j , int &maxi)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0 ;
        
        int right = solve(mat , i , j+1 , maxi) ;
        int diagnol = solve(mat , i+1 , j+1 , maxi) ;
        int down = solve(mat , i+1 , j , maxi) ;

        if (mat[i][j] == 1)
        {
            int ans = 1 + min(right , min(diagnol , down)) ;
            maxi = max(maxi , ans) ;
            return ans ;
        }
        else
        {
            return 0 ;
        }
    }
  public:
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0 ;
        solve(mat , 0 , 0 , maxi) ;
        return maxi ;
        
    }
};







class Recursion_Memoization {
    int solve(vector<vector<int>> &mat , int i , int j , int &maxi , vector<vector<int>>& dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0 ;
        
        if (dp[i][j] != -1)
            return dp[i][j] ;
        
        int right = solve(mat , i , j+1 , maxi , dp) ;
        int diagnol = solve(mat , i+1 , j+1 , maxi , dp) ;
        int down = solve(mat , i+1 , j , maxi , dp) ;

        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right , min(diagnol , down)) ;
            maxi = max(maxi , dp[i][j]) ;
            return dp[i][j] ;
        }
        else
        {
            return dp[i][j] = 0 ;
        }
    }
    
    
    
  public:
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0 ;
        int n = mat.size() ;
        int m = mat[0].size() ;
        vector<vector<int>> dp(n , vector<int>(m , -1)) ;
        solve(mat , 0 , 0 , maxi , dp) ;
        return maxi ;
        
    }
};







class Tabulation {
    int solve(vector<vector<int>> &mat , int &maxi)
    {
        int row = mat.size() ;
        int col = mat[0].size() ;
        
        vector<vector<int>> dp(row + 1 , vector<int>(col+1 , 0)) ;
        
        for (int i = row - 1 ; i >= 0 ; i--)
        {
            for (int j = col - 1 ; j >= 0 ; j--)
            {
                int right = dp[i][j+1] ;
                int diagnal = dp[i+1][j+1] ;
                int down = dp[i+1][j] ;
                
                if (mat[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right , min(diagnal , down)) ;
                    maxi = max(maxi , dp[i][j]) ;
                }
                else
                {
                    dp[i][j] = 0 ;
                }
            }
        }
        
        return dp[0][0] ;
    }
    
    
    
  public:
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0 ;
        solve(mat , maxi) ;
        return maxi ;
        
    }
};







class SO {
    int solve(vector<vector<int>> &mat , int &maxi)
    {
        int row = mat.size() ;
        int col = mat[0].size() ;
        
        vector<int> curr(col+1 , 0) ;
        vector<int> next(col+1 , 0) ;
        
        for (int i = row - 1 ; i >= 0 ; i--)
        {
            for (int j = col - 1 ; j >= 0 ; j--)
            {
                int right = curr[j+1] ;
                int diagnal = next[j+1] ;
                int down = next[j] ;
                
                if (mat[i][j] == 1)
                {
                    curr[j] = 1 + min(right , min(diagnal , down)) ;
                    maxi = max(maxi , curr[j]) ;
                }
                else
                {
                    curr[j] = 0 ;
                }
            }
            
            next = curr ;
        }
        
        return next[0] ;
    }
    
    
    
  public:
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0 ;
        solve(mat , maxi) ;
        return maxi ;
        
    }
};










int main() {


    // Test matrix
    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    // Run all approaches
    Recursion r;
    Recursion_Memoization rm;
    Tabulation t;
    SO so;

    cout << "Max Square (Recursion): " << r.maxSquare(matrix) << endl;
    cout << "Max Square (Recursion + Memoization): " << rm.maxSquare(matrix) << endl;
    cout << "Max Square (Tabulation): " << t.maxSquare(matrix) << endl;
    cout << "Max Square (Space Optimized): " << so.maxSquare(matrix) << endl;
    
    
    return 0;
}








