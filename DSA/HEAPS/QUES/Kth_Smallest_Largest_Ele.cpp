// Kth Smallest and Largest


/*

Given an array arr[] and an integer k where k is smaller than the size of the array, your task is to find the kth smallest element in the given array.

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.

*/




#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class Smallest {
    public:
      // arr : given array
      // k : find kth smallest element and return using this function
      int kthSmallest(vector<int> &arr, int k) {
          priority_queue<int> pq ;
          int n = arr.size() ;
          
          // Step1
          for (int i = 0 ; i < k ; i++)
          {
              pq.push(arr[i]) ;
          }
          
          // Step2 
          for (int i = k ; i < n ; i++)
          {
              if (arr[i] < pq.top())
              {
                  pq.pop() ;
                  pq.push(arr[i]) ;
              }
          }
          
          // Ans = pq.top() ;
          int ans = pq.top() ;
          return ans ;
      }
};



class Largest {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int , vector<int> , greater<int> > pq ;
              int n = nums.size() ;
              
              // Step1
              for (int i = 0 ; i < k ; i++)
              {
                  pq.push(nums[i]) ;
              }
              
              // Step2 
              for (int i = k ; i < n ; i++)
              {
                  if (nums[i] > pq.top())
                  {
                      pq.pop() ;
                      pq.push(nums[i]) ;
                  }
              }
              
              // Ans = pq.top() ;
              int ans = pq.top() ;
              return ans ;
        }
};




int main() {

    vector<int> arr = {7 , 10 , 4 , 3 , 20 , 15} ;

    cout << "\nArray : " ;
    for (int i = 0 ; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    int k ;
    cout << "Enter the value of k to find Kth Smallest Element = ";
    cin >> k ;

    Smallest sol1 ;
    cout << k <<"th Smallest Element in Array = " << sol1.kthSmallest(arr,k) << endl;


    Largest sol2 ;
    cout << k <<"th Smallest Element in Array = " << sol2.findKthLargest(arr,k) << endl;
    
    return 0;
}

