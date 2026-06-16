
//BINARY SEARCH 


#include <iostream>
using namespace std;

int BinarySearch(int arr[] , int size , int key)
{
    int start = 0 , end = size - 1;
    int mid;
    while (start <= end)
    {
        // mid = (start + end)/2 ;
        // to prevent the case when start + end makeas a no greater than INT_MAX 
        
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

int main() {
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int key;
    cout<<"Enter Key element to search for = ";
    cin>>key;

    int index = BinarySearch(arr,9,key);

    if (index!=-1)
    {
        cout<<"Element found at index : "<<index<<endl;
    }
    else
    {
        cout<<"Element not found in array "<<endl;
    }
    return 0;
}













