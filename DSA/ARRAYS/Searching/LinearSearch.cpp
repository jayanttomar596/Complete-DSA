

#include <iostream>
using namespace std;

int linearSearch(int arr[],int size , int element)
{
    for (int i = 0 ; i < size ; i++)
    {
        if (arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[5] = {1,2,3,4,5},n;
    cout<<"Enter element to search : ";
    cin>>n;

    int result = linearSearch(arr,5,n) ;
    if (result != -1)
    {
        cout<<"Element found at index : "<<result<<endl;
    }
    else
    {
        cout<<"Element not found in array ."<<endl;
    }
    return 0;
}