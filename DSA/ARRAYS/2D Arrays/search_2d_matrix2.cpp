/*
Search a 2D Matrix II

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
*/



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size() ;
        int col = matrix[0].size();

        int rowIndex = 0 ;
        int colIndex = col - 1 ;

        while (rowIndex < row && colIndex >= 0)
        {
            int element = matrix[rowIndex][colIndex];

            if (element == target)
            {
                cout<<"RowIndex : "<<rowIndex<<endl;
                cout<<"ColumnIndex : "<<colIndex<<endl;
                return 1 ;
            }

            if (element < target)
            {
                rowIndex++;
            }
            else
            {
                colIndex-- ;
            }
        }
        return 0 ;
    }
};


void Print_2D_Vector(vector<vector<int> > v)
{
    int rows = v.size();
    int cols = v[0].size();

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
    Solution sol ;

    //if you want to change rows and cols , you can below aur add input for both variables
    int row = 5 ;
    int col = 5 ;

    vector<vector<int> > matrix(row , vector<int>(col));
    cout<<"Enter the elements : "<<endl;
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            cin>>matrix[i][j];
        }
    }

    Print_2D_Vector(matrix);

    int target ;
    cout<<"Enter the target variable to search for : ";
    cin>>target ;

    if (sol.searchMatrix(matrix,target))
    {
        cout<<"The Target Element is present in matrix"<<endl;
    }
    else
    {
        cout<<"The Target Element is not present in matrix"<<endl;
    }
    return 0;
}


