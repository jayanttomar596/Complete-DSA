// Wildcard Matching





/*

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

*/








#include <iostream>
#include <vector>
using namespace std;








// | Approach                | Time Complexity    | Space Complexity |
// | ----------------------- | ------------------ | ---------------- |
// | Recursion               | O(2^(n+m)          | O(n + m)         |
// | Recursion + Memoization | O(n × m)           | O(n × m)         |
// | Tabulation              | O(n × m)           | O(n × m)         |
// | Space Optimized (SO)    | O(n × m)           | O(m)             |







class Recursion {

    bool solve(string& str , string& pattern , int i , int j)
    {
        // Base Case
        if (i < 0 && j < 0)
            return true ;
        
        if (i >= 0 && j < 0)
        {
            return false ;
        }

        if (i < 0 && j >= 0)
        {
            for (int k = 0 ; k <= j ; k++)
            {
                if (pattern[k] != '*')
                    return false ;
            }
            return true ;
        }

        // Match 
        if (str[i] == pattern[j] || pattern[j] == '?')
            return solve(str, pattern , i-1 , j-1) ;
        else if (pattern[j] == '*')
            return (solve(str , pattern , i-1 , j) || solve(str , pattern , i , j-1)) ;
        else
            return false ;
    }

public:
    bool isMatch(string s, string p) {
        return solve(s , p , s.length()-1 , p.length() - 1) ;
    }
};










class Recursion_Memoization {

    bool solve(string& str , string& pattern , int i , int j , vector<vector<int>>& dp)
    {
        // Base Case
        if (i < 0 && j < 0)
            return true ;
        
        if (i >= 0 && j < 0)
        {
            return false ;
        }

        if (i < 0 && j >= 0)
        {
            for (int k = 0 ; k <= j ; k++)
            {
                if (pattern[k] != '*')
                    return false ;
            }
            return true ;
        }

        if (dp[i][j] != -1)
            return dp[i][j] ;

        // Match 
        if (str[i] == pattern[j] || pattern[j] == '?')
            return dp[i][j] = solve(str, pattern , i-1 , j-1 , dp) ;
        else if (pattern[j] == '*')
            return dp[i][j] = (solve(str , pattern , i-1 , j , dp) || solve(str , pattern , i , j-1 , dp)) ;
        else
            return false ;
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() , vector<int>(p.length() , -1)) ;
        return solve(s , p , s.length()-1 , p.length() - 1 , dp) ;
    }
};









class Tabulation {

    bool solve(string& str , string& pattern)
    {
        vector<vector<int>> dp(str.length()+1 , vector<int>(pattern.length()+1 , 0)) ;
        dp[0][0] = true ;

        for (int j = 1 ; j <= pattern.length() ; j++)
        {
            bool flag = true ;
            for (int k = 1 ; k <= j ; k++)
            {
                if (pattern[k-1] != '*') {
                    flag = false ;
                    break ;
                }
            }
            dp[0][j] = flag ;
        }


        for (int i = 1 ; i <= str.length() ; i++)
        {
            for (int j = 1 ; j <= pattern.length() ; j++)
            {
                // Match 
                if (str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1] ; 
                else if (pattern[j-1] == '*')
                    dp[i][j] =  (dp[i-1][j] || dp[i][j-1]) ;
                else
                    dp[i][j] = false ;
            }
        }

        return dp[str.length()][pattern.length()] ;
    }

public:
    bool isMatch(string s, string p) {
        return solve(s , p) ;
    }
};









class SO {

    bool solve(string& str , string& pattern)
    {
        vector<int> prev(pattern.length()+1 , 0) ;
        vector<int> curr(pattern.length()+1 , 0) ;

        prev[0] = true ;

        for (int j = 1 ; j <= pattern.length() ; j++)
        {
            bool flag = true ;
            for (int k = 1 ; k <= j ; k++)
            {
                if (pattern[k-1] != '*') {
                    flag = false ;
                    break ;
                }
            }
            prev[j] = flag ;
        }


        for (int i = 1 ; i <= str.length() ; i++)
        {
            for (int j = 1 ; j <= pattern.length() ; j++)
            {
                // Match 
                if (str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    curr[j] = prev[j-1] ; 
                else if (pattern[j-1] == '*')
                    curr[j] =  (prev[j] || curr[j-1]) ;
                else
                    curr[j] = false ;
            }
            prev = curr ;
        }

        return prev[pattern.length()] ;
    }

public:
    bool isMatch(string s, string p) {
        return solve(s , p) ;
    }
};












int main() {

    string str = "baaabab";
    string pattern = "ba*ab";

    Recursion r;
    Recursion_Memoization rm;
    Tabulation tab;
    SO so;

    cout << "String: " << str << "\nPattern: " << pattern << "\n\n";

    cout << "[1] Recursion: " << (r.isMatch(str, pattern) ? "Match" : "No Match") << endl;
    cout << "[2] Memoization: " << (rm.isMatch(str, pattern) ? "Match" : "No Match") << endl;
    cout << "[3] Tabulation: " << (tab.isMatch(str, pattern) ? "Match" : "No Match") << endl;
    cout << "[4] Space Optimized: " << (so.isMatch(str, pattern) ? "Match" : "No Match") << endl;
    
    return 0;
}




