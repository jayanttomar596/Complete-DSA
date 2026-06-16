// Perfect Squares





/*

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Input: n = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 

*/








#include <iostream>
#include <vector>
using namespace std;







// | Approach                | Time Complexity       | Space Complexity   |
// | ----------------------- | --------------------- | ------------------ |
// | Recursion               | Exponential `O(√n^n)` | O(n) (stack depth) |
// | Recursion + Memoization | `O(n * √n)`           | O(n)               |
// | Tabulation              | `O(n * √n)`           | O(n)               |







class Recursion {
    int solve(int n)
    {
        // Base Case
        if (n == 0)
            return 0 ;
        
        int ans = n ;
        for (int i = 1 ; i*i <= n ; i++)
        {
            int temp = i*i ;
            ans = min(ans , 1+solve(n-temp)) ;
        }

        return ans ;
    }

public:
    int numSquares(int n) {
        return solve(n) ;
    }
};







class Recursion_Memoization {
    int solve(int n , vector<int> &dp)
    {
        // Base Case
        if (n == 0)
            return 0 ;

        if (dp[n] != -1) 
            return dp[n] ;
        
        int ans = n ;
        for (int i = 1 ; i*i <= n ; i++)
        {
            int temp = i*i ;
            ans = min(ans , 1+solve(n-temp , dp)) ;
        }

        dp[n] = ans ;
        return dp[n] ;
    }

public:
    int numSquares(int n) {
        vector<int> dp(n+1 , -1) ;
        return solve(n , dp) ;
    }
};








class  Tabulation {
    int solve(int n)
    {
        vector<int> dp(n+1 , INT_MAX) ;
        dp[0] = 0 ;

        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j*j <= n ; j++)  // is loop me j*j <= i bhi kar sakte hai 
            {
                int temp = j*j ;

                if (i - temp >= 0)
                    dp[i] = min(dp[i] , 1 + dp[i - temp]) ;
            }
        }

        return dp[n] ;
    }

public:
    int numSquares(int n) {
        return solve(n) ;
    }
};







int main() {

    int n = 12;

    Recursion rec;
    cout << "Recursion: " << rec.numSquares(n) << endl;

    Recursion_Memoization memo;
    cout << "Memoization: " << memo.numSquares(n) << endl;

    Tabulation tab;
    cout << "Tabulation: " << tab.numSquares(n) << endl;
    
    return 0;
}







