
#include <iostream>
using namespace std;


void print_row_wise_sum(int arr[][4] , int row , int col)
{
    cout<<"Printing Sum -> "<<endl;
    for (int i = 0 ; i < row ; i++)
    {
        int sum = 0 ;
        for (int j = 0 ; j < col ; j++)
        {
            sum+=arr[i][j];
        }
        cout<<"Sum of "<<i<<" Row Elements = "<<sum<<endl;
    }
    cout<<endl;
}



void print_col_wise_sum(int arr[][4] , int row , int col)
{
    cout<<"Printing Sum -> "<<endl;
    for (int i = 0 ; i < col ; i++)
    {
        int sum = 0 ;
        for (int j = 0 ; j < row ; j++)
        {
            sum+=arr[j][i];
        }
        cout<<"Sum of "<<i<<" Column Elements = "<<sum<<endl;
    }
    cout<<endl;
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


    print_row_wise_sum(arr,3,4);

    print_col_wise_sum(arr,3,4);

    return 0;
}


