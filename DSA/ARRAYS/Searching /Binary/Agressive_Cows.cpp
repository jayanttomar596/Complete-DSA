
// AGRESSIVE COWS

/*
Given an array of length 'N' , where each element denotes the position of a stall . Now you have 'N' stalls and an integer 'K' which denotes the number of cows that are aggressive . To prevent the cows from hurting each other , you need to assign the cows to the stalls , such that the minimum distance between any two of them is as large as possible . Return the largest minimum distance . 
*/


// I have not used vector therefore enter sorted array , If not use vector instead of array and sort it using - sort(v.begin() , v.end())

#include <iostream>
using namespace std;

int isPossible(int arr[] , int size , int k , int mid)
{
    int cowCount = 1 ;
    int lastPos = arr[0] ;

    for (int i = 0 ; i < size ; i++)
    {
        if (arr[i] - lastPos >= mid)
        {
            cowCount++ ;
            if (cowCount == k)
            {
                return true;
            } 
            lastPos = arr[i];
        }
    }
    return false ;
}

int aggressiveCows(int arr[] , int size ,int k)
{
    int s = 0 ; 

    int maxi = -1 ;
    for (int i = 0 ; i < size ; i++)
    {
        maxi = max(maxi , arr[i]);
    }
    int e = maxi ;
    int ans = - 1;
    int mid = s + (e-s)/2 ;

    while(s<=e)
    {
        if (isPossible(arr ,size, k , mid))
        {
            ans = mid ;
            s = mid + 1 ;
        }
        else{
            e = mid - 1 ;
        }
        mid = s + (e-s)/2 ;
    }
    return ans ;
}


int main() {
    int arr[5] = {1,2,3,4,6};
    int k ;
    cout<<"Enter the number of cows : ";
    cin>>k;

    cout<<"Maximum distance of the minimum distance between each cow is = "<<aggressiveCows(arr,5,k)<<endl;

    return 0;
}



