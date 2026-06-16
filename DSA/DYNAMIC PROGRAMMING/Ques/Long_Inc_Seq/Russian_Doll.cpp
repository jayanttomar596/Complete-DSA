// Russian Doll Envelopes




/*

You are given a list of envelopes. Each envelope is represented by a pair of integers [width, height].

You can place one envelope inside another (like Russian Dolls) only if both:

The width of the inner envelope is strictly less than the outer envelope.

The height of the inner envelope is strictly less than the outer envelope.

📌 You cannot rotate the envelopes — width always refers to width, and height to height.

*/







#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




// | Step          | Time Complexity | Space Complexity|
// | ------------- | --------------- | ----------------|
// | Sorting       | O(n log n)      | O(1) (in-place) |
// | LIS on height | O(n log n)      | O(n)            |
// | **Total**     | O(n log n)      | O(n)            |



class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort by width ascending, height descending
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1]; // Descending height if same width
            return a[0] < b[0];     // Ascending width
        });

        // Step 2: Extract heights
        vector<int> heights;
        for (auto& env : envelopes) {
            heights.push_back(env[1]);
        }

        // Step 3: Apply LIS on heights
        vector<int> dp;
        for (int h : heights) {
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) {
                dp.push_back(h); // Extend the sequence
            } else {
                *it = h; // Replace to maintain smallest possible end value
            }
        }

        return dp.size(); // Length of LIS = max envelopes you can Russian doll
    }
};




int main()
{
    Solution s;
    vector<vector<int>> env = {{5,4},{6,4},{6,7},{2,3}};
    int result = s.maxEnvelopes(env);  // result will be 3
    cout << "Result = " << result << endl; 

    return 0 ;
}