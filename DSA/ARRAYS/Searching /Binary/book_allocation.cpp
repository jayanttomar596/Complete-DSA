
// BOOK ALLOCATION

/*
- arr of int and arr[i] represents the no of pages in the 'ith' book 
- each student get atleast one book and each book should allocated to student in contiguous manner to m students such that max no of pages assigned to each student is minimum 
*/


#include <iostream>
using namespace std;

bool isPossible(int arr[] , int n , int m , int mid)
{
    int studentCount = 1 ;
    int pageSum = 0 ;

    for (int i=0 ; i < n ; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i] ; 
        }
        else{
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false ;
            }
            pageSum = 0;
            pageSum +=arr[i];
        }
    }
    return true ;
}

int allocate_books(int arr[] , int n , int m)
{
    int start = 0 ;
    int sum = 0;

    for (int i = 0 ; i < n ; i++)
    {
        sum+=arr[i];
    }
    int end = sum ;
    int ans = -1 ;
    int mid = start + (end - start)/2 ;

    while (start<=end)
    {
        mid = start + (end - start)/2 ;
        if (isPossible(arr,n,m,mid))
        {
            ans = mid ;
            end = mid - 1 ;
        }
        else
        {
            start = mid + 1 ;
        }
    }
    return ans ;
}


int main() {
    int arr[4] = {10,20,30,40};
    int m ; 
    cout<<"Enter no of students [m] = ";
    cin >> m;

    // if m > n i.e if no of students is greater than size of array than ALLOCATION NOT POSSIBLE 

    cout<<"Minimum of max pages allocated to each student = "<<allocate_books(arr,4,m)<<endl;
    
    return 0;
}




