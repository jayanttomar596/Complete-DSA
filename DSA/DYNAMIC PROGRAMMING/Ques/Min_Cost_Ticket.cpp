// Minimum Cost For Tickets




/*

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.



*/







#include <iostream>
#include <vector>
#include <queue>
using namespace std;





// | Approach           | Time Complexity | Space Complexity | 
// | ------------------ | --------------- | ---------------- | 
// | **1. Recursion**   | O(3^N)          | O(N)             | 
// | **2. Memoization** | O(N)            | O(N)             | 
// | **3. Tabulation**  | O(N)            | O(N)             | 
// | **3. Space Optim*  | O(N)            | O(N) or O(1)     | 






class Recursion {
    int solve(int n , vector<int>& days , vector<int>& cost , int index)
    {
        // Base Case
        if (index >= n) 
            return 0 ;
        
        // 1 Day Pass
        int option1 = cost[0] + solve(n , days , cost , index+1) ;

        int i ;

        // 7 Day Pass
        for (i = index ; i < n && days[i] < days[index] + 7 ; i++) ;
        
        int option2 = cost[1] + solve(n , days , cost , i) ;

        // 30 Days Pass
        for(i = index ; i < n && days[i] < days[index] + 30 ; i++) ;

        int option3 = cost[2] + solve(n , days , cost , i) ;

        return min(option1 , min(option2 , option3)) ;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ;
        return solve(n , days , costs , 0) ;
    }
};








class Recursion_Memoization {
    int solve(int n , vector<int>& days , vector<int>& cost , int index , vector<int> &dp)
    {
        // Base Case
        if (index >= n) 
            return 0 ;

        if (dp[index] != -1)
            return dp[index] ;
        
        // 1 Day Pass
        int option1 = cost[0] + solve(n , days , cost , index+1 , dp) ;

        int i ;

        // 7 Day Pass
        for (i = index ; i < n && days[i] < days[index] + 7 ; i++);
        
        int option2 = cost[1] + solve(n , days , cost , i , dp) ;

        // 30 Days Pass
        for(i = index ; i < n && days[i] < days[index] + 30 ; i++);

        int option3 = cost[2] + solve(n , days , cost , i , dp) ;

        dp[index] = min(option1 , min(option2 , option3)) ;
        return dp[index] ;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ;

        vector<int> dp(n+1 , -1) ;
        return solve(n , days , costs , 0 , dp) ;
    }
};









class Tabulation {
    int solve(int n , vector<int>& days , vector<int>& cost , int index)
    {
        vector<int> dp(n+1 , INT_MAX) ;
        dp[n] = 0 ;

        for (int k = n-1 ; k >= 0 ; k--)
        {
            // 1 Day Pass
            int option1 = cost[0] + dp[k+1] ;

            int i ;

            // 7 Day Pass
            for (i = k ; i < n && days[i] < days[k] + 7 ; i++);
        
            int option2 = cost[1] + dp[i] ;

            // 30 Days Pass
            for(i = k ; i < n && days[i] < days[k] + 30 ; i++);

            int option3 = cost[2] + dp[i] ;

            dp[k] = min(option1 , min(option2 , option3)) ;
        }  
        
        return dp[0] ;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ;
        return solve(n , days , costs , 0 ) ;
    }
};







class Space_Optimization {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            int n = days.size() ;
            
            int ans = 0 ;
    
            queue<pair<int , int>> month ;
            queue<pair<int , int>> week ;
    
    
            for (int day : days)
            {
    
                // Step1 : Remove expired days
                while(!month.empty() && month.front().first + 30 <= day)
                    month.pop() ;
                
                while(!week.empty() && week.front().first + 7 <= day)
                    week.pop() ;
                
    
                // Step2 : Add cost for current day
                week.push(make_pair(day , ans + costs[1])) ;
                month.push(make_pair(day , ans + costs[2])) ;
    
                // Step3 : Ans Update
                ans = min(ans+costs[0] , min(week.front().second , month.front().second)) ;
            }
    
            return ans ;
        }
};








int main() {

    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    Recursion rec;
    Recursion_Memoization memo;
    Tabulation tab;
    Space_Optimization opt;

    cout << "Approach 1 - Recursion: " << rec.mincostTickets(days, costs) << endl;
    cout << "Approach 2 - Memoization: " << memo.mincostTickets(days, costs) << endl;
    cout << "Approach 3 - Tabulation: " << tab.mincostTickets(days, costs) << endl;
    cout << "Approach 4 - Space Optimized: " << opt.mincostTickets(days, costs) << endl;
    
    return 0;
}







