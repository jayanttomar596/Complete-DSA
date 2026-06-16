#include <iostream>
using namespace std;

void print(int arr[] , int size , int start = 0)
// Start optional agruement hai , daala toh thik nahi toh by default 0 - dena hai toh dede nahi toh apne paas hai hi
// IMP - Rightmost arguement se start karna hai

{
    for (int i = start ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {
    
    int arr[5] = {1,2,7,8,9};
    int size = 5 ;

    print(arr,size);
    cout<<endl;
    print(arr,size,2);

    return 0;
}