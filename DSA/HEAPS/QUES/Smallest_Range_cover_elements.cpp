// Smallest Range Covering Elements from K Lists



/*

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

*/





#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class node {
public:
    int data, row, col;
    node(int d, int r, int c) : data(d), row(r), col(c) {}
};




class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data; // Min heap based on data value
    }
};




class Solution {

public:

    vector<int> smallestRange(vector<vector<int>>& nums) {

        int mini = INT_MAX, maxi = INT_MIN;

        priority_queue<node*, vector<node*>, compare> minHeap;

        int k = nums.size();


        // Step1: Create a min heap for starting element of each list
        for (int i = 0; i < k; i++) {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element, i, 0)); // Allocating dynamically
        }


        int start = mini, end = maxi;


        // Process ranges
        while (!minHeap.empty()) {

            // Fetch the minimum element
            node* temp = minHeap.top();
            minHeap.pop();

            mini = temp->data;

            // Update the range
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // Next element exists
            if (temp->col + 1 < nums[temp->row].size()) {
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                minHeap.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            } else {
                break; // Next element does NOT exist
            }

            // Free memory of processed node
            delete temp;
        }

        return {start, end};
    }
};





int main() {


    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};

    Solution sol;

    vector<int> result = sol.smallestRange(nums);

    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}




