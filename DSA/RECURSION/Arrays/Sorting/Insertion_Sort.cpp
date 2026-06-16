#include <iostream>
using namespace std;


// Using Recursion

// Time Complexity: O(n2)
// Auxiliary Space: O(n)


void insert_sort_recursive(int arr[] , int n)
{

    // Base Case
    if (n <= 1)
        return  ;


    // Sort first n-1 elements
    insert_sort_recursive(arr , n -1);


    // Insert last element at its correct position 
    // is sorted array
    int last = arr[n-1];
    int j = n-2 ;


    // Move elements of arr[0...i-1] , that are greater then key , to one position ahead of their current position

    while( j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j] ;
        j--;
    }
    arr[j+1] = last ;
}




/* Using Loops

void Insert_Sort(int arr[] , int n )
{
    for (int i = 1 ; i < n ; i++)
    {
        int temp = arr[i];
        int j = i - 1 ;
        for (; j>= 0 ; j--)
        {
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break ;
            }
        }
        arr[j+1] = temp; 
    }
}
*/


void Print_Array(int arr[] , int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



int main() {
    int arr[5] = {2,5,1,4,3};
    int size = 5 ;

    cout<<"Array Before Sorting : "<<endl;
    Print_Array(arr,size);

    // Insert_Sort(arr,size);
    insert_sort_recursive(arr,size);

    cout<<"Array After Sorting : "<<endl;
    Print_Array(arr,size);

    return 0;
}





