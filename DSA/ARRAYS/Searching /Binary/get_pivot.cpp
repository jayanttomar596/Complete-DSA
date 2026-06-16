
//PIVOT POINT OF ROTATED ARRAR 

// #include <iostream>
// using namespace std;

// int getPivot(int arr[] , int size)
// {
//     int start = 0 ; 
//     int end = size - 1 ;
//     int mid = start + (end - start)/2 ;

//     while(start < end)
//     {
//         mid = start + (end- start)/2 ;
//         if (arr[mid] >= arr[0])
//         {
//             start = mid + 1 ;
//         }
//         else{
//             end = mid ;
//         }
//     }
//     return start ;
// }

// int main() {
//     int arr[5] = {8,10,17,1,3};

//     cout<<"Pivot is at Index : "<<getPivot(arr,5)<<" with value = "<<getPivot(arr,5)<<endl;
//     return 0;
// }    









// Searching in ROTATED ARRAY

#include <iostream>
using namespace std;

int getPivot(int arr[] , int size)
{
    int start = 0 ; 
    int end = size - 1 ;
    int mid = start + (end - start)/2 ;

    while(start < end)
    {
        mid = start + (end- start)/2 ;
        if (arr[mid] >= arr[0])
        {
            start = mid + 1 ;
        }
        else{
            end = mid ;
        }
    }
    return start ;
}

int BinarySearch(int arr[] , int s , int e , int key)
{
    int start = s , end = e;
    int mid;
    while (start <= end)
    {
        
        mid = start + (end-start)/2;
        if (arr[mid] == key)
        {
            return mid ;
        }
        else if (arr[mid]>key)
        {
            end = mid - 1 ;
        }
        else if (arr[mid]<key)
        {
            start = mid+1;
        }   
    }
    return -1 ;
}

int find_position(int arr[] , int size , int key)
{
    int pivot = getPivot(arr,size);

    if (key >= arr[pivot] && key <= arr[size-1])
    {
        return BinarySearch(arr,pivot,size-1,key);
    }
    else{
        return BinarySearch(arr,0,pivot-1,key);
    }
}

int main() {
    int arr[5] = {8,10,17,1,3};
    int key;
    cout<<"Enter the value of key to search for : ";
    cin>>key;

    cout<<"The Key Element is present at index = "<<find_position(arr,5,key)<<endl;
    return 0;
}  



