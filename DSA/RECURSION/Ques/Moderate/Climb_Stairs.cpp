// Problem Statement 

// You have been given a number of stairs . Initially , you are at the 0th stair , and you need to reach the Nth stair . Each time you can either climb one step or two steps . You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step .



#include <iostream>
using namespace std;



long long int  count_ways_to_climbstairs(long long nStairs)
{

    // Base Case
    if (nStairs < 0)
        return 0 ;

    if (nStairs == 0)
        return 1 ;

    // Recursion Call
    return count_ways_to_climbstairs(nStairs - 1) + count_ways_to_climbstairs(nStairs - 2);
}




// 2nd Reccursion method 
class Solution_1
{
private : 
    int solve(long long nStairs , int i)
    {
        // Base Case
        if ( i == nStairs)
            return 1 ;
        
        if (i > nStairs)
            return 0 ;
        
        return (solve(nStairs , i+1) + solve(nStairs , i+2) ) ;
    }


    int countDistinctWayToClimbStair(long long nStairs)
    {
        int ans = solve(nStairs , 0) ;

        return ans ;
    }
};







int main() {

    int n ;
    cout<<"Enter the value of n = ";
    cin>>n;

    cout<<"No of Distinct Ways to climb from 0th stair to nth stair = "<<count_ways_to_climbstairs(n)<<endl;

    return 0;
}





