
// Mountain array is like its elements first increase then decreases 

#include <iostream>
using namespace std;

int peakIndex(int arr[] , int size)
{
    int start = 0 , end = size - 1 ;
    int mid ;

    while (start < end)
    {
        mid = start + (end - start)/2;
        if (arr[mid] < arr[mid+1])
        {
            start = mid + 1 ;
        }
        else{
            end = mid ;
        }
    }
    return start;
}

int main() {
    int arr[8] = {1,4,10,7,4,3,2,1};

    cout<<"Index of Peak Element in Mountain Array : "<<peakIndex(arr,8)<<endl;
    return 0;
}