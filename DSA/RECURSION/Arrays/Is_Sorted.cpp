// To check whether a array is sorted or not 

#include <iostream>
using namespace std;


bool isSorted(int arr[] , int size)
{
    // Base Case
    if (size == 0 || size == 1)
            return true ;

    if (arr[0] > arr[1])
            return false ;  
    else
    {
        bool remainingPart = isSorted(arr+1 , size - 1); 
        return remainingPart ;
    }
                  
}


int main() {
    
    int arr[5] = {2,4,6,8,9};
    int size = 5 ;

    bool ans = isSorted(arr,size);

    if (ans)
    {
        cout<<"\nArray is Sorted\n"<<endl;   
    }
    else
    {
        cout<<"\nArray is not Sorted\n"<<endl;
    }

    return 0;
}