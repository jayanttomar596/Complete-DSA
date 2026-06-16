// N meetings in one room





/*

You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

*/








#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;








// Time Complexity: O(n log n)

// Space Complexity: O(n)





class Solution {
    static bool cmp(pair<int , int> a , pair<int , int> b)
    {
        return a.second < b.second ;
    }
    
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int , int>> v ;
        
        for (int i = 0 ; i < start.size() ; i++)
        {
            pair<int , int> p = make_pair(start[i] , end[i]) ;
            v.push_back(p) ;
        }
        
        sort(v.begin() , v.end() , cmp) ;
        
        int count = 1 ;
        int ansEnd = v[0].second ;
        
        for (int i = 1 ; i < start.size() ; i++)
        {
            if(v[i].first > ansEnd)
            {
                count++ ;
                ansEnd = v[i].second ;
            }
        }
        
        return count ;
        
    }
};









int main() {

    Solution obj;

    // Example input:
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end =   {2, 4, 6, 7, 9, 9};

    int result = obj.maxMeetings(start, end);
    cout << "Maximum number of non-overlapping meetings: " << result << endl;
    
    return 0;
}



