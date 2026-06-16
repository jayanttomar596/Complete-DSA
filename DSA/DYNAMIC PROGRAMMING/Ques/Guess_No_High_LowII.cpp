// Guess Number Higher or Lower II




/*

We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

*/








#include <iostream>
#include <vector>
using namespace std;








// | Approach               | Time Complexity | Space Complexity |
// | ---------------------- | --------------- | ---------------- |
// | Recursion              |  O(2^n)         |  O(n)            |
// | Memoization (Top-Down) |  O(n^3)         |  O(n^2)          |
// | Tabulation (Bottom-Up) |  O(n^3)         |  O(n^2)          |






class Recursion {
    int solve(int start , int end)
    {
        if (start >= end)
            return 0 ;
        
        int maxi = INT_MAX ;
        for (int i = start ; i <= end ; i++)
        {
            maxi = min(maxi , i+max(solve(start , i-1) , solve(i+1 , end))) ;
        }

        return maxi ;
    }
public:
    int getMoneyAmount(int n) {
        return solve(1 , n) ;
    }
};









class Recursion_Memoization {
    int solve(int start , int end , vector<vector<int>> & dp)
    {
        if (start >= end)
            return 0 ;

        if (dp[start][end] != -1)
            return dp[start][end] ;
        
        int maxi = INT_MAX ;
        for (int i = start ; i <= end ; i++)
        {
            maxi = min(maxi , i+max(solve(start , i-1 , dp) , solve(i+1 , end , dp))) ;
        }

        return dp[start][end] = maxi ;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1)) ;
        return solve(1 , n , dp) ;
    }
};









class Tabulation {
    int solve(int n)
    {
        vector<vector<int>> dp(n+2 , vector<int>(n+2 , 0 )) ;

        for (int start = n ; start >= 1 ; start--)
        {
            for (int end = start ; end <= n ; end++)
            {
                if (start == end)
                    continue ;
                else
                {
                    int maxi = INT_MAX ;
                    for (int i = start ; i <= end ; i++)
                    {
                        maxi = min(maxi , i+max(dp[start][i-1] , dp[i+1][end])) ;
                    }
                    dp[start][end] = maxi ;
                }
            }
        }

        return dp[1][n] ;
    }
public:
    int getMoneyAmount(int n) {
        return solve(n) ;
    }
};










int main() {

    int n = 10; // Example: Number range from 1 to 10

    Recursion rec;
    Recursion_Memoization memo;
    Tabulation tab;

    cout << "Testing with n = " << n << endl;

    // NOTE: Pure recursion is very slow for larger n like 10+
    // So keep n <= 5 for it unless you want to wait.
    if (n <= 5) {
        cout << "[Recursion Only]        Minimum cost: " << rec.getMoneyAmount(n) << endl;
    } else {
        cout << "[Recursion Only]        Skipped (Too slow for n > 5)" << endl;
    }

    cout << "[Recursion + Memoization] Minimum cost: " << memo.getMoneyAmount(n) << endl;
    cout << "[Tabulation]              Minimum cost: " << tab.getMoneyAmount(n) << endl;

    
    return 0;
}









