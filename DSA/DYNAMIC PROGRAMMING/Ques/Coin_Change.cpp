// Coin Change



/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

*/





#include <iostream>
#include <vector>
using namespace std;





// n = number of coin denominations (coins.size())

// amount = the target value (x)


// T.C. -> O(N^X)
// S.C. -> O(X)

class Solution_Recursion {
    int solveRec(vector<int> &coins , int x)
    {
        // Base Case
        if (x == 0)
            return 0 ;
        
        if (x < 0)
            return INT_MAX ;
        
        int mini = INT_MAX ;
        for (int i = 0 ; i < coins.size() ; i++)
        {
            int ans = solveRec(coins , x-coins[i]) ;
            if (ans != INT_MAX)
                mini = min(mini , 1+ans) ;
        }

        return mini ;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveRec(coins , amount) ;
        if (ans == INT_MAX)
            return -1 ;
        
        return ans ;
    }
};






// T.C. -> O(N * X)
// S.C. -> O(X)

class Solution_Memoization {

    int solveMem(vector<int> &num , int x , vector<int> &dp)
    {
        // Base Case
        if (x == 0)
            return 0 ;
        
        if (x < 0)
            return INT_MAX ;
        
        if (dp[x] != -1)
            return dp[x] ;
        
        int mini = INT_MAX ;
        for (int i = 0 ; i < num.size() ; i++ )
        {
            int ans = solveMem(num , x-num[i] , dp) ;
            if (ans != INT_MAX)
                mini = min(mini , 1+ans) ;
        }

        dp[x] = mini ;


        return mini ; 
    }


public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1 , -1) ;
        int ans = solveMem(coins , amount , dp) ;

        if (ans == INT_MAX)
            return -1 ;
        else
            return ans ;    
    }
};







// T.C. -> O(N * X)
// S.C. -> O(X)

class Solution_Tabulation {

    int solveTab(vector<int> &num , int x )
    {
        vector<int> dp(x+1 , INT_MAX) ;
        dp[0] = 0 ;

        for (int i = 1 ; i <= x ; i++)
        {
            // I am trying to solve for every amount figure from 1 to x
            for (int j = 0 ; j < num.size() ; j++)
            {
                if ( i - num[j] >= 0 && dp[i - num[j]] != INT_MAX )
                {
                    dp[i] = min(dp[i] , 1 + dp[i - num[j]] ) ;
                }
            }
        }

        if (dp[x] == INT_MAX)
            return -1 ;

        return dp[x] ;    
    }


public:
    int coinChange(vector<int>& coins, int amount) {  

        return solveTab(coins , amount) ;

    }
};







int main() {

    vector<int> coins = {1, 2, 5};  // Coin denominations
    int amount = 11;  // Target amount



    // Testing Recursion approach
    Solution_Recursion recSolution;
    int resultRec = recSolution.coinChange(coins, amount);
    if (resultRec == -1)
        cout << "Recursion: Cannot make up the amount." << endl;
    else
        cout << "Recursion: Fewest coins needed: " << resultRec << endl;



    // Testing Memoization approach
    Solution_Memoization memSolution;
    int resultMem = memSolution.coinChange(coins, amount);
    if (resultMem == -1)
        cout << "Memoization: Cannot make up the amount." << endl;
    else
        cout << "Memoization: Fewest coins needed: " << resultMem << endl;



    // Testing Tabulation approach
    Solution_Tabulation tabSolution;
    int resultTab = tabSolution.coinChange(coins, amount);
    if (resultTab == -1)
        cout << "Tabulation: Cannot make up the amount." << endl;
    else
        cout << "Tabulation: Fewest coins needed: " << resultTab << endl;

    
        
    return 0;
}







