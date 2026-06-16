// Longest Common Subsequence




/*

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

*/







#include <iostream>
#include <vector>
using namespace std;









// | Approach                | Time Complexity | Space Complexity       |
// | ----------------------- | --------------- | ---------------------- |
// | Recursion               |  O(2^{n + m})   |  O(n + m)              |
// | Recursion + Memoization |  O(n * m)       |  O(n*m + n + m)        |
// | Tabulation              |  O(n * m)       |  O(n * m)              |
// | Space Optimized (SO)    |  O(n * m)       |  O(m)                  |









class Recursion {
    int solve(string &a , string &b , int i , int j)
    {
        // Base Case
        if (i == a.length())
            return 0 ;
        if (j == b.length())
            return 0 ;
        
        int ans = 0 ;
        if (a[i] == b[j])
        {
            ans = 1 + solve(a , b , i+1 , j+1) ;
        }
        else
        {
            ans = max(solve(a , b , i+1 , j) , solve(a , b , i , j+1)) ;
        }

        return ans ;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1 , text2 , 0 , 0) ;
    }
};










class Recursion_Memoization {
    int solve(string &a , string &b , int i , int j , vector<vector<int>>& dp)
    {
        // Base Case
        if (i == a.length())
            return 0 ;
        if (j == b.length())
            return 0 ;
        
        if (dp[i][j] != -1)
            return dp[i][j] ;
        
        int ans = 0 ;
        if (a[i] == b[j])
        {
            ans = 1 + solve(a , b , i+1 , j+1 , dp) ;
        }
        else
        {
            ans = max(solve(a , b , i+1 , j , dp) , solve(a , b , i , j+1 , dp)) ;
        }

        return dp[i][j] = ans ;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() , vector<int>(text2.length() , -1)) ;
        return solve(text1 , text2 , 0 , 0 , dp) ;
    }
};









class Tabulation {
    int solve(string &a , string &b)
    {
        vector<vector<int>> dp(a.length() + 1 , vector<int>(b.length() + 1 , 0)) ;

        for (int i = a.length() - 1 ; i >= 0 ; i--)
        {
            for (int j = b.length() - 1 ; j >= 0 ; j--)
            {
                int ans = 0 ;
                if (a[i] == b[j])
                {
                    ans = 1 + dp[i+1][j+1] ; 
                }
                else
                {
                    ans = max( dp[i+1][j] , dp[i][j+1] ) ; 
                }

                dp[i][j] = ans ;               
            }
        }

        return dp[0][0] ;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1 , text2) ;
    }
};









class SO {
    int solve(string &a , string &b)
    {
        vector<int> curr(b.length()+1 , 0) ;
        vector<int> next(b.length()+1 , 0) ;

        for (int i = a.length() - 1 ; i >= 0 ; i--)
        {
            for (int j = b.length() - 1 ; j >= 0 ; j--)
            {
                int ans = 0 ;
                if (a[i] == b[j])
                {
                    ans = 1 + next[j+1] ; 
                }
                else
                {
                    ans = max( next[j] , curr[j+1] ) ; 
                }

                curr[j] = ans ;               
            }
            next = curr ;
        }

        return next[0] ;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1 , text2) ;
    }
};














int main() {

    string text1 = "abcde";
    string text2 = "ace";

    Recursion r;
    Recursion_Memoization rm;
    Tabulation t;
    SO so;

    cout << "Text1: " << text1 << "\n";
    cout << "Text2: " << text2 << "\n\n";

    cout << "1. Recursion (Brute Force): " << r.longestCommonSubsequence(text1, text2) << endl;
    cout << "2. Recursion + Memoization: " << rm.longestCommonSubsequence(text1, text2) << endl;
    cout << "3. Tabulation (Bottom-Up): " << t.longestCommonSubsequence(text1, text2) << endl;
    cout << "4. Space Optimized: " << so.longestCommonSubsequence(text1, text2) << endl;
    
    return 0;
}




