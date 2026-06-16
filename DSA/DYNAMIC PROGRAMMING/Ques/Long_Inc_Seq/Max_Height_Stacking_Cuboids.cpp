// Maximum Height by Stacking Cuboids 




/*

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.



*/






#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;






// Time Complexity: O(n^2)

// Space Complexity: O(n)





class Solution {
    bool check(vector<int> &base , vector<int>& newBox)
    {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
            return true ;
        else
            return false ;
    }


    int solve(int n , vector<vector<int>> &a)
    {
        vector<int> currRow(n+1 , 0) ;
        vector<int> nextRow(n+1 , 0) ;

        for (int curr = n-1 ; curr >= 0 ; curr--)
        {
            for (int prev = curr - 1 ; prev >= -1 ; prev--)
            {
                // Include
                int take = 0 ;
                if (prev == -1 || check(a[curr] , a[prev]))
                    take = a[curr][2] + nextRow[curr + 1] ;
                
                // Exclude 
                int notTake = 0 + nextRow[prev + 1] ;

                currRow[prev + 1] = max(take , notTake) ;
            }

            nextRow = currRow ;
        }

        return nextRow[0] ;
    }
    
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        
        // Step1 : Sort all dimensions for every cuboid

        for (auto &a : cuboids)
            sort(a.begin() , a.end()) ;
        
        // Step2 : Sort all cuboids basis on w or l
        sort(cuboids.begin() , cuboids.end()) ;

        // Step3 : Use LIS Logic
        return solve(cuboids.size() , cuboids) ;
    }
};






int main() {

    Solution sol;

    // Sample test case
    vector<vector<int>> cuboids = {
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}
    };

    int result = sol.maxHeight(cuboids);
    cout << "Maximum stack height: " << result << endl;
    
    return 0;
}




