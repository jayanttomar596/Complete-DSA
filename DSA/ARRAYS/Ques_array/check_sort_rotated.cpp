// Given an array nums, return true if the array was originally sorted in non-decreasing order , then rotated some number of positions (including zero). Otherwise return false .

#include <iostream>
using namespace std;

bool check_sort_rotated(int arr[] , int size)
{
    int count = 0 ;
    
    for (int i = 1 ; i < size ; i++)
    {
        if (arr[i-1] > arr[i])
        {
            count++;
        }
    }
    if (arr[size-1] > arr[0])
        count++;

    return count<=1 ;    
}

int main() {
    int arr[5]={3,4,5,1,2};

    cout<<"Its a Sorted and Rotated Array : "<<check_sort_rotated(arr,5)<<endl;
    return 0;
}