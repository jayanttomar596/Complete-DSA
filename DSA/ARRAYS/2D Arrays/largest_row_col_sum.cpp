
#include <iostream>
using namespace std;


int largest_row_wise_sum(int arr[][4] , int row , int col)
{
    int maxi = INT_MIN ;
    int rowIndex = -1 ; 
    for (int i = 0 ; i < row ; i++)
    {
        int sum = 0 ;
        for (int j = 0 ; j < col ; j++)
        {
            sum+=arr[i][j];
        }

        if (sum > maxi)
        {
            maxi = sum ;
            rowIndex = i ;
        }
    }

    cout<<"The Maximum Row Sum is = "<<maxi<<endl;
    return rowIndex ;
}



int largest_col_wise_sum(int arr[][4] , int row , int col)
{
    int maxi = INT_MIN;
    int colIndex = -1 ;
    for (int i = 0 ; i < col ; i++)
    {
        int sum = 0 ;
        for (int j = 0 ; j < row ; j++)
        {
            sum+=arr[j][i];
        }
        
        if (sum > maxi)
        {
            maxi = sum ;
            colIndex = i ;
        }
    }
    cout<<"The Maximum Columns Sum is = "<<maxi<<endl;
    return colIndex ;
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

    int ansRowIndex = largest_row_wise_sum(arr,3,4);
    cout<<"Max Row is at Index = "<<ansRowIndex<<endl;    

    int ansColIndex = largest_col_wise_sum(arr,3,4);
    cout<<"Max Column is at Index = "<<ansColIndex<<endl;

    return 0;
}


