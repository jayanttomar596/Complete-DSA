// First Negative in Every Window of size K

/*

Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.



Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window {-8, 2}: First negative integer is -8.
Window {2, 3}: No negative integers, output is 0.
Window {3, -6}: First negative integer is -6.
Window {-6, 10}: First negative integer is -6.





Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0] 
Explanation:
Window {12, -1, -7}: First negative integer is -1.
Window {-1, -7, 8}: First negative integer is -1.
Window {-7, 8, -15}: First negative integer is -7.
Window {8, -15, 30}: First negative integer is -15.
Window {-15, 30, 16}: First negative integer is -15.
Window {30, 16, 28}: No negative integers, output is 0.

*/




#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
    deque<int> dq ;
    vector<int> ans ;
    int N = arr.size() ;
    
    // Process first window of k size
    for (int i = 0 ; i < k ; i++)
    {
        if(arr[i] < 0)
        {
            dq.push_back(i) ;
        }
    }
    
    // Store answer of first k sized window
    if(dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]) ;
    }
    else
    {
        ans.push_back(0) ;
    }
    
    // Process the remainiong windows
    for (int i = k ; i < N ; i++)
    {
        // Removal
        if(!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front() ;
        }
        
        // Addition
        if(arr[i] < 0)
        {
            dq.push_back(i) ;
        }
        
        // Ans Store
        if(dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0) ;
        }
        
    }
    
    return ans ;
}


void Print_Vector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}




int main() {

    int k ;
    vector<int> arr = {-8,2,3,-6,10} ;

    cout << "Original Array : "<<endl;
    Print_Vector(arr);

    cout << "\nEnter the size of window [Value of K] = ";
    cin>>k ;
    
    vector <int> ans = FirstNegativeInteger(arr,k) ;

    cout<<"\nFirst Negative Integer for window "<<k<<" : " << endl;
    Print_Vector(ans) ;
    cout << endl;
    
    return 0;
}





