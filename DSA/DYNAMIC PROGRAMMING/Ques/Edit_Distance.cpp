// Edit Distance






/*

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')


*/








#include <iostream>
#include <vector>
using namespace std;









// | Version              | Time Complexity | Space Complexity        |
// | -------------------- | --------------- | ----------------------- |
// | Recursion            |  O(3^(n + m))   |  O(n + m)               |
// | Recursion + Memo     |  O(n * m)       |  O(n * m)  +  O(n + m)  |
// | Tabulation           |  O(n * m)       |  O(n * m)               |
// | Space Optimized (SO) |  O(n * m)       |  O(m)                   |









class Recursion {
    int solve(string& a , string& b , int i , int j)
    {
        // Base Case
        if (i == a.length())
            return b.length() - j ;

        if (j == b.length())
            return a.length() - i ;
        
        int ans = 0 ;
        if (a[i] == b[j])
            return solve(a , b , i+1 , j+1) ;
        else
        {
            // Insert
            int insertAns = 1 + solve(a , b , i , j+1) ;

            // Delete
            int deleteAns = 1 + solve(a , b , i+1 , j) ;

            // Replace
            int replaceAns = 1 + solve(a , b , i+1 , j+1) ;

            ans = min(insertAns , min(deleteAns , replaceAns)) ;
        }

        return ans ;
    }
    
public:
    int minDistance(string word1, string word2) {
        return solve(word1 , word2 , 0 , 0) ;
    }
};












class Recursion_Memoization {
    int solve(string& a , string& b , int i , int j , vector<vector<int>>& dp)
    {
        // Base Case
        if (i == a.length())
            return b.length() - j ;

        if (j == b.length())
            return a.length() - i ;
        
        if (dp[i][j] != -1)
            return dp[i][j] ;
        
        int ans = 0 ;
        if (a[i] == b[j])
            return solve(a , b , i+1 , j+1 , dp) ;
        else
        {
            // Insert
            int insertAns = 1 + solve(a , b , i , j+1 , dp) ;

            // Delete
            int deleteAns = 1 + solve(a , b , i+1 , j , dp) ;

            // Replace
            int replaceAns = 1 + solve(a , b , i+1 , j+1 , dp) ;

            ans = min(insertAns , min(deleteAns , replaceAns)) ;
        }

        return dp[i][j] = ans ;
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() , vector<int>(word2.length() , -1 )) ;
        return solve(word1 , word2 , 0 , 0 , dp) ;
    }
};











class Tabulation {
    int solve(string& a , string& b)
    {
        vector<vector<int>> dp(a.length()+1 , vector<int>(b.length()+1 , 0 )) ;

        for (int j = 0 ; j < b.length() ; j++)
            dp[a.length()][j] = b.length() - j ;
        
        for (int i = 0 ; i < a.length() ; i++)
            dp[i][b.length()] = a.length() - i ;

        
        for (int i = a.length() - 1 ; i >= 0 ; i--)
        {
            for (int j = b.length() - 1 ; j >= 0 ; j--)
            {
                int ans = 0 ;
                if (a[i] == b[j])
                    ans = dp[i+1][j+1] ;
                else
                {
                    // Insert
                    int insertAns = 1 + dp[i][j+1] ; 

                    // Delete
                    int deleteAns = 1 + dp[i+1][j] ; 

                    // Replace
                    int replaceAns = 1 + dp[i+1][j+1] ;

                    ans = min(insertAns , min(deleteAns , replaceAns)) ;
                }

                dp[i][j] = ans ;
            }
        }

        return dp[0][0] ;
    }

public:
    int minDistance(string word1, string word2) {
        return solve(word1 , word2) ;
    }
};












class SO {
    int solve(string& a , string& b)
    {
        vector<int> curr(b.length()+1 , 0) ;
        vector<int> next(b.length()+1 , 0) ;


        // Base Case
        for (int j = 0 ; j < b.length() ; j++)
            next[j] = b.length() - j ;

        
        for (int i = a.length() - 1 ; i >= 0 ; i--)
        {
            // For Base Case
            curr[b.length()] = a.length() - i ;
            
            for (int j = b.length() - 1 ; j >= 0 ; j--)
            {
                int ans = 0 ;
                if (a[i] == b[j])
                    ans = next[j+1] ;
                else
                {
                    // Insert
                    int insertAns = 1 + curr[j+1] ; 

                    // Delete
                    int deleteAns = 1 + next[j] ; 

                    // Replace
                    int replaceAns = 1 + next[j+1] ;

                    ans = min(insertAns , min(deleteAns , replaceAns)) ;
                }

                curr[j] = ans ;
            }
            next = curr ;
        }

        return next[0] ;
    }

public:
    int minDistance(string word1, string word2) {
        return solve(word1 , word2) ;
    }
};











int main() {


    string word1 = "horse";
    string word2 = "ros";

    cout << "Word1: " << word1 << ", Word2: " << word2 << "\n\n";

    Recursion rec;
    cout << "[1] Recursion: " << rec.minDistance(word1, word2) << "\n";

    Recursion_Memoization rec_memo;
    cout << "[2] Recursion + Memoization: " << rec_memo.minDistance(word1, word2) << "\n";

    Tabulation tab;
    cout << "[3] Tabulation: " << tab.minDistance(word1, word2) << "\n";

    SO so;
    cout << "[4] Space Optimized: " << so.minDistance(word1, word2) << "\n";
    
    return 0;
}

