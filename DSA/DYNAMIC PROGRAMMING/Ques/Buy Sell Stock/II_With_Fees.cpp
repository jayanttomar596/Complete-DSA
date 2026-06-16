// Best Time to Buy and Sell Stock with Transaction Fee





/*

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

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







// Bass II walle me buy ya sell karte hua unme se kisi ek me - fees kardo 



class Recursion {
    int solve(int index , int buy , vector<int>& prices , int fee)
    {
        if (index == prices.size())
            return 0 ;
        
        int profit = 0 ;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(index+1 , 0 , prices , fee) ;
            int skipKaro = 0 + solve(index+1 , 1 , prices , fee) ;
            profit = max(buyKaro , skipKaro) ;
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1 , 1 , prices , fee)  - fee ;
            int skipKaro = 0 + solve(index+1 , 0 , prices , fee) ;
            profit = max(sellKaro , skipKaro) ;
        }

        return profit ;
    }

public:
    int maxProfit(vector<int>& prices , int fee) {
        return  solve(0 , 1 , prices , fee) ;
    }
};









class Recursion_Memoization {
    int solve(int index , int buy , vector<int>& prices , vector<vector<int>>& dp , int fee)
    {
        if (index == prices.size())
            return 0 ;
        
        if (dp[index][buy] != -1)
            return dp[index][buy] ;
        
        int profit = 0 ;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(index+1 , 0 , prices , dp , fee) ;
            int skipKaro = 0 + solve(index+1 , 1 , prices , dp , fee) ;
            profit = max(buyKaro , skipKaro) ;
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1 , 1 , prices , dp , fee) - fee ;
            int skipKaro = 0 + solve(index+1 , 0 , prices , dp , fee) ;
            profit = max(sellKaro , skipKaro) ;
        }

        return dp[index][buy] = profit ;
    }

public:
    int maxProfit(vector<int>& prices , int fee) {
        int n = prices.size() ;
        vector<vector<int>> dp(n , vector<int>(2 , -1)) ;
        return  solve(0 , 1 , prices , dp , fee) ;
    }
};










class Tabulation {
    int solve(vector<int>& prices , int fee)
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
                    int sellKaro = prices[index] + dp[index+1][1] - fee ;
                    int skipKaro = 0 + dp[index+1][0] ;
                    profit = max(sellKaro , skipKaro) ;
                }  

                dp[index][buy] = profit ;             
            }
        }
        


        return dp[0][1] ;
    }

public:
    int maxProfit(vector<int>& prices , int fee) {
        return  solve(prices , fee) ;
    }
};









class SO {
    int solve(vector<int>& prices , int fee)
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
                    int sellKaro = prices[index] + next[1] - fee ;
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
    int maxProfit(vector<int>& prices, int fee) {
        return  solve(prices , fee) ;
    }
};




int main() {


    vector<int> prices = {1,3,2,8,4,9}; // Sample input
    int fee = 2 ;


    Recursion r;
    cout << "Recursion: " << r.maxProfit(prices , fee) << endl;

    Recursion_Memoization rm;
    cout << "Recursion_Memoization: " << rm.maxProfit(prices , fee) << endl;

    Tabulation t;
    cout << "Tabulation: " << t.maxProfit(prices , fee) << endl;

    SO so;
    cout << "Space Optimized: " << so.maxProfit(prices , fee) << endl;


    // Output = 2
    
    return 0;
}


