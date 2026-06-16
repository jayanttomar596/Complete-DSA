
// Find first and last occurance of a given number in an array

#include <iostream>
using namespace std;

int firstOcc(int arr[] , int size , int key)
{
    int start = 0 , end = size -1 ;
    int mid ,ans = -1; 

    while (start <= end)
    {
        mid = start + (end - start)/2 ;

        if (arr[mid] == key)
        {
            ans = mid ; 
            end = mid - 1 ;
        }
        else if (key > arr[mid])
        {
            start = mid + 1 ;
        }
        else if (key < arr[mid])
        {
            end = mid - 1 ;
        }
    }
    return ans ; 
}

int lastOcc(int arr[] , int size , int key)
{
    int start = 0 , end = size -1 ;
    int mid ,ans = -1; 

    while (start <= end)
    {
        mid = start + (end - start)/2 ;

        if (arr[mid] == key)
        {
            ans = mid ; 
            start = mid + 1 ;
        }
        else if (key > arr[mid])
        {
            start = mid + 1 ;
        }
        else if (key < arr[mid])
        {
            end = mid - 1 ;
        }
    }
    return ans ; 
}

int main() {
    int arr[5] = {1,2,3,3,5};
    int key;
    cout<<"Enter the value of element = ";
    cin>>key ;

    if (firstOcc(arr , 5 , key) == -1)
    {
        cout<<"Element is not present in array .";
    }
    else 
    {
        cout<<"First occurance is at Index : "<<firstOcc(arr,5,key)<<endl;
        cout<<"Last occurance is at Index : "<<lastOcc(arr,5,key)<<endl;
    }
    

    return 0;
}











// SOLUTION USING LINEAR SEARCH APPROACH


// first and last occurance of a particular number in a sorted array

// #include <iostream>
// using namespace std;

// int first_occurance(int arr[] , int size , int key)
// {
//     for (int i = 0 ; i < size ; i++)
//     {
//         if (arr[i] == key)
//         {
//             return i ;
//         }
//     }
//     return -1 ;
// }

// int last_occurance(int arr[] , int size , int key)
// {
//     for (int i = size - 1 ; i >= 0 ; i--)
//     {
//         if (arr[i] == key)
//         {
//             return i ;
//         }
//     }
//     return -1 ;
// }

// int main() {
//     int arr[8] = {1,1,1,2,2,2,2,8};
//     int key;
//     cout<<"Enter the element to search occurance = ";
//     cin>>key;
//     int first_occ = first_occurance(arr , 8 , key);
//     int last_occ = last_occurance(arr , 8 , key);

//     cout<<"First Ocuurance = "<<first_occ<<endl;
//     cout<<"Last Occurance = "<<last_occ<<endl;
//     return 0;
// }