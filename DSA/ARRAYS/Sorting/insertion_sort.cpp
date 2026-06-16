
// INSERTION SORT

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

void InsertSort(int arr[] , int size)
{
    for (int i = 1 ; i < size ; i++)
    {
        int temp = arr[i] ;
        int j = i - 1;
        for ( ; j >= 0 ; j--)
        {
            if (arr[j] > temp)
            {
                //shift
                arr[j+1] = arr[j];
            }
            else{
                break ;
            }
        }
        arr[j+1] = temp ;
    }
}


// // Using WHILE LOOP 

// void InsertSort(int arr[] , int size)
// {
//     for (int i = 1 ; i < size ; i++)
//     {
//         int temp = arr[i] , j = i-1 ;
//         while(j>=0)
//         {
//             if (arr[j]>temp)
//             {
//                 arr[j+1] = arr[j];
//             }
//             else{
//                 break;
//             }
//             j--;
//         }
//         arr[j+1] = temp ;
//     }
// }

int main() {
    int arr[7] = {10,1,7,4,8,2,11};
    printArray(arr,7);
    InsertSort(arr,7);
    printArray(arr,7);
    
    return 0;
}