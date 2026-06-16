// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// Time Complexity : O(log(m*n))



#include <iostream>
#include <vector>
using namespace std;



bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0 ;
    int end = row*col - 1 ;

    int mid = start + (end-start)/2 ;

    while(start <= end)
    {

        int element = matrix[mid/col][mid%col];

        if (element == target)
        {
            cout<<"RowIndex : "<<mid/col<<endl;
            cout<<"ColumnIndex : "<<mid%col<<endl;
            return 1 ;
        }

        if (element < target)
        {
            start = mid + 1 ;
        }
        else
        {
            end = mid - 1 ;
        }
            mid = start + (end - start)/2 ;
    }
    return 0 ;
}


void Print_2D_Array(vector<vector<int> > v)
{
    int rows = v.size();
    int cols = v[0].size();
    cout<<"The 2D Vector is :\n";
    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < cols ; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main() {

    int rows = 3 , cols = 4 ;
    vector<vector<int> > matrix(rows , vector<int>(cols));

    cout<<"Enter the elements : "<<endl;
    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < cols ; j++)
        {
            cin>>matrix[i][j];
        }
    }    

    Print_2D_Array(matrix);
    int target ;
    cout<<"Enter the element to search for : ";
    cin>>target ;

    if (searchMatrix(matrix,target))
    {
        cout<<"Element is present in Matrix"<<endl;
    }
    else
    {
        cout<<"Element is not present in the Matrix "<<endl;
    }

    return 0;
}