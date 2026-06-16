// Best Time to Buy and Sell Stock II





/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

*/







#include <iostream>
#include <vector>
using namespace std;






// | Version                 | Time Complexity | Space Complexity |
// | ----------------------- | --------------- | ---------------- |
// | Recursion               |  O(2^n)         |  O(n)            |
// | Recursion + Memoization |  O(n)           |  O(n)            |
// | Tabulation              |  O(n)           |  O(n)            |
// | Space Optimized         |  O(n)           |  O(1)            |








class Recursion {
    int solve(int index , int buy , vector<int>& prices)
    {
        if (index == prices.size())
            return 0 ;
        
        int profit = 0 ;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(index+1 , 0 , prices) ;
            int skipKaro = 0 + solve(index+1 , 1 , prices) ;
            profit = max(buyKaro , skipKaro) ;
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1 , 1 , prices) ;
            int skipKaro = 0 + solve(index+1 , 0 , prices) ;
            profit = max(sellKaro , skipKaro) ;
        }

        return profit ;
    }

public:
    int maxProfit(vector<int>& prices) {
        return  solve(0 , 1 , prices) ;
    }
};









class Recursion_Memoization {
    int solve(int index , int buy , vector<int>& prices , vector<vector<int>>& dp)
    {
        if (index == prices.size())
            return 0 ;
        
        if (dp[index][buy] != -1)
            return dp[index][buy] ;
        
        int profit = 0 ;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(index+1 , 0 , prices , dp) ;
            int skipKaro = 0 + solve(index+1 , 1 , prices , dp) ;
            profit = max(buyKaro , skipKaro) ;
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1 , 1 , prices , dp) ;
            int skipKaro = 0 + solve(index+1 , 0 , prices , dp) ;
            profit = max(sellKaro , skipKaro) ;
        }

        return dp[index][buy] = profit ;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp(n , vector<int>(2 , -1)) ;
        return  solve(0 , 1 , prices , dp) ;
    }
};









class Tabulation {
    int solve(vector<int>& prices)
    {
        int n = prices.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(2 , 0)) ;


        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int buy = 0 ; buy <= 1 ; buy++)
            {
                int profit = 0 ;
                if (buy)
                {
                    int buyKaro = -prices[index] + dp[index+1][0] ;
                    int skipKaro = 0 + dp[index+1][1] ;
                    profit = max(buyKaro , skipKaro) ;
                }
                else
                {
                    int sellKaro = prices[index] + dp[index+1][1] ;
                    int skipKaro = 0 + dp[index+1][0] ;
                    profit = max(sellKaro , skipKaro) ;
                }  

                dp[index][buy] = profit ;             
            }
        }
        


        return dp[0][1] ;
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
        vector<int> curr(2 , 0) ;
        vector<int> next(2 , 0) ;


        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int buy = 0 ; buy <= 1 ; buy++)
            {
                int profit = 0 ;
                if (buy)
                {
                    int buyKaro = -prices[index] + next[0] ;
                    int skipKaro = 0 + next[1] ;
                    profit = max(buyKaro , skipKaro) ;
                }
                else
                {
                    int sellKaro = prices[index] + next[1] ;
                    int skipKaro = 0 + next[0] ;
                    profit = max(sellKaro , skipKaro) ;
                }  

                curr[buy] = profit ;             
            }

            next = curr ;
        }

        return next[1] ;
    }

public:
    int maxProfit(vector<int>& prices) {
        return  solve(prices) ;
    }
};










int main() {


    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Sample input

    Recursion r;
    cout << "Recursion: " << r.maxProfit(prices) << endl;

    Recursion_Memoization rm;
    cout << "Recursion + Memoization: " << rm.maxProfit(prices) << endl;

    Tabulation t;
    cout << "Tabulation: " << t.maxProfit(prices) << endl;

    SO so;
    cout << "Space Optimized: " << so.maxProfit(prices) << endl;
    
    return 0;
}



