// Minimum Sideway Jumps



/*

There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.



*/






#include <iostream>
#include <vector>
using namespace std;







// | Approach                | Time Complexity | Space Complexity | 
// | ----------------------- | --------------- | ---------------- | 
// | Recursion               | O(3ⁿ)           | O(n)             | 
// | Recursion + Memoization | O(3 × n) = O(n) | O(n)             | 
// | Tabulation              | O(3 × n) = O(n) | O(n)             | 
// | Space Optimization (SO) | O(3 × n) = O(n) | O(1)             |








class Recursion {

    int solve(vector<int>& obstacles , int currlane , int currpos)
    {
        // Base Case 
        int n = obstacles.size() - 1 ;
        if (currpos == n)
            return 0 ;
        
        if (obstacles[currpos + 1] != currlane)
            return solve(obstacles , currlane , currpos + 1) ;
        else
        {
            // Sideways Jump
            int ans = INT_MAX ;
            for (int i = 1 ; i <= 3 ; i++)
            {
                if (currlane != i && obstacles[currpos] != i)
                    ans = min(ans , 1 + solve(obstacles , i , currpos)) ;
            }

            return ans ;
        }
    }

public:

    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles , 2 , 0) ;
    }
};







class Recursion_Memoization {

    int solve(vector<int>& obstacles , int currlane , int currpos , vector<vector<int>>& dp)
    {
        // Base Case 
        int n = obstacles.size() - 1 ;
        if (currpos == n)
            return 0 ;
        
        if (dp[currlane][currpos] != -1)
            return dp[currlane][currpos] ;
        
        if (obstacles[currpos + 1] != currlane)
            return solve(obstacles , currlane , currpos + 1 , dp) ;
        else
        {
            // Sideways Jump
            int ans = INT_MAX ;
            for (int i = 1 ; i <= 3 ; i++)
            {
                if (currlane != i && obstacles[currpos] != i)
                    ans = min(ans , 1 + solve(obstacles , i , currpos , dp)) ;
            }

            dp[currlane][currpos] = ans ;
            return dp[currlane][currpos] ;
        }
    }

public:

    int minSideJumps(vector<int>& obstacles) {

        vector<vector<int>> dp(4 , vector<int>(obstacles.size() , -1)) ;
        return solve(obstacles , 2 , 0 , dp) ;
    }
};










class Tabulation {

    int solve(vector<int>& obstacles)
    {
        // Base Case 
        int n = obstacles.size() - 1 ;
        vector<vector<int>> dp(4 , vector<int> (obstacles.size() , 1e9)) ;

        dp[0][n] = 0 ;
        dp[1][n] = 0 ;
        dp[2][n] = 0 ;
        dp[3][n] = 0 ;
         
        
        
        for (int currpos = n-1 ; currpos >= 0 ; currpos--)
        {
            for (int currlane = 1 ; currlane <= 3 ; currlane++)
            {
                if (obstacles[currpos + 1] != currlane)
                    dp[currlane][currpos] = dp[currlane][currpos+1] ;
                else
                {
                    // Sideways Jump
                    int ans = 1e9 ;
                    for (int i = 1 ; i <= 3 ; i++)
                    {
                        if (currlane != i && obstacles[currpos] != i)
                            ans = min(ans , 1 + dp[i][currpos + 1]) ;
                    }

                    dp[currlane][currpos] = ans ;
                }
            }
        }      

        return min(dp[2][0] , min(1+dp[1][0] , 1+dp[3][0])) ;
    }

public:

    int minSideJumps(vector<int>& obstacles) {

        return solve(obstacles) ;
    }
};









class SO {

    int solve(vector<int>& obstacles)
    {
        // Base Case 
        int n = obstacles.size() - 1 ;
        
        vector<int> curr (4 , INT_MAX) ;
        vector<int> next(4 , INT_MAX) ;

        next[0] = 0 ;
        next[1] = 0 ;
        next[2] = 0 ;
        next[3] = 0 ;
         
        
        
        for (int currpos = n-1 ; currpos >= 0 ; currpos--)
        {
            for (int currlane = 1 ; currlane <= 3 ; currlane++)
            {
                if (obstacles[currpos + 1] != currlane)
                    curr[currlane] = next[currlane] ;
                else
                {
                    // Sideways Jump
                    int ans = 1e9 ;
                    for (int i = 1 ; i <= 3 ; i++)
                    {
                        if (currlane != i && obstacles[currpos] != i)
                            ans = min(ans , 1 + next[i]) ;
                    }

                    curr[currlane] = ans ;
                }
            }

            next = curr ;
        }      

        return min(next[2] , min(1+next[1] , 1+next[3])) ;
    }

public:

    int minSideJumps(vector<int>& obstacles) {

        return solve(obstacles) ;
    }
};









int main() {

    vector<int> obstacles1 = {0, 1, 2, 3, 0};       // Expected: 2
    vector<int> obstacles2 = {0, 1, 1, 3, 3, 0};    // Expected: 0
    vector<int> obstacles3 = {0, 2, 1, 0, 3, 0};    // Expected: 2

    Recursion rec;
    Recursion_Memoization memo;
    Tabulation tab;
    SO opt;

    cout << "Testing on [0,1,2,3,0]:" << endl;
    cout << "Recursion: " << rec.minSideJumps(obstacles1) << endl;
    cout << "Memoization: " << memo.minSideJumps(obstacles1) << endl;
    cout << "Tabulation: " << tab.minSideJumps(obstacles1) << endl;
    cout << "Space Optimized: " << opt.minSideJumps(obstacles1) << endl;
    cout << endl;

    cout << "Testing on [0,1,1,3,3,0]:" << endl;
    cout << "Recursion: " << rec.minSideJumps(obstacles2) << endl;
    cout << "Memoization: " << memo.minSideJumps(obstacles2) << endl;
    cout << "Tabulation: " << tab.minSideJumps(obstacles2) << endl;
    cout << "Space Optimized: " << opt.minSideJumps(obstacles2) << endl;
    cout << endl;

    cout << "Testing on [0,2,1,0,3,0]:" << endl;
    cout << "Recursion: " << rec.minSideJumps(obstacles3) << endl;
    cout << "Memoization: " << memo.minSideJumps(obstacles3) << endl;
    cout << "Tabulation: " << tab.minSideJumps(obstacles3) << endl;
    cout << "Space Optimized: " << opt.minSideJumps(obstacles3) << endl;
    cout << endl;

    
    return 0;
}



