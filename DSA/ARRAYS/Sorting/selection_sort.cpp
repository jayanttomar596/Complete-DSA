
// SELECTION SORT

/*
Input Array (There will be total n-1 passes , 5-1=4 in this case)
 00 01 02 03 04
|03 05 02 13 12

After first pass
    00  01 02 03 04
    02 |05 03 13 12

After second pass
    00 01  02 03 04
    02 03 |05 13 12

After third pass
    00 01 02  03 04
    02 03 05 |13 12

After fourth pass
    00 01 02 03  04
    03 05 02 12 |13
*/


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

void selectionSort(int arr[] , int size)
{
    for (int i = 0  ; i < size-1 ; i++)
    {
        int minIndex = i ;

        for (int j = i+1 ; j < size ; j++)
        {

            if (arr[j] < arr[minIndex])
                minIndex = j ;

        }
        swap(arr[minIndex] , arr[i]);
    }
}

int main() {

    int A[] = {3,5,2,13,12};
    int n=5;
    printArray(A,n);
    selectionSort(A,n);
    printArray(A,n);
        
    return 0;
}

