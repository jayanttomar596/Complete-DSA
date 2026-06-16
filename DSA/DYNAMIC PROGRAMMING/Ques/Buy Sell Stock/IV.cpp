// Best Time to Buy and Sell Stock IV






/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/









#include <iostream>
#include <vector>
using namespace std;






// | Approach               | Time Complexity | Space Complexity |
// | ---------------------- | --------------- | ---------------- |
// | Recursion (Brute)      | O(2ⁿ)           | O(n)             |
// | Memoization (Top-Down) | O(n  * k)       | O(n  * k)        |
// | Tabulation (Bottom-Up) | O(n  * k)       | O(n  * k)        |
// | Space Optimized        | O(n  * k)       | O(k)             |







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
    int maxProfit(int k, vector<int>& prices) {
        return  solve(0 , 1 , prices , k) ;
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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<vector<int>>> dp (n , vector<vector<int>>(2 , vector<int>(k+1 , -1))) ;
        return  solve(0 , 1 , prices , k , dp) ;
    }
};










class Tabulation {

    int solve(vector<int>& prices , int k) 
    {
        int n = prices.size() ;
        vector<vector<vector<int>>> dp (n+1 , vector<vector<int>>(2 , vector<int>(k+1 , 0))) ;

        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int buy = 0 ; buy <= 1 ; buy++)
            {
                for (int limit = 1 ; limit <= k ; limit++) // limit = 0 pehle hi initialize ho gaya 0
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
        
        return dp[0][1][k] ;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        return  solve(prices , k) ;
    }
};











class SO {

    int solve(vector<int>& prices , int k) 
    {
        int n = prices.size() ;
        
        vector<vector<int>> curr(2 , vector<int>(k+1,0)) ;
        vector<vector<int>> next(2 , vector<int>(k+1,0)) ;

        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int buy = 0 ; buy <= 1 ; buy++)
            {
                for (int limit = 1 ; limit <= k ; limit++) // limit = 0 pehle hi initialize ho gaya 0
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
        
        return next[1][k] ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return  solve(prices , k) ;
    }
};













// USING TRANSACTION NO or Operation Number 







// | Approach                 | Time Complexity | Space Complexity            |
// | ------------------------ | --------------- | --------------------------- |
// |  Recursion_              |  O(2^(2k) * n)  |  O(n)  (stack)              |
// |  Recursion_Memoization_  |  O(n * k)       |  O(n * k)  +  O(n)  (stack) |
// |  Tabulation_             |  O(n * k)       |  O(n * k)                   |
// |  SO_  (Space Opt.)       |  O(n * k)       |  O(k)                       |







class Recursion_ {
    int solve(int index , int operationNo , int k , vector<int> & prices)
    {
        if (index == prices.size())
            return 0 ;
        
        if (operationNo == 2*k)
            return 0 ;
        
        int profit = 0 ;
        if (operationNo%2 == 0)
        {
            // Buy Allowed
            int buyKaro = -prices[index] + solve(index+1 , operationNo + 1 , k , prices) ;
            int skipKaro = 0 + solve(index+1 , operationNo , k , prices) ;
            profit = max(buyKaro , skipKaro) ;
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1 , operationNo+1 , k , prices) ;
            int skipKaro = 0 + solve(index+1 , operationNo , k , prices) ;
            profit = max(sellKaro , skipKaro) ;
        }

        return profit ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(0 , 0 , k , prices) ;
    }
};










class Recursion_Memoization_ {
    int solve(int index , int operationNo , int k , vector<int> & prices , vector<vector<int>> & dp)
    {
        if (index == prices.size())
            return 0 ;
        
        if (operationNo == 2*k)
            return 0 ;
        
        if (dp[index][operationNo] != -1)
            return dp[index][operationNo] ;

        int profit = 0 ;
        if (operationNo%2 == 0)
        {
            // Buy Allowed
            int buyKaro = -prices[index] + solve(index+1 , operationNo + 1 , k , prices , dp) ;
            int skipKaro = 0 + solve(index+1 , operationNo , k , prices , dp) ;
            profit = max(buyKaro , skipKaro) ;
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1 , operationNo+1 , k , prices , dp) ;
            int skipKaro = 0 + solve(index+1 , operationNo , k , prices , dp) ;
            profit = max(sellKaro , skipKaro) ;
        }

        return dp[index][operationNo] = profit ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp(n , vector<int>(2*k , -1)) ;
        return solve(0 , 0 , k , prices , dp) ;
    }
};










class Tabulation_ {
    int solve(int k , vector<int> & prices)
    {
        int n = prices.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(2*k+1 , 0)) ;


        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int operationNo = 0 ; operationNo < 2*k ; operationNo++)
            {
                int profit = 0 ;
                if (operationNo%2 == 0)
                {
                    // Buy Allowed
                    int buyKaro = -prices[index] + dp[index+1][operationNo + 1] ;
                    int skipKaro = 0 + dp[index+1][operationNo] ; 
                    profit = max(buyKaro , skipKaro) ;
                }
                else
                {
                    int sellKaro = prices[index] + dp[index+1][operationNo+1] ; 
                    int skipKaro = 0 + dp[index+1][operationNo] ; 
                    profit = max(sellKaro , skipKaro) ;
                }
                dp[index][operationNo] = profit ;
            }
        }

        return dp[0][0] ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(k , prices) ;
    }
};










class SO_ {
    int solve(int k , vector<int> & prices)
    {
        int n = prices.size() ;
        
        vector<int> curr(2*k+1 , 0) ;
        vector<int> next(2*k+1 , 0) ;

        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int operationNo = 0 ; operationNo < 2*k ; operationNo++)
            {
                int profit = 0 ;
                if (operationNo%2 == 0)
                {
                    // Buy Allowed
                    int buyKaro = -prices[index] + next[operationNo + 1] ;
                    int skipKaro = 0 + next[operationNo] ; 
                    profit = max(buyKaro , skipKaro) ;
                }
                else
                {
                    int sellKaro = prices[index] + next[operationNo+1] ; 
                    int skipKaro = 0 + next[operationNo] ; 
                    profit = max(sellKaro , skipKaro) ;
                }
                curr[operationNo] = profit ;
            }
            next = curr ;
        }

        return next[0] ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(k , prices) ;
    }
};











int main() {


    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;

    Recursion r;
    Recursion_Memoization rm;
    Tabulation t;
    SO so;

    cout << "Prices: ";
    for (int price : prices) cout << price << " ";
    cout << "\nTransactions allowed (k): " << k << "\n\n";

    cout << "Recursion Output: " << r.maxProfit(k, prices) << endl;
    cout << "Memoization Output: " << rm.maxProfit(k, prices) << endl;
    cout << "Tabulation Output: " << t.maxProfit(k, prices) << endl;
    cout << "Space Optimization Output: " << so.maxProfit(k, prices) << endl;







    Recursion_ r1;
    Recursion_Memoization_ r2;
    Tabulation_ r3;
    SO_ r4;

    cout << "\n\n\n\nRecursion Only: " << r1.maxProfit(k , prices) << endl;
    cout << "Memoization:    " << r2.maxProfit(k , prices) << endl;
    cout << "Tabulation:     " << r3.maxProfit(k , prices) << endl;
    cout << "Space Optimized:" << r4.maxProfit(k , prices) << endl;

    
    return 0;
}



