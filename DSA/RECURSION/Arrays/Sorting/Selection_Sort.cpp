#include <iostream>
using namespace std;



// Using Recursion

// Time Complexity: O(n2)
// Auxiliary Space: O(n)


// Return minimum index
int minIndex(int a[] , int i , int j)
{
    if (i == j) 
        return i ;

    // Find minimum of remaining elements
    int k = minIndex(a , i+1 , j);

    // Return minimum of current and remaining
    return (a[i] < a[k]) ? i : k ;
}


// Recursive selection sort , n is size of a[] and index 
// index is index of starting element
void selection_sort_recursion(int arr[] , int n , int index = 0 )
{
    // Return when starting and size are same
    if (index == n)
        return ;

    // Calling minimum index function for minimum index
    int k = minIndex(arr , index , n-1);

    // Swapping when index and minimum index are not same 
    if (k != index)
        swap(arr[k] , arr[index]);

    // Recursively calling selection sort function
    selection_sort_recursion(arr , n , index+1) ;

}


/* Using Iteration
void selection_sort(int arr[] , int size)
{
    for (int i = 0 ; i < size - 1 ; i++)
    {
        int minIndex = i ;
        for (int j = i + 1 ; j < size ; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j ;
            }
        }
        swap(arr[i] , arr[minIndex]);
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

    selection_sort_recursion(arr,size);

    cout<<"Array After Sorting : "<<endl;
    Print_Array(arr,size);
    return 0;
}





