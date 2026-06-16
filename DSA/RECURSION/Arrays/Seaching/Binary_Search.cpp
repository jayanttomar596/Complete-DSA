// Only for Sorted Array

#include <iostream>
using namespace std;



// MY APPROACH : 
void print_arr(int arr[] , int size)
{
    for (int i= 0 ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool Binary_Search(int arr[] , int size , int k)
{
    print_arr(arr,size);
    int mid = (size-1)/2 ;

    if (size == 0)
    {
        return false ;
    }

    if (arr[mid] == k)
    {
        return true ;
    }
    else if (arr[mid] > k)
    {
        bool remainingPart = Binary_Search(arr,mid,k);
        return remainingPart ;
    }
    else
    {
        bool remainingPart = Binary_Search(arr+mid+1 , size-mid-1 , k);
        return remainingPart ;
    }
}





// LOVE BABBAR APPROACH : 
void print(int arr[] , int s , int e)
{
    for (int i = s ; i <=e ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool binarysearch(int arr[] , int s , int e , int k)
{
    cout<<endl;
    print(arr,s,e);


    // Base Case

    // Element not found
    if (s>e) {
        return false;
    }

    int mid = s + (e-s)/2 ;
    cout<<"Value of arr Mid is "<<arr[mid]<<endl;

    // Element Found
    if (arr[mid] == k)
    {
        return true ;
    } 
    if (arr[mid] < k)
    {
        return binarysearch(arr,mid+1,e,k);
    }
    else
    {
        return binarysearch(arr,s,mid-1,k);
    }
}




int main() {

    int arr[6] = {2,4,6,10,14,16};
    // int size = sizeof(arr)/sizeof(arr[0]) ;
    int size = 6 ;
    int key ;
    cout<<"Enter the element to search for = ";
    cin>>key;


    // bool ans = Binary_Search(arr,size,key);

    bool ans = binarysearch(arr,0,size-1,key);


    if (ans)
    {
        cout<<endl<<key<<" is present in the array"<<endl;
    }
    else
    {
        cout<<endl<<key<<" is absent in the array"<<endl;
    }
    
    return 0;
}



