// Best Time to Buy and Sell Stock III





/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/







#include <iostream>
#include <vector>
using namespace std;







// | Approach                | Time Complexity | Space Complexity 
// | ----------------------- | --------------- | -----------------
// | Recursion               |  O(2^n)         |  O(n)  (stack)   
// | Recursion + Memoization |  O(n)           |  O(n)            
// | Tabulation (Bottom-Up)  |  O(n)           |  O(n)            
// | Space Optimized         |  O(n)           |  O(1)  







class Recursion {
    int solve(int index , int buy , vector<int>& prices , int limit)
    {
        if (index == prices.size())
            return 0 ;
        
        if (limit == 0)
            return 0 ;
        
        int profit = 0 ;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(index+1 , 0 , prices , limit) ;
            int skipKaro = 0 + solve(index+1 , 1 , prices , limit) ;
            profit = max(buyKaro , skipKaro) ;
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1 , 1 , prices , limit-1) ;
            int skipKaro = 0 + solve(index+1 , 0 , prices , limit) ;
            profit = max(sellKaro , skipKaro) ;
        }

        return profit ;
    }
public:
    int maxProfit(vector<int>& prices) {
        return  solve(0 , 1 , prices , 2) ;
    }
};










class Recursion_Memoization {
    int solve(int index , int buy , vector<int>& prices , int limit , vector<vector<vector<int>>> & dp) 
    {
        if (index == prices.size())
            return 0 ;
        
        if (limit == 0)
            return 0 ;
        
        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit] ;
        
        int profit = 0 ;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(index+1 , 0 , prices , limit , dp) ;
            int skipKaro = 0 + solve(index+1 , 1 , prices , limit , dp) ;
            profit = max(buyKaro , skipKaro) ;
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1 , 1 , prices , limit-1 , dp) ;
            int skipKaro = 0 + solve(index+1 , 0 , prices , limit , dp) ;
            profit = max(sellKaro , skipKaro) ;
        }

        return dp[index][buy][limit] = profit ;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<vector<int>>> dp (n , vector<vector<int>>(2 , vector<int>(3 , -1))) ;
        return  solve(0 , 1 , prices , 2 , dp) ;
    }
};









class Tabulation {
    int solve(vector<int>& prices) 
    {
        int n = prices.size() ;
        vector<vector<vector<int>>> dp (n+1 , vector<vector<int>>(2 , vector<int>(3 , 0))) ;

        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int buy = 0 ; buy <= 1 ; buy++)
            {
                for (int limit = 1 ; limit <= 2 ; limit++) // limit = 0 pehle hi initialize ho gaya 0
                {
                    int profit = 0 ;
                    if (buy)
                    {
                        int buyKaro = -prices[index] + dp[index+1][0][limit] ; 
                        int skipKaro = 0 + dp[index+1][1][limit] ; 
                        profit = max(buyKaro , skipKaro) ;
                    }
                    else
                    {
                        int sellKaro = prices[index] + dp[index+1][1][limit-1] ; 
                        int skipKaro = 0 + dp[index+1][0][limit] ;
                        profit = max(sellKaro , skipKaro) ;
                    }
                    dp[index][buy][limit] = profit ;
                }
            }
        }
        
        return dp[0][1][2] ;
    }
public:
    int maxProfit(vector<int>& prices) {
        return  solve(prices) ;
    }
};









class SO {
    int solve(vector<int>& prices) 
    {
        int n = prices.size() ;
        
        vector<vector<int>> curr(2 , vector<int>(3,0)) ;
        vector<vector<int>> next(2 , vector<int>(3,0)) ;

        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int buy = 0 ; buy <= 1 ; buy++)
            {
                for (int limit = 1 ; limit <= 2 ; limit++) // limit = 0 pehle hi initialize ho gaya 0
                {
                    int profit = 0 ;
                    if (buy)
                    {
                        int buyKaro = -prices[index] + next[0][limit] ; 
                        int skipKaro = 0 + next[1][limit] ; 
                        profit = max(buyKaro , skipKaro) ;
                    }
                    else
                    {
                        int sellKaro = prices[index] + next[1][limit-1] ; 
                        int skipKaro = 0 + next[0][limit] ;
                        profit = max(sellKaro , skipKaro) ;
                    }
                    curr[buy][limit] = profit ;
                }
            }

            next = curr ;
        }
        
        return next[1][2] ;
    }
public:
    int maxProfit(vector<int>& prices) {
        return  solve(prices) ;
    }
};










int main() {

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    Recursion rec;
    cout << "Recursion: " << rec.maxProfit(prices) << endl;

    Recursion_Memoization recMemo;
    cout << "Recursion + Memoization: " << recMemo.maxProfit(prices) << endl;

    Tabulation tab;
    cout << "Tabulation: " << tab.maxProfit(prices) << endl;

    SO spaceOpt;
    cout << "Space Optimized: " << spaceOpt.maxProfit(prices) << endl;
    
    return 0;
}

