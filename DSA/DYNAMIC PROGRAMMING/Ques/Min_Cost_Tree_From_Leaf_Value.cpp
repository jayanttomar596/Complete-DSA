// Minimum Cost Tree From Leaf Values





/*

Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

*/







#include <iostream>
#include <vector>
#include <map>
using namespace std;







// | Version     | Time Complexity | Space Complexity |
// | ----------- | --------------- | ---------------- |
// | Recursion   | O(n³)           | O(n²)            |
// | Memoization | O(n³)           | O(n²)            |
// | Tabulation  | O(n³)           | O(n²)            |


// It's not O(2ⁿ) because we’re not choosing 2 options per element.
// It’s O(n³) because:
//          There are O(n²) unique intervals
//          Each interval checks O(n) splits









class Recursion {
    int solve(vector<int>& arr , map<pair<int , int> , int>& maxi , int left , int right)
    {
        // Leaf Node
        if (left == right)
            return 0 ;
        
        int ans = INT_MAX ;
        for (int i = left ; i < right ; i++)
        {
            ans = min(ans , maxi[{left , i}]*maxi[{i+1 , right}] + solve(arr , maxi , left , i) + solve(arr , maxi , i+1 , right)) ;
        }

        return ans ;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int , int> , int> maxi ;

        for (int i = 0 ; i < arr.size() ; i++)
        {
            maxi[{i,i}] = arr[i] ;
            for (int j = i + 1 ; j < arr.size() ; j++)
            {
                maxi[{i , j}] = max(arr[j] , maxi[{i , j-1}]) ; 
            }
        }

        return solve(arr , maxi , 0 , arr.size()-1) ;
    }
};








class Recursion_Memoization {
    int solve(vector<int>& arr , map<pair<int , int> , int>& maxi , int left , int right , vector<vector<int>> & dp)
    {
        // Leaf Node
        if (left == right)
            return 0 ;
        
        if (dp[left][right] != -1) 
            return dp[left][right] ;
        
        int ans = INT_MAX ;
        for (int i = left ; i < right ; i++)
        {
            ans = min(ans , maxi[{left , i}]*maxi[{i+1 , right}] + solve(arr , maxi , left , i , dp) + solve(arr , maxi , i+1 , right , dp)) ;
        }

        return dp[left][right] = ans ;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int , int> , int> maxi ;
        int n = arr.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1)) ;

        for (int i = 0 ; i < arr.size() ; i++)
        {
            maxi[{i,i}] = arr[i] ;
            for (int j = i + 1 ; j < arr.size() ; j++)
            {
                maxi[{i , j}] = max(arr[j] , maxi[{i , j-1}]) ; 
            }
        }

        return solve(arr , maxi , 0 , arr.size()-1 , dp) ;
    }
};








class Tabulation {
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi)
    {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, 0));
        int n = arr.size();
        for (int left = n; left >= 0; left--)
        {
            for (int right = 1; right < n; right++)
            {
                int ans = INT_MAX;
                if (left == right)
                {
                    continue;
                    // base case
                }
                else
                {
                    for (int i = left; i < right; i++)
                    {
                  
                        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i+1][right]);
                    }
                    dp[left][right] = ans;
                }
            }
        }
        return dp[0][n-1];
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int , int> , int> maxi ;

        for (int i = 0 ; i < arr.size() ; i++)
        {
            maxi[{i,i}] = arr[i] ;
            for (int j = i + 1 ; j < arr.size() ; j++)
            {
                maxi[{i , j}] = max(arr[j] , maxi[{i , j-1}]) ; 
            }
        }

        return solve(arr , maxi) ;
    }
};










int main() {


    vector<int> arr = {6, 2, 4};  // You can change this input to test different cases

    Recursion rec;
    Recursion_Memoization memo;
    Tabulation tab;

    cout << "Input array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Recursion only: " << rec.mctFromLeafValues(arr) << endl;
    cout << "Recursion + Memoization: " << memo.mctFromLeafValues(arr) << endl;
    cout << "Tabulation (Bottom-Up DP): " << tab.mctFromLeafValues(arr) << endl;
    

    
    return 0;
}












