// Reducing Dishes






/*

A chef has collected data on the satisfaction level for each dish they can prepare. The chef can choose to prepare any subset of the dishes and can prepare them in any order.

A dish takes 1 unit of time to prepare, and the satisfaction of a dish depends on when it is cooked. Specifically, if the chef cooks the ith dish at time 𝑡t, the total satisfaction will be: satisfaction  [𝑖]×𝑡 satisfaction[i]×t , The chef wants to maximize the sum of satisfaction values for the dishes they prepare.


*/







#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;






// | Approach                | Time Complexity | Space Complexity |
// | ----------------------- | --------------- | ---------------- |
// | Recursion               | $O(2^n)$        | O(n)             |
// | Recursion + Memoization | $O(n^2)$        | $O(n^2) + O(n)$  |
// | Tabulation              | $O(n^2)$        | $O(n^2)$         |
// | Space Optimized (SO)    | $O(n^2)$        | $O(n)$           |







class Recursion 
{
    int solve(vector<int>& satisfaction , int index , int time)
    {
        // Base Case
        if (index == satisfaction.size())
            return 0 ;
        
        int include  = satisfaction[index]*(time+1) + solve(satisfaction , index+1 , time+1) ;
        int exclude = 0 + solve(satisfaction , index + 1 , time) ;

        return max(exclude , include) ;
    }
 
    
public :

    int maxSatisfaction(vector<int>& satisfaction)
    {
        // Sort the Vector
        sort(satisfaction.begin() , satisfaction.end()) ;
        return solve(satisfaction , 0 , 0) ;
    }     
};







class Recursion_Memoization
{
    int solve(vector<int>& satisfaction , int index , int time , vector<vector<int>> &dp)
    {
        // Base Case
        if (index == satisfaction.size())
            return 0 ;
        
        if (dp[index][time] != -1)
            return dp[index][time] ;
        
        int include  = satisfaction[index]*(time+1) + solve(satisfaction , index+1 , time+1 , dp) ;
        int exclude = 0 + solve(satisfaction , index + 1 , time , dp) ;

        return dp[index][time] = max(exclude , include) ;
    }


public :

    int maxSatisfaction(vector<int>& satisfaction)
    {
        // Sort the Vector
        sort(satisfaction.begin() , satisfaction.end()) ;

        int n = satisfaction.size() ; 
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1)) ;
        return solve(satisfaction , 0 , 0 , dp) ;
    }     
};







class Tabulation 
{
    int solve(vector<int>& satisfaction)
    {
        // Base Case
        int n = satisfaction.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0)) ;

        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int time = index ; time >= 0 ; time --)
            {
                int include = satisfaction[index]*(time+1) + dp[index+1][time+1] ;
                int exclude = 0 + dp[index+1][time] ;

                dp[index][time] = max(include , exclude) ;
            }
        }

        return dp[0][0] ;
    }


public :

    int maxSatisfaction(vector<int>& satisfaction)
    {
        // Sort the Vector
        sort(satisfaction.begin() , satisfaction.end()) ;

        int n = satisfaction.size() ;

        return solve(satisfaction) ;
    }     
};







class SO 
{
    int solve(vector<int>& satisfaction)
    {
        // Base Case
        int n = satisfaction.size() ;
        
        vector<int> curr(n+1 , 0) ;
        vector<int> next(n+1 , 0) ;

        for (int index = n-1 ; index >= 0 ; index--)
        {
            for (int time = index ; time >= 0 ; time --)
            {
                int include = satisfaction[index]*(time+1) + next[time+1] ;
                int exclude = 0 + next[time] ;

                curr[time] = max(include , exclude) ;
            }

            next = curr ;
        }

        return next[0] ;
    }


public :

    int maxSatisfaction(vector<int>& satisfaction)
    {
        // Sort the Vector
        sort(satisfaction.begin() , satisfaction.end()) ;

        int n = satisfaction.size() ;

        return solve(satisfaction) ;
    }     
};






// T.C. -> O(nlogn)
// S.C. -> O(1)


class Greedy {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend()); // Sort in descending order
        
        int total = 0;   // Running sum of included dishes
        int result = 0;  // Final answer

        for (int s : satisfaction) {
            total += s;     // Try including this dish
            if (total <= 0)
                break;      // If it doesn't help, stop
            result += total;
        }

        return result;
    }
};











int main() {

    vector<int> satisfaction = {-1, -8, 0, 5, -9};

    Recursion r;
    Recursion_Memoization rm;
    Tabulation t;
    SO so;
    Greedy gr ;


    cout << "Recursion Only: " << r.maxSatisfaction(satisfaction) << endl;
    cout << "Recursion + Memoization: " << rm.maxSatisfaction(satisfaction) << endl;
    cout << "Tabulation: " << t.maxSatisfaction(satisfaction) << endl;
    cout << "Space Optimized: " << so.maxSatisfaction(satisfaction) << endl;
    cout << "Greedy Appraoch : " << gr.maxSatisfaction(satisfaction) << endl;
    
    return 0;
}