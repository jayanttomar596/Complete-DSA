
// BUBBLE SORT

// ith Round - ith largest element on right place

#include <iostream>
using namespace std;

void printArray(int A[] , int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[] , int size)
{
    for (int i = 1 ; i < size ; i++)
    {
        //for round 1 to n-1

        bool swapped = false ;
        for (int j = 0 ; j < size-i ; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true ;
            }
        }
        if (swapped == false)
        {
            break ;
        }
            
    }

}


int main() {
    int A[] = {12,54,65,7,23,9};
    int n = 6 ;

    printArray(A,n); 
    bubbleSort(A,n);
    printArray(A,n);

    return 0;
}



//  i = 0 ---->  < n - 1
//         ||
//  j = 0 ---->  < n - i - 1     