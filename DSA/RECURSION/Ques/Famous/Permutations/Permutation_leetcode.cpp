// PERMUTATIONS

/*

// Given an array nums of distinct integers, return all the possible permutations . You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]

*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
private :
    void solve(vector<int> nums , vector<vector<int>> &ans , int index)
    {
        // Base Case
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return ;
        }

        for (int j = index ; j<nums.size() ; j++)
        {
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            // backtrack
            swap(nums[index] , nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector <int>> ans ;

        sort(nums.begin() , nums.end());

        int index = 0 ;
        solve(nums , ans , index);

        sort(ans.begin() , ans.end());

        return ans ;
    }
};


void Print_2D_Vector(vector<vector <int>> v)
{
    for (const auto& row : v) {
        cout<<"[ ";
        for (const auto& val : row) {
        cout << val << " ";
    }
    cout<<"]";
    cout << endl;
    }
}


int main() {
    Solution sol ;
    vector<int> nums = {1,2,3};

    vector<vector <int>> permutations = sol.permute(nums);

    Print_2D_Vector(permutations);

    return 0;
}





