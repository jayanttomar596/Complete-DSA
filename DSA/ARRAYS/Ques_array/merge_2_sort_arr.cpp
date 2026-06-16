// merge 2 sorted arrays into one sorted array

#include <iostream>
using namespace std;

void merge (int arr1[] , int n , int arr2[] , int m , int arr3[])
{
    int i = 0 , j = 0 ; 
    int k = 0 ; 
    while (i<n && j<m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }

    //copy first array ke elements ko
    while (i<n)
    {
        arr3[k++] = arr1[i++];
    }

    //copy kardo second array ke remaining elements ko
    while (j<m)
    {
        arr3[k++] = arr2[j++];
    }
}

void PrintArray(int arr[],int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    
    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};

    int arr3[8] = {0};

    cout<<"Array No 1"<<endl;
    PrintArray(arr1,5);

    cout<<"Array No 2"<<endl;
    PrintArray(arr2,3);
    cout<<endl;


    merge(arr1 , 5 , arr2 , 3 , arr3);

    cout<<"After Merging two sorted arrays into one :"<<endl;

    PrintArray(arr3,8);


    return 0;
}










// LEETCODE QUES - MERGE SORTED ARRAY 


// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     int i = m - 1;     // Last valid element in nums1
//     int j = n - 1;     // Last element in nums2
//     int k = m + n - 1; // Last position in nums1

//     while (i >= 0 && j >= 0) {
//         if (nums1[i] > nums2[j]) {
//             nums1[k--] = nums1[i--];
//         } else {
//             nums1[k--] = nums2[j--];
//         }
//     }

//     // Copy remaining elements from nums2 (if any)
//     while (j >= 0) {
//         nums1[k--] = nums2[j--];
//     }
// }
