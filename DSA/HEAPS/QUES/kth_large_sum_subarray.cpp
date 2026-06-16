//  K-th Largest Sum Subarray



/*

Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.

*/




#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;




// Approach - 1
// T.C. -> O(N^2 LogN)
// S.C. -> O(N^2)
int getKthLargest(vector<int> &arr , int k)
{
    vector<int> sumStore ;
    int n = arr.size() ;

    for (int i = 0 ; i < n ; i++)
    {
        int sum = 0 ;

        for (int j = i ; j < n ; j++)
        {
            sum += arr[j] ;
            sumStore.push_back(sum) ;
        }
    }

    sort(sumStore.begin() , sumStore.end()) ;

    return sumStore[sumStore.size()-k] ;
}





// Approach - 2
// T.C. -> O(N^2 LogK)
// S.C. -> O(K)
int GetKthLargest(vector<int> &arr , int k)
{
    priority_queue<int , vector<int> , greater<int> > mini ;

    int n = arr.size() ;
    for (int i = 0 ; i < n ; i++)
    {
        int sum = 0 ;
        for (int j = i ; j < n ; j++)
        {
            sum += arr[j] ;
            if (mini.size() < k)
            {
                mini.push(sum) ;
            }
            else
            {
                if (sum > mini.top())
                {
                    mini.pop() ;
                    mini.push(sum) ;
                }
            }
        }
    }

    return mini.top() ;
}





int main() {

    vector<int> v = {1, -2, 3, -4, 5} ;

    cout << "\nVector : ";
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;


    int k ; 
    cout << "\nEnter the value of k = ";
    cin >> k ;


    cout << k << "th Largest Sum SubArray = " << getKthLargest(v , k) << endl ;
    // for k = 2 , Output should be 4


    cout << k << "th Largest Sum SubArray = " << GetKthLargest(v , k) << endl ;
    // for k = 2 , Output should be 4
    

    return 0;
}

