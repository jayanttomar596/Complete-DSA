
// LEETCODE - MOVE ZEROS
// Given an integer array nums , move all 0's to the end of it while maintaining the relative order of the non zero elements .

#include <iostream>
using namespace std;


// My Solution
void move_zeros(int arr[] , int size)
{
    int k = 0 , count = 0 ;
    for (int i = 0 ; i < size ; i++)
    {
        if (arr[i] != 0 )
        {
            arr[k++] = arr[i];
            count++;
        }
    }
    for (int j = 0 ; j < size - count ; j++)
    {
        arr[k++] = 0 ;
    }
}

//Love Babbar Solution
void movezeros(int arr[] , int size)
{
    int nonZero = 0 ;

    for (int j = 0 ; j < size ; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[j] , arr[nonZero]);
            nonZero++;
        }
    }
}

void PrintArray(int arr[] , int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[5] = {1,3,0,0,12};

    PrintArray(arr,5);
    move_zeros(arr,5);
    PrintArray(arr,5);

    return 0;
}


