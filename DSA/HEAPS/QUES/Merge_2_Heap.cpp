// Merge two binary Max heaps



/*

Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

*/






#include <iostream>
#include <vector>
using namespace std;



// T.C. -> O(M+N)
// S.C. -> O(M+N)

class Solution{
    void heapify(vector<int> &arr , int n , int i)
{

    int largest = i ;
    int left = 2*i + 1 ;
    int right = 2*i + 2 ;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left ;
    }

    if (right < n && arr[largest] < arr[right])
    {
        largest = right ;
    }


    if (largest != i)
    {
        swap(arr[largest] , arr[i]) ;
        heapify(arr , n , largest) ;
    }
}

    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Step1 : Merge both arrays into one
        
        vector<int> ans ;
        
        for (auto i : a)
            ans.push_back(i) ;
        
        for (auto i : b)
            ans.push_back(i) ;
            
        
        // Step2 : Build heap using merged array
        int size = ans.size() ;
        for (int i = size/2 -1 ; i >= 0 ; i--)
        {
            heapify(ans , size , i);
        }
        
        return ans ;
    }
};



void Print_Vector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    } 
    cout << endl;
}




int main() {

    vector<int> a = {10 , 5 , 6 , 2} ;
    vector<int> b = {12 , 7 , 9} ;
    
    int n = a.size() ;
    int m = b.size() ;

    cout << "\nHeap1 = ";
    Print_Vector(a) ;
    cout << "\nHeap2 = ";
    Print_Vector(b) ;

    Solution sol;
    vector<int> v = sol.mergeHeaps(a , b , n , m) ;

    cout << "\nMerged Heap" << endl;
    Print_Vector(v);
    cout << endl;
     
    return 0;
}


