
#include <iostream>
using namespace std;

bool isPresent(int arr[][4] , int target , int row , int col)
{
    for (int i = 0  ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            if (arr[i][j] == target)
                return 1 ;
        }
    }  
    return 0 ;
}

int main() {
    int arr[3][4];

    //taking input row wise
    cout<<"Enter the elements : "<<endl;
    for (int i = 0  ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            cin>>arr[i][j];
        }
    }



    //Print Array
    cout<<"Printing the array "<<endl;
    for (int i = 0 ; i < 3 ; i ++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int target ;
    cout<<"Enter the element to search = ";
    cin>>target;

    if (isPresent(arr,target,3,4))
    {
        cout<<"Element Found "<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}