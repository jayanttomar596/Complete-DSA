#include <iostream>
using namespace std;

void sortArray(int *arr , int n)
{

    // base case - already sorted
    if (n == 0 || n == 1)
    {
        return ;
    }

    // 1 case solve karlia - largest element ko end me rakh dega
    for (int i = 0 ; i < n-1 ; i++)
    {
        if (arr[i] > arr[i+1])
        {
            swap(arr[i] , arr[i+1]);
        }
    }

    // Recursive Call
    sortArray(arr,n-1);

}

void Print_Array(int arr[] , int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {
    
    int arr[5] = {2,5,1,6,9};
    int size = 5 ;

    cout<<"Array before Sorting : "<<endl;
    Print_Array(arr,size);

    sortArray(arr,size);

    cout<<"Array after Sorting : "<<endl;
    Print_Array(arr,size);

    
    return 0;
}




