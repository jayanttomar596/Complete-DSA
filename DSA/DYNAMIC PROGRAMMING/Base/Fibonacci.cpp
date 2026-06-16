#include <iostream>
#include <vector>
using namespace std;






// Recursion + Memoization Approach
// T.C. -> O(N)
// S.C. -> O(N)  { O(N) + O(N) }
class Top_Down {

    int fib_dp(int n , vector<int> &dp)
    {
        // Base Case
        if (n <= 1)
            return n ;

        // Step 3
        if (dp[n] != -1)
            return dp[n] ;

        // Step 2
        dp[n] = fib(n-1) + fib(n-2) ;
        return dp[n] ;
    }

public:
    int fib(int n) {

        // Step1
        vector<int> dp (n+1 , -1) ;

        return fib_dp(n , dp) ;
    }
};






// Tabulation Approach
// T.C. -> O(N)
// S.C. -> O(N) 
class Bottom_Up
{

    public:
    int fib(int n) {

        // Step1 :
        vector<int> dp (n+1 ) ;

        // Step2 :
        dp[1] = 1 ;
        dp[0] = 0 ;

        // Step3 :
        for (int i = 2 ; i <= n ; i++)
            dp[i] = dp[i-1] + dp[i-2] ;
        
        // Step4 :
        return dp[n] ;
    }
};





// T.C. -> O(N)
// S.C. -> O(1)

class Space_Opt
{

    public:
    int fib(int n) {

        int prev1 = 1 ; 
        int prev2 = 0 ;
        int curr = 1 ;

        if (n == 0)
            return prev2 ;

        for (int i = 2 ; i <= n ; i++)
        {
            curr = prev1 + prev2 ;
            // Shift Logic
            prev2 = prev1 ;
            prev1 = curr ;
        }

        return curr  ;

    }
} ;






int main() {


    Top_Down sol1;
    Bottom_Up sol2;
    Space_Opt sol3;

    // Example Test Cases
    int n1 = 1;
    int n2 = 10;
    int n3 = 20;

    cout << "Fibonacci of " << n1 << " = " << sol1.fib(n1) << endl;
    cout << "Fibonacci of " << n2 << " = " << sol1.fib(n2) << endl;
    cout << "Fibonacci of " << n3 << " = " << sol1.fib(n3) << endl;



    cout << "\n\nFibonacci of " << n1 << " = " << sol2.fib(n1) << endl;
    cout << "Fibonacci of " << n2 << " = " << sol2.fib(n2) << endl;
    cout << "Fibonacci of " << n3 << " = " << sol2.fib(n3) << endl;



    cout << "\n\nFibonacci of " << n1 << " = " << sol2.fib(n1) << endl;
    cout << "Fibonacci of " << n2 << " = " << sol2.fib(n2) << endl;
    cout << "Fibonacci of " << n3 << " = " << sol2.fib(n3) << endl;

    // Index:     0  1  2  3  4  5  6  ...
    // Fibonacci: 0  1  1  2  3  5  8  ...

    
    return 0;
}





