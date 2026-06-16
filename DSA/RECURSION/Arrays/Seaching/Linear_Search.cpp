#include <iostream>
using namespace std;


void print(int arr[] , int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool linear_Search(int arr[] , int size , int k)
{
    print(arr,size);
    // Base Case
    if (size == 0)
        return false ;

    if (arr[0] == k)
    {
        return true ;
    }
    else
    {
        bool remaining_Part = linear_Search(arr+1 , size - 1 , k);
        return remaining_Part ;
    }    

}


int main() {

    int arr[5] = {3,5,1,2,6};
    int size = 5 ;
    int key = 1 ;

    bool ans = linear_Search(arr , size , key);

    if (ans)
    {
        cout<<key<<" is Present in the array "<<endl;
    }
    else
    {
        cout<<key<<" is Absent in the Array "<<endl;
    }

    return 0;
}





