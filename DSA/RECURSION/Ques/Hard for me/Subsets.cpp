/* SUBSETS

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/


#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    void solve(vector<int> nums , vector<int> output , int index , vector<vector <int>> &ans)  
    {
        // Base Case
        if (index >= nums.size())
        {
            ans.push_back(output);
            return ;
        }

        // Exclude
        solve(nums , output , index+1 , ans);

        // include
        int element = nums[index];
        output.push_back(element);
        solve(nums , output , index+1 , ans);

    }  

public:
    vector<vector <int>> subsets(vector<int>& nums) {
        
        vector<vector <int>> ans ;
        vector<int > output ; 
        int index = 0 ;
        solve(nums , output , index , ans);
        return ans ;
    }
};


void Print_2D_Vector(vector<vector <int>> v)
{
    for (const auto& row : v)
    {
        cout<<"{ ";
        for (const auto& elem : row)
        {
            cout << elem << " ";
        }
        cout<<"}";
        cout<<endl;
    }
} 



int main() {
    
    Solution sol ;

    vector<int> v = {1,2,3};

    vector<vector <int>> Power_Set = sol.subsets(v);

    Print_2D_Vector(Power_Set);

    return 0;
}




