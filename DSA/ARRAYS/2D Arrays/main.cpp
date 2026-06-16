
#include <iostream>
using namespace std;


// we have to specify size of 2nd dimension ie column
void Input_2d_row_wise(int arr[][4] , int row , int col)
{
    //taking input -> row wise input
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            cin>>arr[i][j];
        }
    }    
}



void Input_2d_col_wise(int arr[][4] , int row , int col)
{
    //taking input -> column wise input
    for (int i = 0 ; i < col ; i++)
    {
        for (int j = 0 ; j < row ; j++)
        {
            cin>>arr[i][j];
        }
    }    
}


void Print_2d_Array(int arr[][4] , int row , int col)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}


int main() {
    
    //create 2D Array
    int arr[3][4]; // -> 3 : rows and 4 : columns

    int arr2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    int arr3[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};


    //taking input -> row wise input
    // cout<<"Enter each element row wise : "<<endl;
    // for (int row = 0 ; row < 3 ; row++)
    // {
    //     for (int col = 0 ; col < 4 ; col++)
    //     {
    //         cin>>arr[row][col];
    //     }
    // }

    
    // taking input -> column wise
    cout<<"Enter each element column wise : "<<endl;
    for (int col = 0 ; col < 4 ; col++)
    {
        for (int row = 0 ; row < 3 ; row++)
        {
            cin>>arr[row][col];
        }
    }

    

    //Print
    cout<<endl<<"Printing the 2D Array : "<<endl;
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}




