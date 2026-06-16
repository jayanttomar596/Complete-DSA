// Minimum Cost of ropes



/*

Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 



Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29

Explanation: We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. Cost of this operation 2 + 3 = 5. 
2) Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9 + 6 =15. Total cost is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we get two rope of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.

*/






#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
    public:
      long long minCost(vector<int>& arr) {
          
          // Create a min Heap
          priority_queue<long long , vector<long long> , greater<long long> > pq ;
          long long n = arr.size() ;
          
          for (int i = 0 ; i < n ; i++)
          {
              pq.push(arr[i]);
          }
          
          long long cost = 0 ;
          
          while(pq.size() > 1)
          {
              long long a = pq.top() ;
              pq.pop() ;
              
              long long b = pq.top() ;
              pq.pop() ;
              
              long long sum = a + b ;
              cost += sum ;
              
              pq.push(sum) ;
          }
          
          return cost ;
      }
};



int main() {

    vector<int> v = {4, 3, 2, 6} ;
    cout << "\nArray : ";
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;


    Solution sol ;

    cout << "\nMin Cost of Ropes for the above Arrays = " << sol.minCost(v) << endl;

    
    return 0;
}